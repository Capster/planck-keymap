IGNORE_MOD_TAP_INTERRUPT = yes
# TAPPING_TERM =

CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = no
MOUSEKEY_ENABLE = yes        # Mouse keys(+4700)
STENO_ENABLE = yes          # Additional protocols for Stenography(+1700), requires VIRTSER
#AUDIO_ENABLE = no           # Audio output on port C6
MIDI_ENABLE = no            # MIDI controls
EXTRAFLAGS+=-flto

SRC += features/achordion.c
