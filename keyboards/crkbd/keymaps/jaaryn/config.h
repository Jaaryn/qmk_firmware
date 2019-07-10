#pragma once

#define EE_HANDS

#undef USE_I2C
#undef SSD1306OLED

#ifdef OLED_DISABLE_TIMEOUT
#   undef OLED_DISABLE_TIMEOUT
#endif

#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
#   undef RGBLED_NUM
#   undef RGBLIGHT_ANIMATIONS
#   define RGBLIGHT_SPLIT
#   define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#   define RGBLIGHT_EFFECT_STATIC_GRADIENT
#   define RGBLED_NUM 27
#   define RGBLIGHT_HUE_STEP 8
#   define RGBLIGHT_SAT_STEP 8
#   define RGBLIGHT_VAL_STEP 8
#   define RGBLIGHT_LIMIT_VAL 100
#endif

#define OLED_FONT_H "keyboards/crkbd/keymaps/jaaryn/glcdfont.c"