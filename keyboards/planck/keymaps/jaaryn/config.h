#pragma once

#ifdef AUDIO_ENABLE
#   define STARTUP_SONG SONG(PLANCK_SOUND)
#   define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND)}
#endif // AUDIO_ENABLE

#define MIDI_BASIC
