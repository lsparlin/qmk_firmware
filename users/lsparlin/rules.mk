SRC += lsparlin.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif

ifeq ($(strip $(MACROS_ENABLE)), yes)
    SRC += macros.c
    OPT_DEFS += -DMACROS_ENABLE
    ifeq ($(strip $(EMOJI_MACROS_ENABLE)), yes)
        OPT_DEFS += -DEMOJI_MACROS_ENABLE
    endif

endif // MACROS_ENABLE
