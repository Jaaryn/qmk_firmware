#include QMK_KEYBOARD_H
#include "jaaryn.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_5x4( \
        UNDO,    REDO,    KC_BSPC, KC_PSLS, \
        KC_7,    KC_8,    KC_9,    KC_PAST, \
        KC_4,    KC_5,    KC_6,    KC_PMNS, \
        KC_1,    KC_2,    KC_3,    KC_PPLS, \
        FUNC,    KC_0,    KC_DOT,  KC_PENT  \
    ),

    [_FUNC] = LAYOUT_ortho_5x4( \
        VRSN,    PING,    KC_DEL,  _______,\
        CUT,     COPY,    PASTE,   _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______, \
        _______, _______, _______, _______  \
    ),

};