// /*
// Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>
// Modified by Ryan Skidmore <rskeys@ryanskidmore.co.uk> (@ryanskidmore)
// to support the rskeys100.

// Copyright 2025
// Modified by BFB Workshop to support the Midi88.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// */

/* This matrix merges separate functions of Ryan Skidmore's rskeys100 into a single function
   in attempt to avoid the unexpected nature of the wait_us() function. */

#include "matrix.h"
//#include <stdbool.h>
#include "gpio.h"
#include "wait.h"

//#include "print.h"

static const uint16_t shift_register_values[16] = COL_SR_COLS; // 2 bytes, 1 non-zero bit per number

void matrix_init_custom(void) {
    setPinInputLow(ROW_0);
    setPinInputLow(ROW_1);
    setPinInputLow(ROW_2);
    setPinInputLow(ROW_3);
    setPinInputLow(ROW_4);
    setPinInputLow(ROW_5);
    setPinInputLow(ROW_6);
	setPinInputLow(ROW_7);
    
    setPinOutput(COL_SR_SER);   // DATA
    setPinOutput(COL_SR_RCLK);  // LATCH
    setPinOutput(COL_SR_SRCLK); // CLOCK
}

// This function performs a single scan of the whole matrix (7 rows by 24 columns)
bool matrix_scan_custom(matrix_row_t saved_matrix[]) {
    bool state_changed = false;

    // Going column by column
    for (uint8_t column_index = 0; column_index < MATRIX_COLS; column_index++) {

        // lock the output, changing the internal registers only
        writePinLow(COL_SR_RCLK);

        // put 3 x 8 bits into the shift registers
        uint16_t shift_register_value = shift_register_values[column_index];
        
        for (uint16_t i = 0; i < 16; ++i) {
            
            // write the leftmost bit  //   |   |   |   |   |   |
            if (shift_register_value & 0b1000000000000000) {
                writePinHigh(COL_SR_SER);
            } else {
                writePinLow(COL_SR_SER);
            }

            // shift the registers using the rising edge signal of the clock
            writePinHigh(COL_SR_SRCLK);
            writePinLow(COL_SR_SRCLK);

            // make the next bit the leftmost
            shift_register_value = shift_register_value << 1;
        }

        // unlock the output, moving the value of the internal registers out
        writePinHigh(COL_SR_RCLK);

        // wait for the output to take place
        wait_us(11);

        // check if the selected column has triggered any of the 8 rows of the matrix
        uint8_t scanned_row_values = (readPin(ROW_7) << 7)    // 1000 0000
								   | (readPin(ROW_6) << 6)    // 0100 0000
                                   | (readPin(ROW_5) << 5)    // 0010 0000
                                   | (readPin(ROW_4) << 4)    // 0001 0000
                                   | (readPin(ROW_3) << 3)    // 0000 1000
                                   | (readPin(ROW_2) << 2)    // 0000 0100
                                   | (readPin(ROW_1) << 1)    // 0000 0010
                                   | (readPin(ROW_0)     );   // 0000 0001

        // Check row by row each key in the current column of the saved matrix. 
        // If a value of the selected row differs from its value in the matrix, the new state should be saved.
        // When changes occur, the "state_changed" value is set to true;
        
        for (uint8_t row_index = 0; row_index < MATRIX_ROWS; ++row_index) {
            // get value of saved_matrix[column_index][row_index]
            bool saved_bit   = saved_matrix[row_index] & (matrix_row_t)1 << column_index;
            // get value of scanned row
            bool scanned_bit = scanned_row_values      & 1 << row_index;
            
            if (saved_bit != scanned_bit) {
                // use XOR logical operator '^' to flip a single bit in the given row
                saved_matrix[row_index] ^=  ((matrix_row_t)1 << column_index);
                //indicate the change
                state_changed = true;
            }
        }
    }

    return state_changed;
}



