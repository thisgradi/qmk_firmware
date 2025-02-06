/*
Copyright 2025 BFB Workshop

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// matrix related =====================================================================

#define MATRIX_ROWS 8
#define MATRIX_COLS 16

// NOTE: There are, in fact, 13 columns, but shift registers have 16 pins in total.

#define ROW_0 GP10
#define ROW_1 GP3
#define ROW_2 GP6
#define ROW_3 GP5
#define ROW_4 GP0
#define ROW_5 GP4
#define ROW_6 GP2
#define ROW_7 GP1

// NOTE: SRCLK = CLOCK, RCLK = LATCH/REFRESH

#define COL_SR_SER		GP8
#define COL_SR_RCLK		GP12
#define COL_SR_SRCLK	GP9

// NOTE: Following is a hexadecimal representation of singular
//		 bit masks.
//		 
//		 Each two digits after 'x' represent eight outputs of
//       a single shift register. 
//
//		 Each digit represents 4 bits:
//		 1 hex = 0001, 2 hex = 0010, 4 hex = 0100, 8 hex = 1000
//
//		 0x0001 = 00000000 00000001	// 1st SR
//       0x0010 = 00000000 00010000	//
//		 ...
//		 0x8000 = 10000000 00000000 // 2nd SR

#define COL_SR_COLS { 0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080, \
					  0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000}

#define DIODE_DIRECTION COL2ROW

// bootmagic ==========================================================================

#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 0

// MIDI ===============================================================================

#define MIDI_ADVANCED