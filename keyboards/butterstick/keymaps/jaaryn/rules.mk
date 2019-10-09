# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

MOUSEKEY_ENABLE 	= yes		# Mouse keys(+4700)
EXTRAKEY_ENABLE 	= yes       # Audio control and System control(+450)
CONSOLE_ENABLE 		= no        # Console for debug(+400)
COMMAND_ENABLE 		= no		# Commands for debug and configuration
NKRO_ENABLE 		= yes       # USB Nkey Rollover
STENO_ENABLE		= yes 		# Needed for chording

OPT_DEFS += -DONLYQWERTY -DDEBUG_MATRIX
SRC += sten.c
EXTRAFLAGS += -flto