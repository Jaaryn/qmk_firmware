# Build Options

BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = no # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
CONSOLE_ENABLE   = no  # Console for debug(+400)
COMMAND_ENABLE   = no # Commands for debug and configuration
CUSTOM_MATRIX    = yes # Custom matrix file for the ErgoDox EZ
NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
UNICODE_ENABLE   = no # Unicode
SWAP_HANDS_ENABLE= no # Allow swapping hands of keyboard
SLEEP_LED_ENABLE = no
API_SYSEX_ENABLE = no
RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no # enable later
DEBOUNCE_TYPE = eager_pr


LAYOUTS = ergodox
