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

#define CT_A  LCTL_T(KC_A)
#define SF_Z  LSFT_T(KC_Z)
#define AL_X  LALT_T(KC_X)
#define CT_C  LCTL_T(KC_C)
#define CM_V  LGUI_T(KC_V)

#define CM_M RGUI_T(KC_M)
#define CT_CM RCTL_T(KC_COMM)
#define AL_DT RALT_T(KC_DOT)
#define SF_SS RSFT_T(KC_SLSH)

#define RA_SP LT(RAISE, KC_SPC)
#define LW_ESC LT(LOWER, KC_ESC)
#define NUM_F LT(NUMPAD, KC_F)
#define MSE_TAB LT(MOUSE, KC_TAB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung39(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
    KC_LCTL,  CT_A,     KC_S,     KC_D,    NUM_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,   KC_ENT,  KC_QUOT,
    KC_LSFT,  SF_Z,     AL_X,     CT_C,     CM_V,      KC_B,               KC_N,     CM_M,    CT_CM,    AL_DT,    SF_SS,  RSFT_T(KC_ENT),
                                                     LW_ESC,     KC_SPC,   RA_SP
  ),
  
  [_LOWER] = LAYOUT_reviung39(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_COLN,  KC_TILD,
    _______,  KC_LSFT,  KC_LALT,  KC_LCTL,  KC_LGUI,    KC_EQL,            KC_QUOT,  KC_DQUO,  KC_PGDN,  KC_PGUP,  KC_BSPC,  RSFT_T(KC_SPC),
                                                       _______,  KC_ENT,   _______
  ),
  
  [_RAISE] = LAYOUT_reviung39(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            XXXXXXX,  XXXXXXX,  KC_GRV,   KC_TILD,  KC_SCLN,  _______,
    _______,  KC_LSFT,  KC_LALT,  KC_LCTL,  KC_LGUI,   KC_TAB,             KC_TAB,   KC_RGUI,  KC_RCTL,  KC_RALT,  KC_DEL,   _______,
                                                       _______,  KC_BSPC,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung39(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                       _______,  XXXXXXX,  _______
  ),

  [_NUMPAD] = LAYOUT_reviung39(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,        KC_PEQL, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,        KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,        KC_PDOT, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, XXXXXXX,
                                                      _______,  XXXXXXX,  KC_KP_0
  ),

  [_MOUSE] = LAYOUT_reviung39(
    _______,  XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,  KC_BTN2,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                      _______,  XXXXXXX,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
