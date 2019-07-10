#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "jaaryn.h"


/*
  [_TEMPLATE] = LAYOUT_ergodox_pretty(
     _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,\
     _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,\
     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,\
     _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,\
     _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______,\
                                                  _______, _______,         _______, _______,                                                      \
                                                           _______,         _______,                                                               \
                                         _______, _______, _______,         _______, _______, _______                                              \
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_ergodox_pretty(
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5, _______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,\
      KC_TAB, KC_SLSH, KC_COMM,  KC_DOT,    KC_P,   KC_Y, WIN_CLS,     WIN_NEW,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,\
     KC_RCTL,    KC_A,    KC_O,    KC_E,    KC_U,   KC_I,                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_ENT,\
     KC_LSPO, KC_SCLN,    KC_Q,    KC_J,    KC_K,   KC_X, WIN_LFT,     WIN_RHT,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, KC_RSPC,\
      KC_ESC, _______, _______, KC_RGUI, KC_LALT,                                        _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,\
                                                 _______, _______,     _______, KC_CAPS,                                             \
                                                          _______,     _______,                                                      \
                                          KC_SPC,  LOWER, _______,     _______,   RAISE, _______                                     \
  ),

  [_QWERTY] = LAYOUT_ergodox_pretty(
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,   KC_5, _______,     _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,\
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, _______,     _______,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
     KC_RCTL,    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,\
     KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, _______,     _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,\
      KC_ESC, _______, _______, KC_RGUI, KC_LALT,                                        _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,\
                                                 _______, _______,     _______, KC_CAPS,                                             \
                                                          _______,     _______,                                                      \
                                          KC_SPC,  LOWER, _______,     _______,   RAISE, _______                                     \
  ),

  [_RAISE] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MINS, KC_UNDS,  KC_EQL, KC_PLUS, _______,\
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,\
                                                 _______, _______,     _______, _______,                                             \
                                                          _______,     _______,                                                      \
                                        _______, _______, _______,     _______, _______, _______                                     \
  ),
  
  [_LOWER] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, KC_TILD, KC_PIPE,  KC_DQT, KC_QUOT, _______, _______,     _______, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,\
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_BSLS, _______,\
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,\
                                                 _______, _______,     _______, _______,                                             \
                                                          _______,     _______,                                                      \
                                        _______, _______, _______,     _______, _______, _______                                     \
  ), 

/*   [_NAV] = LAYOUT_ergodox_pretty(
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,     _______, KC_PGUP, KC_HOME,   KC_UP,  KC_END,  KC_DEL, _______,\
    _______, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_INS, _______,\
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,\
                                                 _______, _______,     _______, _______,                                             \
                                                          _______,     _______,                                                      \
                                        _______, _______, _______,     _______, _______, _______                                     \
  ), */

  [_ADJUST] = LAYOUT_ergodox_pretty(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,\
    _______,   RESET,   DEBUG, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, RGB_TOG, RGB_MOD, _______, _______, _______,                       _______,  QWERTY, _______,  DVORAK, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,\
                                                 _______, _______,     _______, _______,                                             \
                                                          _______,     _______,                                                      \
                                        _______, _______, _______,     _______, _______, _______                                     \
  )
};


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_keymap(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_keymap(uint32_t state) {
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