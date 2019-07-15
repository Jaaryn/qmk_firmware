#pragma once

#undef PERMISSIVE_HOLD

#define FORCE_NKRO
#define TAP_CODE_DELAY 5
#define NO_ACTION_ONESHOT
#define IGNORE_MOD_TAP_INTERRUPT

#ifndef QMK_KEYS_PER_SCAN
#   define QMK_KEYS_PER_SCAN 4
#endif // QMK_KEYS_PER_SCAN

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#   undef LOCKING_SUPPORT_ENABLE
#endif // LOCKING_SUPPORT_ENABLE

#ifdef LOCKING_RESYNC_ENABLE
#   undef LOCKING_RESYNC_ENABLE
#endif // LOCKING_RESYNC_ENABLE

#ifdef TAPPING_TERM
#   undef TAPPING_TERM
#endif // TAPPING_TERM

#if defined(KEYBOARD_ergodox_ez)
#   define TAPPING_TERM 185
#elif defined(KEYBOARD_crkbd)
#   define TAPPING_TERM 200
#else
#   define TAPPING_TERM 175
#endif
