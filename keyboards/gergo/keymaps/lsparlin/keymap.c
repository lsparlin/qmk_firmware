#include QMK_KEYBOARD_H
#include "lsparlin.h" // tap_dances, and custom modifiers

#define IGNORE_MOD_TAP_INTERRUPT

enum layers {
  _BASE = 0,
  _SYMB,
  _MOTN,
  _NUMB
};

//
// KEYMAP ARRAY
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |NUMB/ESC|   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  - _   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |TD_CTRL |   A  |   S  |  D   |   F  |   G  | RMB  |           |      |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |Sft/Caps|   Z  |   X  |   C  |   V  |   B  | LMB  |           |      |   N  |   M  | ,  < | . >  | /  ? |RShift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    | TD_ALT   |   | TD_GUI|                                 | Tab  |   |BKSP |
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | NUMB  |                      | PgDn  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | MOTN  |                      | MOTN  | SYMB |
 *                                 | Space| Escape|                      | Ent   |Space |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */

[_BASE] = LAYOUT_gergo(
         ESC_NUMB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                               KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
       TD(TD_CTL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_BTN2,                               KC_NO, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
    OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BTN1, LT(_NUMB, KC_BTN3),  KC_PGDN, RESET, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), 
                                  TD(TD_ALT), TD(TD_GUI), SPC_SYMB, ESC_MOTN,  ENTR_MOTN, SPC_SYMB, TAB_RCTL, KC_BSPC 
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |      |  &   |      |      |  =   |   _    |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  *   |  %   |   "    |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  <   |  >   |  \   |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | DEL |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */

[_SYMB] = LAYOUT_gergo(
 KC_TILD, KC_EXLM, KC_AT,  TD(TD_CBR), KC_RCBR, KC_PIPE,                                             KC_TRNS, KC_AMPR, KC_TRNS, KC_TRNS, KC_EQL,  KC_UNDS,
  KC_TRNS, KC_HASH, KC_DLR, TD(TD_PRN), KC_RPRN, KC_GRV, KC_TRNS,                           KC_PGUP, KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_DQUO,
 KC_TRNS, KC_PERC, KC_CIRC,TD(TD_BRC), KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,         KC_PGUP, KC_TRNS, KC_AMPR, KC_EQL, KC_LT, KC_GT, KC_BSLS, KC_TRNS,
                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL
    ),

/* Keymap 2: Motion/Function layer *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        | BR_DN| BR_UP|      |      |      |                         |      | PGDN | PGUP |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  | F2   | F3   | F4   | F5   | F6   |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F7  | F8   | F9   | F10  | F11  | F12  |           |      | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */

[_MOTN] = LAYOUT_gergo(
 KC_TRNS, KC_BRMD,	KC_BRMU, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                            KC_PGUP, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_VOLD, KC_VOLU, 
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,           KC_PGUP, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MUTE, KC_TRNS, 
                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 3: Numpad layer *
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |  /   |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  *   |  4   |  5   |  6   |  +   | CTRL   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  ,   |  1   |  2   |  3   | ENTR |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |  0   |   |  .  |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */

[_NUMB] = LAYOUT_gergo(
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_PSLS, KC_7, KC_8, KC_9, KC_PMNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PPLS, KC_RCTL,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_COMM, KC_1, KC_2, KC_3, KC_PENT, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_0, KC_DOT
    )
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[_LAYER] = LAYOUT_gergo(
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    biton32(layer_state);
};
