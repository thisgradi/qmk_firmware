#include QMK_KEYBOARD_H
#include "quantum.h"

// LAYER related stuff ====================================

enum layers {
  L_MAIN  = 0
  //L_TEST  = 0
};

// LAYOUT related stuff ===================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * [TEMPLATE]
  *
  *    ┌─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐     ┌─────┬─────┐     ┌─────┬─────┬─────┐
  *    │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
  * ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬─────┐
  * │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
  * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
  *
  */

//   [0] = LAYOUT(
// //    |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |    11   |    12   |
//         MI_     ,           MI_     , MI_     ,           MI_     , MI_     , MI_     ,           MI_     , MI_     ,           MI_     ,
//         MI_     , MI_     ,           MI_     , MI_     ,           MI_     , MI_     , MI_     ,           MI_     , MI_     , 
//         MI_     , MI_     , MI_     ,           MI_     , MI_     ,           MI_     , MI_     , MI_     ,           MI_     , MI_     ,
//                   MI_     , MI_     , MI_     ,           MI_     , MI_     ,           MI_     , MI_     , MI_     ,
//         MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     ,
//         MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     ,
//         MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     ,
//         MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     , MI_     
//    )

  // 13 COLUMNS, 8 ROWS
  
// 88-key piano layout

  [L_MAIN] = LAYOUT(
//     |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |    11   |    12   |
         MI_AsN1 ,           MI_Cs   , MI_Ds   ,           MI_Fs   , MI_Gs   , MI_As   ,           MI_Cs1  , MI_Ds1  ,           MI_Fs1  ,
         MI_Gs1  , MI_As1  ,           MI_Cs2  , MI_Ds2  ,           MI_Fs2  , MI_Gs2  , MI_As2  ,           MI_Cs3  , MI_Ds3  , 
         MI_Fs3  , MI_Gs3  , MI_As3  ,           MI_Cs4  , MI_Ds4  ,           MI_Fs4  , MI_Gs4  , MI_As4  ,           MI_Cs5  , MI_Ds5  ,
                   MI_Fs5  , MI_Gs5  , MI_As5  ,           MI_Cs6  , MI_Ds6  ,           MI_Fs6  , MI_Gs6  , MI_As6  ,
         MI_AN1  , MI_BN1  , MI_C    , MI_D    , MI_E    , MI_F    , MI_G    , MI_A    , MI_B    , MI_C1   , MI_D1   , MI_E1   , MI_F1   ,
         MI_G1   , MI_A1   , MI_B1   , MI_C2   , MI_D2   , MI_E2   , MI_F2   , MI_G2   , MI_A2   , MI_B2   , MI_C3   , MI_D3   , MI_E3   ,
         MI_F3   , MI_G3   , MI_A3   , MI_B3   , MI_C4   , MI_D4   , MI_E4   , MI_F4   , MI_G4   , MI_A4   , MI_B4   , MI_C5   , MI_D5   ,
         MI_E5   , MI_F5   , MI_G5   , MI_A5   , MI_B5   , MI_C6   , MI_D6   , MI_E6   , MI_F6   , MI_G6   , MI_A6   , MI_B6   , MI_C7    
    )
//   [L_TEST] = LAYOUT(
// //    |    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |   10    |    11   |    12   |
//         KC_M    ,           KC_I    , KC_J    ,           KC_K    , KC_L    , KC_M    ,           KC_I    , KC_J    ,           KC_K    ,
//         KC_L    , KC_M    ,           KC_I    , KC_J    ,           KC_K    , KC_L    , KC_M    ,           KC_I    , KC_J    , 
//         KC_K    , KC_L    , KC_M    ,           KC_I    , KC_J    ,           KC_K    , KC_L    , KC_M    ,           KC_I    , KC_J    ,
//                   KC_K    , KC_L    , KC_M    ,           KC_I    , KC_J    ,           KC_K    , KC_L    , KC_M    ,
//         KC_A    , KC_B    , KC_C    , KC_D    , KC_E    , KC_F    , KC_G    , KC_A    , KC_B    , KC_C    , KC_D    , KC_E    , KC_F    ,
//         KC_G    , KC_A    , KC_B    , KC_C    , KC_D    , KC_E    , KC_F    , KC_G    , KC_A    , KC_B    , KC_C    , KC_D    , KC_E    ,
//         KC_F    , KC_G    , KC_A    , KC_B    , KC_C    , KC_D    , KC_E    , KC_F    , KC_G    , KC_A    , KC_B    , KC_C    , KC_D    ,
//         KC_E    , KC_F    , KC_G    , KC_A    , KC_B    , KC_C    , KC_D    , KC_E    , KC_F    , KC_G    , KC_A    , KC_B    , KC_C    
//    )
};

void keyboard_post_init_kb(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=false;
}