/* Copyright 2019 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _MOUSE
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define MOUSE MO(_MOUSE)

// from original layout
#define FN1_SPC     LT(1, KC_SPC)
#define FN2_BSPC    LT(2, KC_BSPC)
#define FN3_C       LT(3, KC_C)
#define FN4_V       LT(4, KC_V)
#define FN5_B       LT(5, KC_B)
#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define ALT_N       ALGR_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_ENT     RSFT_T(KC_ENT)

#define CT_A  LCTL_T(KC_A)
#define SF_Z  LSFT_T(KC_Z)
#define AL_X  LALT_T(KC_X)
#define CT_C  LCTL_T(KC_C)
#define CM_V  LGUI_T(KC_V)

#define CM_M RGUI_T(KC_M)
#define CT_B RCTL_T(KC_B)
#define AL_SP RALT_T(KC_SPC)
#define SF_SS RSFT_T(KC_SLSH)

#define RA_N LT(RAISE, KC_N)
#define LW_ESC LT(LOWER, KC_ESC)
#define NUM_F LT(NUMPAD, KC_F)
#define MSE_TAB LT(MOUSE, KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_reviung30(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
    CT_A,    KC_S,    KC_D,   NUM_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_ENT,
    SF_Z,   ALT_X,    CT_C,    CM_V,  LW_ESC,    RA_N,    CM_M,    CT_B,    AL_SP,   SF_SS,
    RGB_TOG
  ),

  [_LOWER] = LAYOUT_reviung30(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COLN,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_EQL,        KC_QUOT, KC_DQUO, KC_COMM, KC_DOT, KC_BSPC,
    _______
  ),
  
  [_RAISE] = LAYOUT_reviung30(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,       XXXXXXX, XXXXXXX, KC_GRV,  KC_TILD, KC_SCLN,
    KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_TAB,        KC_TAB,  KC_RGUI, KC_LT,   KC_GT,   KC_DEL,
    _______
  ),
  
  [_ADJUST] = LAYOUT_reviung30(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        XXXXXXX, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU,
    KC_F11,  KC_F12,  KC_CAPS, XXXXXXX, XXXXXXX,       RESET,   XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX,
    _______
  ),

  [_NUMPAD] = LAYOUT_reviung30(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_PEQL, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_PDOT, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS,
    _______
  ),

  [_MOUSE] = LAYOUT_reviung30(
    XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//
// PER KEY TAPPING FORCE_HOLD
//
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case (RA_N):
      return true;
    case (LW_ESC):
      return true;
    default:
      return false;
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (layer_state_is(_BASE)) {
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    } else if (layer_state_is(_LOWER)) {
      if (clockwise) {
        rgblight_increase_hue();
      } else {
        rgblight_decrease_hue();
      }
    }
  }
}
