
#pragma once
#include "quantum.h"
#include "version.h"
#ifdef TAP_DANCE_ENABLE
#  include "tap_dances.h"
#endif // TAP_DANCE_ENABLE
#ifdef MACROS_ENABLE
#  include "macros.h"
#endif

//
// LSPARLIN CUSTOM MODIFIERS
//
#define ESC_NUMB LT(_NUMB, KC_ESC)
#define SPC_SYMB LT(_SYMB, KC_SPC)
#define ESC_MOTN LT(_MOTN, KC_ESC)
#define ENTR_MOTN LT(_MOTN, KC_ENT)
#define TAB_RCTL MT(MOD_RCTL, KC_TAB)

// 
// EMOJI KEYCODES
//
#define UC_FROWN SS_LALT("D83D+DE41")
#define UC_SMILE SS_LALT("D83D+DE42")
#define UC_GRINNING SS_LALT("D83D+DE00")
#define UC_THUMBUP SS_LALT("D83D+DC4D")
