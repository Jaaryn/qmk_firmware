#include QMK_KEYBOARD_H
#include "jaaryn.h"
#include "bootloader.h"

#ifdef PROTOCOL_LUFA
#   include "lufa.h"
#   include "split_util.h"
#endif // PROTOCOL_LUFA

#ifdef OLED_DRIVER_ENABLE
#   undef  OLED_TIMEOUT
#   define OLED_TIMEOUT 60000
    uint16_t oled_timer;
#endif // OLED_DRIVER_ENABLE


extern uint8_t is_master;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
                                        KC_LALT, LOWER,    KC_SPC,    FUNC,    RAISE,   KC_LGUI \
  ),

  [_COLEMAK] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,\
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,\
                                        KC_LALT, LOWER,    KC_SPC,    FUNC,    RAISE,   KC_LGUI \
  ),

  [_DVORAK] = LAYOUT( \
    KC_TAB,  KC_SLSH, KC_COMM, KC_DOT,  KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,\
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,\
                                        KC_LALT, LOWER,    KC_SPC,    FUNC,    RAISE,   KC_LGUI \
  ),

  [_PLOVER] = LAYOUT( \
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,                         KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,   \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,\
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
                                        KC_XPLV, KC_C,    KC_V,       KC_N,    KC_M,    KC_XPLV \
  ),

  [_LOWER] = LAYOUT( \
    KC_ESC,  KC_TILD, KC_PIPE, KC_DQT,  KC_QUOT, _______,                      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_DEL, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, KC_BSLS, _______,\
                                        _______, _______, _______,    _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                      _______, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_DEL, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,\
    _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
                                        _______, _______, _______,    _______, _______, _______ \
  ),

  [_FUNC] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_CCCV,                      PING,    _______, KC_UP,   _______, _______, _______,\
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_CLCK,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,\
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NLCK,                      _______, WIN_LFT, WIN_CLS, WIN_NEW, WIN_RHT, _______,\
                                        _______, _______, _______,    _______, _______, _______ \
  ),

  [_ADJUST] = LAYOUT( \
    RESET,   _______, _______, _______, _______, VRSN,                         VRSN,    _______, _______, _______, _______, EEP_RST,\
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, VLK_TOG, _______,                      _______, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,\
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,                      MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, _______,\
                                        _______, _______, _______,    _______, _______, _______ \
  )
};

#ifdef OLED_DRIVER_ENABLE
// Set Rotation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_master) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

void set_keylog(uint16_t keycode, keyrecord_t *record);
void render_status(void);
void render_logo(void);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
        oled_timer = timer_read();
    }
    return true; 
};

void oled_task_user(void) {
    if (is_master && timer_elapsed(oled_timer) > OLED_TIMEOUT) {
        oled_off();
        return;
    }
    if (is_master) {
        render_status();
    } else {
        render_logo();
        oled_scroll_left();
    }
}

#endif // OLED_DRIVER_ENABLE
