

ROW0            GP10|       [USBC]       |GP11
ROW4            GP0 |                    |  5V
ROW7            GP1 |                    | GND
                GND |   o__BOOT          | RST
                GND |                    | 3V3
ROW6            GP2 |                    |GP29
ROW1            GP3 |         GP18__o o  |GP28
ROW5            GP4 |         GP24____|  |GP27
ROW3            GP5 |                    |GP26
ROW2            GP6 |      *RP2040*      |GP22
                GP7 |     (top view)     |GP20
COLS_SER        GP8 | o GP25             |GP23
COLS_SRCLK      GP9 | o   o   o   o   o  |GP21
                      |   |   |   |   |
COLS_RCLK       GP12__|   |   |   |   |___GP16
                GP13______|   |   |_______GP15
                GP14__________|

                *LED is GP18

                            MATRIX:
    BLACKS:      ROW0      ROW1      ROW2      ROW3
    WHITES:    ROW4      ROW5      ROW6      ROW7

    ROW0:   0   2 3   5 6 7   9 A   C
    ROW1:   0 1   3 4   6 7 8   A B
    ROW2:   0 1 2   4 5   7 8 9   B C
    ROW3:     1 2 3   5 6   8 9 A
    ROW4:   0 1 2 3 4 5 6 7 8 9 A B C
    ROW5:   0 1 2 3 4 5 6 7 8 9 A B C
    ROW6:   0 1 2 3 4 5 6 7 8 9 A B C
    ROW7:   0 1 2 3 4 5 6 7 8 9 A B C


                        Matrix (COL2ROW)
                               
                           diodes
            COL0 -  Button0 ->|---|
                                  |
                                ROW0
            




                        MATRIX ("MREG" - matrix register)

COL1    Output1    1 |        KEY       |16  VCC                        5V
COL2    Output2    2 |                  |15  Output0                    COL0
COL3    Output3    3 |    SN74HC595N    |14  INPUT          (SER)       COLS_SER
COL4    Output4    4 |      (SIPO)      |13  Disable output (OE inv)    GND
COL5    Output5    5 |    SHIFT REG     |12  Refresh output (RCLK)      COLS_RCLK
COL6    Output6    6 |     Top view     |11  Clock          (SRCLK)     COLS_SRCLK
COL7    Output7    7 |                  |10  Retain info    (SRCLR inv) 5V
GND         GND    8 |      MREG0       |9   Daisychain out (QH')       MREG1_SER

COL9    Output1    1 |        KEY       |16  VCC                        5V
COL10   Output2    2 |                  |15  Output0                    COL8
COL11   Output3    3 |    SN74HC595N    |14  INPUT          (SER)       MREG1_SER
COL12   Output4    4 |      (SIPO)      |13  Disable output (OE inv)    GND
        Output5    5 |    SHIFT REG     |12  Refresh output (RCLK)      COLS_RCLK
        Output6    6 |     Top view     |11  Clock          (SRCLK)     COLS_SRCLK
        Output7    7 |                  |10  Retain info    (SRCLR inv) 5V
GND         GND    8 |      MREG1       |9   Daisychain out (QH')
