#pragma once

/* #ifdef AUDIO_ENABLE
#   define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                    SONG(COLEMAK_SOUND), \
                                    SONG(DVORAK_SOUND), \
                                    SONG(OVERWATCH_THEME) \
                                }

#endif // !AUDIO_ENABLE */

#ifndef QMK_KEYS_PER_SCAN
#   define QMK_KEYS_PER_SCAN 4
#endif // !QMK_KEYS_PER_SCAN

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD


#define FORCE_NKRO

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#   undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#   undef LOCKING_RESYNC_ENABLE
#endif