/*
Copyright 2019 Brandon Coffey <coffeyb@outlook.com> u/Jaaryn

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
#include "quantum.h"
#include "version.h"

#if defined(KEYMAP_SAFE_RANGE)
#   define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#   define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _PLOVER,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNC,
    _NAV
};

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,   // Prints QMK Firmware and board info
    QWERTY,         // Sets default layer to QWERTY
    COLEMAK,        // Sets default layer to COLEMAK
    DVORAK,         // Sets default layer to DVORAK
    PLOVER,         // Sets default layer to PLOVER
    LOWER,
    RAISE,
    FUNC,
    NAV,
    KC_XPLV,        // Exits PLOVER
    KC_CCCV,        // Hold to copy, tap to paste 
    PING,
    RGB_SLD,
    NEW_SAFE_RANGE  //use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// Define short macros
#define UNDO    LCTL(KC_Z)
#define REDO    LCTL(KC_Y)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)
#define WIN_LFT RCTL(RGUI(KC_LEFT))
#define WIN_RHT RCTL(RGUI(KC_RGHT))
#define WIN_CLS RCTL(RGUI(KC_F4))
#define WIN_NEW RCTL(RGUI(KC_D))
#define KC_CAD   LCA(KC_DEL)
#define KC_ALTB  LALT(KC_TAB)
#define KC_CTLES CTL_T(KC_ESC)

#define MG_NKRO MAGIC_TOGGLE_NKRO

// Rename mouse keys with 7 letters
#ifdef MOUSEKEY_ENABLE
#define MO_S_N  KC_MS_WH_UP
#define MO_S_S  KC_MS_WH_DOWN
#define MO_S_E  KC_MS_WH_RIGHT
#define MO_S_W  KC_MS_WH_LEFT
#define MO_N    KC_MS_UP
#define MO_S    KC_MS_DOWN
#define MO_E    KC_MS_RIGHT
#define MO_W    KC_MS_LEFT
#define MO_CL_L KC_MS_BTN1
#define MO_CL_R KC_MS_BTN2
#define MO_CL_M KC_MS_BTN3
#define MO_CL_4 KC_MS_BTN4
#define MO_CL_5 KC_MS_BTN5
#define MO_AC_0 KC_MS_ACCEL0
#define MO_AC_1 KC_MS_ACCEL1
#define MO_AC_2 KC_MS_ACCEL2
#else
#define MO_S_N  KC_NO
#define MO_S_S  KC_NO
#define MO_S_E  KC_NO
#define MO_S_W  KC_NO
#define MO_N    KC_NO
#define MO_S    KC_NO
#define MO_E    KC_NO
#define MO_W    KC_NO
#define MO_CL_L KC_NO
#define MO_CL_R KC_NO
#define MO_CL_M KC_NO
#define MO_CL_1 KC_NO
#define MO_CL_2 KC_NO
#define MO_AC_0 KC_NO
#define MO_AC_1 KC_NO
#define MO_AC_2 KC_NO
#endif

