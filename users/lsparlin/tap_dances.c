#include "tap_dances.h"

void dance_curlb (qk_tap_dance_state_t *state, void *user_data) {
  if ( state->count == 1 ) {
    tap_code16(KC_LCBR);
  } else {
    SEND_STRING("{}" SS_TAP(X_LEFT));
  }
}

void dance_paren (qk_tap_dance_state_t *state, void *user_data) {
  if ( state->count == 1 ) {
    tap_code16(KC_LPRN);
  } else {
    SEND_STRING("()" SS_TAP(X_LEFT));
  }
}

void dance_squareb (qk_tap_dance_state_t *state, void *user_data) {
  if ( state->count == 1 ) {
    tap_code16(KC_LBRC);
  } else {
    SEND_STRING("[]" SS_TAP(X_LEFT));
  }
}

void dance_gui_each (qk_tap_dance_state_t *state, void *user_data) {
  if ( state->count == 1 ) {
    register_code(KC_LGUI);
  }
  else if ( state->count == 2 ) {
    register_code(KC_LSFT);
  }
  else if ( state->count == 3 ) {
    unregister_code(KC_LSFT);
    register_code(KC_LALT);
  }
}

void dance_alt_each (qk_tap_dance_state_t *state, void *user_data) {
  if ( state->count == 1 ) {
    register_code(KC_LALT);
  }
  else if (state->count == 2 ) {
    register_code(KC_LSFT);
  }
}

void dance_ctl_each (qk_tap_dance_state_t *state, void *user_data) {
  if ( state->count == 1 ) {
    register_code(KC_LCTL);
  }
  else if (state->count == 2 ) {
    register_code(KC_LSFT);
  }
  else if ( state->count == 3) {
    unregister_code(KC_LSFT);
    register_code(KC_LALT);
  }
}

void dance_mod_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LGUI);
  unregister_code(KC_LSFT);
  unregister_code(KC_LALT);
  unregister_code(KC_LCTL);
}

// QMK tap dance fn override
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GUI] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_gui_each, NULL, dance_mod_reset, TD_MOD_TIMEOUT),
  [TD_ALT] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_alt_each, NULL, dance_mod_reset, TD_MOD_TIMEOUT),
  [TD_CTL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_ctl_each, NULL, dance_mod_reset, TD_MOD_TIMEOUT),
  [TD_CBR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_curlb, NULL, TD_PAREN_TIMEOUT),
  [TD_PRN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_paren, NULL, TD_PAREN_TIMEOUT),
  [TD_BRC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_squareb, NULL, TD_PAREN_TIMEOUT)
};
