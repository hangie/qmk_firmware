/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Pablo Ramirez

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    WIN_BASE    = 0,
    WIN_FN      = 1,
    WIN_EDIT    = 2,
    WIN_GREEN   = 3,
    WIN_S_GREEN = 4,
    MAC_BASE    = 5,
    MAC_FN      = 6,
    MAC_EDIT    = 7,
    MAC_GREEN   = 8,
    MAC_S_GREEN = 9,
};
int EDIT = WIN_EDIT;
int GREEN = WIN_GREEN;
int S_GREEN = WIN_S_GREEN;

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

#define WK_LWRD LCTL(KC_LEFT)       // Word Left (Windows)
#define WK_RWRD LCTL(KC_RIGHT)      // Word Right (Windows)
#define WK_UNDO LCTL(KC_Z)          // Ctrl-Z (Windows Undo)
#define WK_REDO LCTL(LSFT(KC_Z))    // Ctrl-Shift-Z (Windows Redo)
#define WK_CUT  LCTL(KC_X)          // Ctrl-X (Windows Cut)
#define WK_COPY LCTL(KC_C)          // Ctrl-C (Windows Copy)
#define WK_PSTE LCTL(KC_V)          // Ctrl-V (Windows Paste)
#define WK_PASTE LCTL(KC_V)         // Ctrl-V (Windows Paste)

#define MK_LWRD LALT(KC_LEFT)       // Word Left (Mac)
#define MK_RWRD LALT(KC_RIGHT)      // Word Right (Mac)
#define MK_UNDO KC_UNDO             // Ctrl-Z (Mac Undo)
#define MK_REDO LGUI(LSFT(KC_Z))    // Ctrl-Shift-Z (Mac Redo)
#define MK_CUT  LGUI(KC_X)          // Command-X (Mac Cut)
#define MK_COPY LGUI(KC_C)          // Command-C (Mac Copy)
#define MK_PSTE LGUI(KC_V)          // Command-V (Mac Paste)
#define MK_PASTE LGUI(KC_V)         // Command-V (Mac Paste)

#define MO_WSGR MO(WIN_S_GREEN)     // Shift-Green (Windows)
#define MO_MSGR MO(MAC_S_GREEN)     // Shift-Green (MacOS)

#define COMBO_PROCESS_KEY_RELEASE
#define COMBO_MUST_HOLD_PER_COMBO

enum combo_events {
  EDIT_LAYER,
  SHIFT_EDIT_LAYER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM edit_layer_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM s_edit_layer_combo[] = {KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[] = {
  [EDIT_LAYER] = COMBO_ACTION(edit_layer_combo),
  [SHIFT_EDIT_LAYER] = COMBO_ACTION(s_edit_layer_combo),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LGUI  * LALT  * SPC                                         * RALT * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [WIN_BASE] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LGUI,    KC_LALT,                                 LT(WIN_GREEN, KC_SPC),                                 KC_RALT,    MO(WIN_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             * RM_P *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [WIN_FN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

  [WIN_EDIT] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    WK_CUT,     WK_LWRD,    KC_UP,      WK_RWRD,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    KC_LSFT,    KC_D,       KC_F,       _______,    WK_COPY,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   WK_UNDO,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    WK_PASTE,   _______,    _______,    _______,    WK_REDO,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

  [WIN_GREEN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DOLLAR,  KC_PERCENT, KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      MO_WSGR,                KC_PLUS,    KC_MINUS,   KC_EQUAL,   KC_LCBR,    KC_RCBR,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_COLN,    KC_BSLS,                MO_WSGR,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LGUI,    KC_LALT,                                        KC_SPC,                                         KC_RALT,    MO(WIN_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  [WIN_S_GREEN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_EXLM,    KC_TILD,    KC_GRV,     _______,    _______,    _______,    _______,    _______,    _______,    KC_DQT,     KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                _______,    KC_UNDS,    KC_PIPE,    _______,    _______,    _______,    _______,    KC_LABK,    KC_RABK,    KC_QUES,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LGUI,    KC_LALT,                                        KC_SPC,                                         KC_RALT,    MO(WIN_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

    /*
    *****************************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  * RMOD *
    *****************************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC        * PGUP *
    *****************************************************************************************************************
    * TAB     * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \        * PGDN *
    *****************************************************************************************************************
    * CAPS      * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT           * HOME *
    *****************************************************************************************************************
    * LSFT         * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT       * UP   * END  *
    *****************************************************************************************************************
    * LCTL  * LALT  * LGUI  * SPC                                         * LGUI * FN   * RCTL * LEFT * DOWN * RGHT *
    *****************************************************************************************************************
  */
  [MAC_BASE] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSNP,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                               LT(MAC_GREEN, KC_SPC),                                   KC_RGUI,    MO(MAC_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  /*
    *****************************************************************************************************************
    *RESET * BRID * BRIU * TASK * FLXP * RVAD * RVAI * MPRV * MPLY * MNXT * MUTE * VOLD * VOLU *      *  INS * RTOG *
    *****************************************************************************************************************
    *      *      *      *      *      *      *      *      *      *      *      *      *      *             * RM_P *
    *****************************************************************************************************************
    *         *      *      *      *      *      *      *      *      *      *      *      *      *          *      *
    *****************************************************************************************************************
    *           *      *      *      *      *      *      *      *      *      *      *      *               *      *
    *****************************************************************************************************************
    *              *      *      *      *      *      *      *      *      *      *      *            * RSAI *      *
    *****************************************************************************************************************
    *       *       *       *                                             *      *      *      * RHUD * RSAD * RHUI *
    *****************************************************************************************************************
  */
  [MAC_FN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_MSSN,    KC_FIND,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_MSCR,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

  [MAC_EDIT] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      RESET,      KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RGB_VAD,    RGB_VAI,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    KC_INS,     RGB_TOG  ,
      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    _______,    _______,    _______,    _______,    MK_CUT,     MK_LWRD,    KC_UP,      MK_RWRD,    _______,    _______,    _______,    _______,                _______  ,
      _______,    _______,    KC_LSFT,    _______,    _______,    _______,    MK_COPY,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   MK_UNDO,    _______,                _______,                _______  ,
      _______,                _______,    _______,    _______,    _______,    _______,    MK_PASTE,   _______,    _______,    _______,    MK_REDO,                _______,    RGB_SAI,    _______  ,
      _______,    _______,    _______,                                        _______,                                        _______,    _______,    _______,    RGB_HUD,    RGB_SAD,    RGB_HUI
  ),

  [MAC_GREEN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSNP,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DOLLAR,  KC_PERCENT, KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_QUOT,                KC_ENT,                 KC_HOME  ,
      MO_MSGR,                KC_PLUS,    KC_MINUS,   KC_EQUAL,   KC_LCBR,    KC_RCBR,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_COLN,    KC_BSLS,                MO_MSGR,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                        KC_SPC,                                         KC_RGUI,    MO(MAC_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),

  [MAC_S_GREEN] = LAYOUT_75_ansi(
  /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14          15       */
      KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_MSNP,    KC_DEL,     RGB_MOD  ,
      KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,                KC_PGUP  ,
      KC_TAB,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_BSLS,                KC_PGDN  ,
      KC_CAPS,    KC_EXLM,    KC_TILD,    KC_GRV,     _______,    _______,    _______,    _______,    _______,    _______,    KC_DQT,     KC_QUOT,                KC_ENT,                 KC_HOME  ,
      KC_LSFT,                _______,    KC_UNDS,    KC_PIPE,    _______,    _______,    _______,    _______,    KC_LABK,    KC_RABK,    KC_QUES,                KC_RSFT,    KC_UP,      KC_END   ,
      KC_LCTL,    KC_LALT,    KC_LGUI,                                        KC_SPC,                                         KC_RGUI,    MO(MAC_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT
  ),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case EDIT_LAYER:
            if (pressed) {
                layer_on(EDIT);
                // unregister_mods(MOD_MASK_SHIFT);
            } else {
                layer_off(EDIT);
            }
            break;
        case SHIFT_EDIT_LAYER:
            if (pressed) {
                layer_on(EDIT);
                register_mods(MOD_MASK_SHIFT);
            } else {
                layer_off(EDIT);
                unregister_mods(MOD_MASK_SHIFT);
            }
            break;
    }
}

bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    switch (combo_index) {
        case SHIFT_EDIT_LAYER:
            switch(keycode) {
                case KC_S:
                    unregister_mods(MOD_MASK_SHIFT);
                    return true; // release combo
                    break;
                case KC_D:
                    unregister_mods(MOD_MASK_SHIFT);
                    layer_off(EDIT);
                    return true; // release combo
                    break;
                case KC_F:
                    unregister_mods(MOD_MASK_SHIFT);
                    layer_off(EDIT);
                    return true; // release combo
                    break;
            }
            return false; // do not release combo
        case EDIT_LAYER:
            switch(keycode) {
                case KC_S:
                    unregister_mods(MOD_MASK_SHIFT);
                    return true; // release combo
                    break;
                case KC_D:
                case KC_F:
                    unregister_mods(MOD_MASK_SHIFT);
                    layer_off(EDIT);
                    return true; // release combo
                    break;
            }
            return false; // do not release combo
    }
    return false;
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    // Same as above, decide by keycode, the combo index, or by the keys in the chord.

    switch (index) {
        case SHIFT_EDIT_LAYER:
            return true;
        case EDIT_LAYER:
            return true;

    }

    return false;
}


/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(WIN_BASE,KC_D):
            if (!record->tap.count && record->event.pressed) {
                layer_on(EDIT_D);
                // tap_code16(MO(EDIT_D)); // Intercept hold function to send Ctrl-X
                return false;
            }
            else {
                layer_off(EDIT_D);
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(WIN_BASE,KC_F):
            if (!record->tap.count && record->event.pressed) {
                layer_on(EDIT_F);
                // tap_code16(MO(EDIT_F)); // Intercept hold function to send Ctrl-C
                return false;
            }
            else {
                layer_off(EDIT_F);
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(EDIT_F,KC_D):
            if (!record->tap.count && record->event.pressed) {
                layer_off(EDIT_F);
                layer_on(EDIT);
                // tap_code16(MO(EDIT)); // Intercept hold function to send Ctrl-X
                return false;
            }
            else {
                layer_off(EDIT_F);
                layer_off(EDIT);
            }
            return true;             // Return true for normal processing of tap keycode
        case LT(EDIT_D,KC_F):
            if (!record->tap.count && record->event.pressed) {
                layer_off(EDIT_D);
                layer_on(EDIT);
                // tap_code16(MO(EDIT)); // Intercept hold function to send Ctrl-C
                return false;
            }
            else {
                layer_off(EDIT);
            }
            return true;             // Return true for normal processing of tap keycode
    }
    return true;
}
*/

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:            // OS switch
            if (active) {  // Mac/iOS mode
                EDIT = MAC_EDIT;
                GREEN = MAC_GREEN;
                S_GREEN = MAC_S_GREEN;
                layer_move(MAC_BASE);
            } else {  // Windows/Android mode
                EDIT = WIN_EDIT;
                GREEN = WIN_GREEN;
                S_GREEN = WIN_S_GREEN;
                layer_move(WIN_BASE);
            }
            break;
        case 1:  // Connection switch
            // Probably it's not possible to do anything sensible here as switching from Cable to BT requires turning off the board. (BT / OFF / Cable)
            if (active) {  // BT mode
                           // do stuff
            } else {       // Cable mode
                // do stuff
            }
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable = true;
  // debug_matrix = true;
  // debug_keyboard = true;
  // debug_mouse = true;
}
