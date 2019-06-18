#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "jaaryn.h"


#define KC_RST   RESET
#define KC_RGB   RGB_MOD
#define KC_TRGB  RGB_TOG

//**************************************
// NEED TO UNDO PREVIOUS LAYOUT WRAPPER
//**************************************


/*
  [_TEMPLATE] = LAYOUT_ergodox_pretty(
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____, _____,                       _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____,                                     _____, _____, _____, _____, _____,\
                                        _____, _____,         _____, _____,                                   \
                                               _____,         _____,                                          \
                                 _____, _____, _____,         _____, _____, _____                             \
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_ergodox_pretty(
       GRV,     1,     2,     3,     4,     5, _____,         _____,     6,     7,     8,     9,     0,   DEL,\
       TAB,  SLSH,  COMM,   DOT,     P,     Y, WIN_CLS,     WIN_NEW,     F,     G,     C,     R,     L,  BSPC,\
      RCTL,     A,     O,     E,     U,     I,                           D,     H,     T,     N,     S,   ENT,\
      LSPO,  SCLN,     Q,     J,     K,     X, WIN_LFT,     WIN_RHT,     B,     M,     W,     V,     Z,  RSPC,\
       ESC, _____, _____,  RGUI,  LALT,                                     _____,  LEFT,  DOWN,    UP,  RGHT,\
                                        _____, _____,         _____,  CAPS,                                   \
                                               _____,         _____,                                          \
                                   SPC,   NAV,  ALTB,         _____, RAISE, LOWER                             \
  ),

  [_QWERTY] = LAYOUT_ergodox_pretty(
       GRV,     1,     2,     3,     4,     5, _____,         _____,     6,     7,     8,     9,     0,   DEL,\
       TAB,     Q,     W,     E,     R,     T, _____,         _____,     Y,     U,     I,     O,     P,  BSPC,\
      RCTL,     A,     S,     D,     F,     G,                           H,     J,     K,     L,  SCLN,   ENT,\
      LSPO,     Z,     X,     C,     V,     B, _____,         _____,     N,     M,  COMM,   DOT,  SLSH,  RSPC,\
       ESC, _____, _____,  RGUI,  LALT,                                     _____,  LEFT,  DOWN,    UP,  RGHT,\
                                         PING,   CAD,         _____,  CAPS,                                   \
                                               _____,         _____,                                          \
                                   SPC,   NAV,  ALTB,         _____, RAISE, LOWER                             \
  ),

  [_LOWER] = LAYOUT_ergodox_pretty(
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____, _____, _____,         _____, _____,  MINS,  UNDS,   EQL,  PLUS, _____,\
     _____,     1,     2,     3,     4,     5,                           6,     7,     8,     9,     0, _____,\
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____,                                     _____, _____, _____, _____, _____,\
                                        _____, _____,         _____, _____,                                   \
                                               _____,         _____,                                          \
                                 _____, _____, _____,         _____, _____, _____                             \
  ),
  
  [_RAISE] = LAYOUT_ergodox_pretty(
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____,  TILD,  PIPE,   DQT,  QUOT, _____, _____,         _____, _____,  LCBR,  RCBR,  LBRC,  RBRC, _____,\
     _____,  EXLM,    AT,  HASH,   DLR,  PERC,                        CIRC,  AMPR,  ASTR,  LPRN,  RPRN, _____,\
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____,  BSLS, _____,\
     _____, _____, _____, _____, _____,                                     _____, _____, _____, _____, _____,\
                                        _____, _____,         _____, _____,                                   \
                                               _____,         _____,                                          \
                                 _____, _____, _____,         _____, _____, _____                             \
  ),

  [_ADJUST] = LAYOUT_ergodox_pretty(
    
  ),

  [_NAV] = LAYOUT_ergodox_pretty(
     _____, _____,  ACL0,  ACL1,  ACL2, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____,  WH_U,  MS_U,  WH_D, _____, _____,         _____,  PGUP,  HOME,    UP,   END,   DEL, _____,\
     _____,  BTN2,  MS_L,  MS_D,  MS_R,  BTN1,                        PGDN,  LEFT,  DOWN,  RGHT,   INS, _____,\
     _____, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____, _____, _____, _____, _____,                                     _____, _____, _____, _____, _____,\
                                        _____, _____,         _____, _____,                                   \
                                               _____,         _____,                                          \
                                 _____, _____, _____,         _____, _____, _____                             \
  ),

  [_FUNC] = LAYOUT_ergodox_pretty(
       RST, _____, _____, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____,  TRGB,   RGB, _____, _____, _____, _____,         _____, _____, _____, _____, _____, _____, _____,\
     _____,    F1,    F2,    F3,    F4,    F5,                          F6,    F7,    F8,    F9,   F10, _____,\
     _____,   F11,   F12,   F13,   F14,   F15, _____,         _____,   F16,   F17,   F18,   F19,   F20, _____,\
     _____, _____, _____, _____, _____,                                     _____, _____, _____, _____, _____,\
                                        _____, _____,         _____, _____,                                   \
                                               _____,         _____,                                          \
                                 _____, _____, _____,         _____, _____, _____                             \
  )
};


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};