
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "jaaryn.h"

#define KEYLOG_LEN (int)(32 / OLED_FONT_WIDTH)

char keylog_str[KEYLOG_LEN] = {};
char keycode_str[KEYLOG_LEN] = {};

void render_status(void) {
    oled_write_P(PSTR("Lyout"), false);
        switch (biton32(default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWRTY"), false);
                break;
            case _COLEMAK:
                oled_write_P(PSTR("COLMK"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("DVRAK"), false);
                break;
            case _PLOVER:
                oled_write_P(PSTR("PLVER"), false);
                break;
        }
    oled_write_P(PSTR("Layer"), false);
        switch (biton32(layer_state)) {
            case 0:
                oled_write_P(PSTR("Base "), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("Raise"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjst"), false);
                break;
            case _FUNC:
                oled_write_P(PSTR("Func "), false);
                break;
            case _PLOVER:
                oled_write_P(PSTR("Plver"), false);
                break;
            default:
                oled_write_P(PSTR("Undef"), false);
                break;
        }

    uint8_t modifiers = get_mods();

    oled_write_P(PSTR("Mods "), false);
    oled_write_P( (modifiers & MOD_MASK_SHIFT) ? PSTR(" SFT ") : PSTR("     "), false);
    oled_write_P( (modifiers & MOD_MASK_CTRL ) ? PSTR(" CTL ") : PSTR("     "), false);
    oled_write_P( (modifiers & MOD_MASK_ALT  ) ? PSTR(" ALT ") : PSTR("     "), false);
    oled_write_P( (modifiers & MOD_MASK_GUI  ) ? PSTR(" GUI ") : PSTR("     "), false);

    uint8_t led_usb_state = host_keyboard_leds();

    oled_write_P(PSTR("Lock "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK)    ? PSTR(" NUM ") : PSTR("     "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK)   ? PSTR(" CAPS") : PSTR("     "), false);
    oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR(" SCRL") : PSTR("     "), false);

    oled_write(keylog_str, false);
    oled_write(keycode_str, false);
}

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d\n",
            record->event.key.row, record->event.key.col);

    snprintf(keycode_str, sizeof(keycode_str), "k%2d", keycode);
}

void render_logo(void) {
  static const char PROGMEM logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(logo, false);
}
