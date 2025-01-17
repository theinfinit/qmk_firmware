/* Copyright 2015-2021 Jack Humbert
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

// #pragma message: The default behavior of mod-taps will change to mimic IGNORE_MOD_TAP_INTERRUPT in the future.
// If you wish to keep the old default behavior of mod-taps, please use HOLD_ON_OTHER_KEY_PRESS.'
//   16 | #            pragma message "The default behavior of mod-taps will change to mimic IGNORE_MOD_TAP_INTERRUPT in the future.\nIf you wish to keep the old default behavior of mod-taps, please use HOLD_ON_OTHER_KEY_PRESS."

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_steno.h"

enum planck_layers {
  _QWERTY,
  _MAC,
  _PLOVER,
  _LOWER,
  _SL,
  _iSL,
  _RAISE,
  _FKEYS,
  _FN,
  _NAV,
  _TL,
  _iNAV,
  _iTL
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  MAC,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  NEW_LINE,
  NDASH,
  MDASH,
};

#define IGNORE_MOD_TAP_INTERRUPT

// Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define NAV LT(_NAV, KC_SPC)
#define iNAV LT(_iNAV, KC_SPC)

// Mod on hold, key on tap
#define LALT_A LALT_T(KC_A)       // Hold: Left Alt    // Tap: A
#define LSFT_S LSFT_T(KC_S)       // Hold: Left Shift  // Tap: S
#define LSFT_ESC LSFT_T(KC_ESC)   // Hold: Left Shift  // Tap: Esc
#define LCTL_D LCTL_T(KC_D)       // Hold: Left Ctrl   // Tap: D
#define LGUI_F LGUI_T(KC_F)       // Hold: Left GUI    // Tap: F

#define RGUI_J RGUI_T(KC_J)       // Hold: Right GUI   // Tap: J
#define RCTL_K RCTL_T(KC_K)       // Hold: Right Ctrl  // Tap: K
#define RSFT_L RSFT_T(KC_L)       // Hold: Right Shift // Tap: L
#define RALT_SCLN RALT_T(KC_SCLN) // Hold: Right Alt   // Tap: ;

// Mod on hold, key on tap (Mac/iPad)
#define iLGUI_D LGUI_T(KC_D)       // Hold: Left GUI    // Tap: D
#define iLCTL_F LCTL_T(KC_F)       // Hold: Left Ctrl   // Tap: F
#define iRCTL_J RCTL_T(KC_J)       // Hold: Right Ctrl  // Tap: J
#define iRGUI_K RGUI_T(KC_K)       // Hold: Right GUI   // Tap: K

#define LCTL_PS LCTL_T(KC_PSCR)    // Hold: Left Ctrl   // Tap: Print Screen
#define LGUI_PS LGUI_T(KC_PSCR)    // Hold: Left Ctrl   // Tap: Print Screen

// Shortcuts
#define CUT    LCTL(KC_X)
#define YANK   LCTL(KC_C)
#define PASTE  LCTL(KC_V)
#define ALT_F4 LALT(KC_F4)

// Dashes (macOS)
#define iNDASH LALT(KC_MINS)
#define iMDASH S(LALT(KC_MINS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer (Qwerty)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │ Tab │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │  '  │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │ _TL │Alt/A│Sft/S│Ctl/D│Gui/F│  G  │   │  H  │Gui/J│Ctl/K│Sft/L│Alt/;│Enter│
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *   Tap for Esc ──┤ Sft │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ Esc │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *  Tap for PrSc ──┤ Ctl │ Gui │Enter│ Alt │Raise│Space│   │ Nav │Lower│ _SL │ Ins │ Fn  │ App │
 *                 ╰─────┴─────┴─────┴─────┴──┬──┴─────┴   ┴──┬──┴──┬──┴─────┴─────┴─────┴─────╯
 *                                            │ Tap for Space ╯     │
 *                                            ╰──────────┬──────────╯
 *                Hold both keys to activate FKEYS layer ╯
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_Y, KC_U,   KC_I,    KC_O,   KC_P,      KC_QUOT,
    MO(_TL),  LALT_A,  LSFT_S, LCTL_D,  LGUI_F, KC_G,   KC_H, RGUI_J, RCTL_K,  RSFT_L, RALT_SCLN, KC_ENT,
    LSFT_ESC, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_ESC,
    LCTL_PS,  KC_LGUI, KC_ENT, KC_LALT, RAISE,  KC_SPC, NAV,  LOWER,  MO(_SL), KC_INS, FN,        KC_APP
),

/* Base layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │ Tab │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │  '  │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │ iTL │Alt/A│Sft/S│Gui/D│Ctl/F│  G  │   │  H  │Ctl/J│Gui/K│Sft/L│Alt/;│Enter│
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *   Tap for Esc ──┤ Sft │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ Esc │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *  Tap for PrSc ──┤ Gui │ Ctl │Enter│ Alt │Raise│Space│   │iNav │Lower│_iSL │ Ins │ Fn  │ App │
 *                 ╰─────┴─────┴─────┴─────┴──┬──┴─────┴   ┴──┬──┴──┬──┴─────┴─────┴─────┴─────╯
 *                                            │ Tap for Space ╯     │
 *                                            ╰──────────┬──────────╯
 *                Hold both keys to activate FKEYS layer ╯
 */
[_MAC] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,   KC_Y,  KC_U,    KC_I,     KC_O,   KC_P,      KC_QUOT,
    MO(_iTL), LALT_A,  LSFT_S, iLGUI_D, iLCTL_F, KC_G,   KC_H,  iRCTL_J, iRGUI_K,  RSFT_L, RALT_SCLN, KC_ENT,
    LSFT_ESC, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,   KC_N,  KC_M,    KC_COMM,  KC_DOT, KC_SLSH,   KC_ESC,
    LGUI_PS,  KC_LCTL, KC_ENT, KC_LALT, RAISE,   KC_SPC, iNAV,  LOWER,   MO(_iSL), KC_INS, FN,        KC_APP
),

/* Stenography layer
 *                   ╭─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                   │ Tab │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │  #  │
 *                   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                   │  ^  │     │  T  │  P  │  H  │     ┆     │  F  │  P  │  L  │  T  │  D  │
 *                   ├─────┼╌ S ╌┼─────┼─────┼─────┼╌╌╌╌ * ╌╌╌╌┼─────┼─────┼─────┼─────┼─────┤
 *                   │     │     │  K  │  W  │  R  │     ┆     │  R  │  B  │  G  │  S  │  Z  │
 *                   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                   │Exit │     │ Alt │ Gui │  A  │  O  │  E  │  U  │ Gui │ Alt │     │     │
 *                   ╰─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_TAB,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
    KC_LCTL, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    EXT_PLV, XXXXXXX, KC_LALT, KC_LGUI, KC_C,    KC_V,    KC_N,    KC_M,    KC_RGUI, KC_RALT, XXXXXXX, XXXXXXX
),

/* Numeric layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │     │     │     │     │   │  _  │  7  │  8  │  9  │  *  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │  +  │   │  -  │  4  │  5  │  6  │  0  │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │  =  │  1  │  2  │  3  │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼┬┬┬┬┬┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │││││││     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴┴┴┴┴┴┴─────┴─────┴─────┴─────╯
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
    _______, _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, KC_EQL,  KC_1,    KC_2,    KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Symbol layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │     │     │     │     │   │  _  │  &  │  *  │  ~  │  *  │     ├ ─╮
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤  │
 *                 │     │     │     │     │     │     │   │ndash│  $  │  %  │  ^  │  `  │     │  ├── Mostly shifted version
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤  │   of lower layer
 *                 │     │     │     │     │     │     │   │mdash│  !  │  @  │  #  │  /  │     ├ ─╯
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼┬┬┬┬┬┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │││││││     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴┴┴┴┴┴┴─────┴─────┴─────╯
 */
[_SL] = LAYOUT_planck_grid(
_______, _______, _______, _______, _______, _______, KC_UNDS, KC_AMPR, KC_ASTR, KC_TILD, KC_ASTR, _______,
_______, _______, _______, _______, _______, _______, NDASH,   KC_DLR,  KC_PERC, KC_CIRC, KC_GRV,  _______,
_______, _______, _______, _______, _______, _______, MDASH,   KC_EXLM, KC_AT,   KC_HASH, _______, _______,
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Symbol layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │     │     │     │     │   │  _  │  &  │  *  │  ~  │  *  │     ├ ─╮
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤  │
 *                 │     │     │     │     │     │     │   │ndash│  $  │  %  │  ^  │  `  │     │  ├── Mostly shifted version
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤  │   of lower layer
 *                 │     │     │     │     │     │     │   │mdash│  !  │  @  │  #  │  /  │     ├ ─╯
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼┬┬┬┬┬┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │││││││     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴┴┴┴┴┴┴─────┴─────┴─────╯
 */
[_iSL] = LAYOUT_planck_grid(
_______, _______, _______,  _______, _______, _______, KC_UNDS, KC_AMPR, KC_ASTR, KC_TILD, KC_ASTR, _______,
_______, _______, _______,  _______, _______, _______, iNDASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_GRV,  _______,
_______, _______, _______,  _______, _______, _______, iMDASH,  KC_EXLM, KC_AT,   KC_HASH, _______, _______,
_______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Parentheses layer
 *
 *    Kill app (Windows) ```\
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │AltF4│     │  [  │  ]  │  \  │   │  _  │BriDn│Prev │Next │BriUp│     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │  (  │  )  │  +  │   │  -  │VolDn│VolUp│Mute │Play │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │  {  │  }  │  |  │   │  =  │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼┬┬┬┬┬┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │││││││     │   │     │     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴┴┴┴┴┴┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, ALT_F4,  _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_UNDS, KC_BRID, KC_MPRV, KC_MNXT, KC_BRIU, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, _______,
    _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_EQL,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* FKEYS
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │ F12 │ F11 │ F10 │ F9  │     │   │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │ F8  │ F7  │ F6  │ F5  │     │   │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │ F4  │ F3  │ F2  │ F1  │     │   │     │     │     │     │     │     │
 *                 ├─────┼─────┼┬┬┬┬┬┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │││││││     │     │     │   │     │     │     │     │     │     │
 *                 ╰─────┴─────┴┴┴┴┴┴┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_FKEYS] = LAYOUT_planck_grid(
    _______, KC_F12,  KC_F11,  KC_F10,  KC_F9,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F4,   KC_F3,   KC_F2,   KC_F1,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust
 *
 *        RGB CONTROL ─────┬────────────────────╮
 *           ╭──────┬──────┬──────┬──────┬──────┬──────┬   ┬──────┬──────┬──────┬──────┬──────┬──────╮
 *           │      │      │RGBMOD│ HUE+ │ HUE- │Aud On│   │AudOff│Mus On│MusOff│      │      │      │
 *           ├──────┼──────┼──────┼──────┼──────┼──────┼   ┼──────┼──────┼──────┼──────┼──────┼──────┤
 *           │      │      │      │ SAT+ │ SAT- │AGnorm│   │AGswap│Qwerty│ Mac  │Plover│      │      │
 *           ├──────┼──────┼──────┼──────┼──────┼──────┼   ┼──────┼──────┼──────┼──────┼──────┼──────┤
 *           │      │ RGB  │      │BRGTH+│BRGTH-│Reset │   │MIDIof│      │      │      │      │      │
 *           ├──────┼──────┼──────┼──────┼──────┼──────┼   ┼──────┼──────┼──────┼──────┼┬┬┬┬┬┬┼──────┤
 *           │      │      │      │      │      │MIDIon│   │      │      │      │      ││││││││      │
 *           ╰──────┴──────┴──────┴──────┴──────┴──────┴   ┴──────┴──────┴──────┴──────┴┴┴┴┴┴┴┴──────╯
 */
[_FN] = LAYOUT_planck_grid(
    _______, _______, RGB_MOD, RGB_HUI, RGB_HUD, AU_ON,   AU_OFF,  MU_ON,   MU_OFF,  _______, _______, _______,
    _______, _______, _______, RGB_SAI, RGB_SAD, AG_NORM, AG_SWAP, QWERTY,  MAC,     PLOVER,  _______, _______,
    _______, RGB_TOG, _______, RGB_VAI, RGB_VAD, QK_BOOT, MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, MI_ON,   _______, _______, _______, _______, _______, _______
),

/* Navigation layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Ctl+←│Ctl+→│PgUp │   │Copy │Ctl+z│Home │ End │Paste│     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │ Del │Bspc │C+Bsp│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │ Cut │Copy │Paste│     │   │     │C+End│C+Hom│     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │││││││     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴┴┴┴┴┴┴─────┴─────┴─────┴─────┴─────╯
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______, KC_PGDN,      LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP,       LCTL(KC_INS), LCTL(KC_Z),   KC_HOME,       KC_END,  LSFT(KC_INS), _______, 
    _______, _______, LSFT_T(KC_S), KC_DEL,        KC_BSPC,       LCTL(KC_BSPC), KC_LEFT,      KC_DOWN,      KC_UP,         KC_RGHT, KC_ENT,       NEW_LINE,
    _______, _______, CUT,          YANK,          PASTE,         _______,       _______,      LCTL(KC_END), LCTL(KC_HOME), _______, _______,      _______,
    _______, _______, _______,      _______,       _______,       _______,       _______,      _______,      _______,       _______, _______,      _______
),

/* Top Layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Ctl+←│Ctl+→│PgUp │   │Copy │Ctl+z│Home │ End │Paste│     │
 *                 ├┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │││││││     │     │ Del │Bspc │C+Bsp│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├┴┴┴┴┴┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │ Cut │Copy │Paste│     │   │     │C+End│C+Hom│     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_TL] = LAYOUT_planck_grid(
    _______, _______, KC_PGDN,      LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP,       YANK,    LCTL(KC_Z),   KC_HOME,       KC_END,  LSFT(KC_INS), _______, 
    _______, _______, LSFT_T(KC_S), KC_DEL,        KC_BSPC,       LCTL(KC_BSPC), KC_LEFT, KC_DOWN,      KC_UP,         KC_RGHT, KC_ENT,       NEW_LINE,
    _______, _______, CUT,          YANK,          PASTE,         _______,       _______, LCTL(KC_END), LCTL(KC_HOME), _______, _______,      _______,          
    _______, _______, _______,      _______,       _______,       _______,       _______, _______,      _______,       _______, _______,      _______
),

/* Navigation layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Alt+←│Alt+→│PgUp │   │Copy │Undo │Home │ End │Paste│     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │ Del │Bspc │A+Bsp│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │ Cut │Copy │Paste│     │   │     │ C+↓ │ C+↑ │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │││││││     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴┴┴┴┴┴┴─────┴─────┴─────┴─────┴─────╯
 */
[_iNAV] = LAYOUT_planck_grid(
    _______, _______, LCTL(KC_DOWN), LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_UP),   LGUI(KC_C), LGUI(KC_Z),    LCTL(KC_LEFT), LCTL(KC_RGHT), LGUI(KC_V), _______, 
    _______, _______, LSFT_T(KC_S),  KC_DEL,        KC_BSPC,       LALT(KC_BSPC), KC_LEFT,    KC_DOWN,       KC_UP,         KC_RGHT,       KC_ENT,     NEW_LINE,
    _______, _______, LGUI(KC_X),    LGUI(KC_C),    LGUI(KC_V),    _______,       _______,    LCTL(KC_DOWN), LCTL(KC_UP),   _______,       _______,    _______,
    _______, _______, _______,       _______,       _______,       _______,       _______,    _______,       _______,       _______,       _______,    _______
),

/* Top Layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Alt+←│Alt+→│PgUp │   │Copy │Undo │Home │ End │Paste│     │
 *                 ├┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │││││││     │     │ Del │Bspc │A+Bsp│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├┴┴┴┴┴┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │ Cut │Copy │Paste│     │   │     │ C+↓ │ C+↑ │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_iTL] = LAYOUT_planck_grid(
    _______, _______, LCTL(KC_DOWN), LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_UP),   LGUI(KC_C), LGUI(KC_Z),    LCTL(KC_LEFT), LCTL(KC_RGHT), LGUI(KC_V), _______, 
    _______, _______, LSFT_T(KC_S),  KC_DEL,        KC_BSPC,       LALT(KC_BSPC), KC_LEFT,    KC_DOWN,       KC_UP,         KC_RGHT,       KC_ENT,     NEW_LINE,
    _______, _______, LGUI(KC_X),    LGUI(KC_C),    LGUI(KC_V),    _______,       _______,    LCTL(KC_DOWN), LCTL(KC_UP),   _______,       _______,    _______,          
    _______, _______, _______,       _______,       _______,       _______,       _______,    _______,       _______,       _______,       _______,    _______
)

/* Layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
/*  [_Layer] = LAYOUT_planck_grid(
 *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
 *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 *  ),
 */ 

};

#ifdef AUDIO_ENABLE
    float plover_song[][2]     = SONG(PLOVER_SOUND);
    float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// activate layer by pressing Lower + Raise
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _FKEYS);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                #ifdef BACKLIGHT_ENABLE
                    backlight_step();
                #endif
                #ifdef KEYBOARD_planck_rev5
                    writePinLow(E6);
                #endif
            } else {
                unregister_code(KC_RSFT);
                #ifdef KEYBOARD_planck_rev5
                    writePinHigh(E6);
                #endif
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(plover_song);
                #endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_FN);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(plover_gb_song);
                #endif
                layer_off(_PLOVER);
            }
            return false;
            break;
        case NEW_LINE:
            if (record->event.pressed) {
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Create new line above cursor
                    unregister_code(KC_LSFT);
                    SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_ENT) SS_TAP(X_UP));
                } else {
                    // Create new line below cursor
                    SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_ENT));
                }
            }
            return false;
            break;
        case NDASH:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0)));
            }
            return false;
            break;
        case MDASH:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
            }
            return false;
            break;
        // case QUOTE_DOUBLE_LEFT_LOW: // „
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_2)));
        //     }
        //     return false;
        //     break;
        // case QUOTE_DOUBLE_LEFT: // “
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_7)));
        //     }
        //     return false;
        //     break;
        // case QUOTE_DOUBLE_RIGHT: // ”
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8)));
        //     }
        //     return false;
        //     break;
        // case QUOTE_SINGLE_LEFT: // ‘
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_5)));
        //     }
        //     return false;
        //     break;
        // case QUOTE_SINGLE_RIGHT: // ’
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_6)));
        //     }
        //     return false;
        //     break;
        // case QUOTE_ANGLE_RIGHT: // » OK
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_5)));
        //     }
        //     return false;
        //     break;
        // case QUOTE_ANGLE_LEFT: // « 
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_4)));
        //     }
        //     return false;
        //     break;
        // case THREE_DOT: // … OK
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_3)));
        //     }
        //     return false;
        //     break;
        // case BULLET: // •
        //     if (record->event.pressed) {
        //         SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_9)));
        //     }
        //     return false;
        //     break;
    }

    return true; //Process all other
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
            muse_offset++;
        } else {
            muse_offset--;
        }
    } else {
        if (clockwise) {
            muse_tempo+=1;
        } else {
            muse_tempo-=1;
        }
    }
  } else {
    if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
        #else
            tap_code(KC_PGDN);
        #endif
    } else {
        #ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
        #else
            tap_code(KC_PGUP);
        #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            #ifdef AUDIO_ENABLE
                static bool play_sound = false;
            #endif
            if (active) {
                #ifdef AUDIO_ENABLE
                    if (play_sound) { PLAY_SONG(plover_song); }
                #endif
                    layer_on(_FN); 
            } else {
                #ifdef AUDIO_ENABLE
                    if (play_sound) { PLAY_SONG(plover_gb_song); }
                #endif
                    layer_off(_FN);
            }
            #ifdef AUDIO_ENABLE
                        play_sound = true;
            #endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

// ----------------------------------- COMBOS ----------------------------------

enum combo_events {
    MY_COMBO_LGUI_1, 
    MY_COMBO_LGUI_2,
    MY_COMBO_LGUI_3,
    MY_COMBO_LGUI_4,
    MY_COMBO_LGUI_5,
    MY_COMBO_LGUI_6,
    MY_COMBO_LGUI_7,
    MY_COMBO_LGUI_8,
    MY_COMBO_LGUI_9,
    MY_COMBO_LGUI_0,

    MY_COMBO_F1,
    MY_COMBO_F2,
    MY_COMBO_F3,
    MY_COMBO_F4,
    MY_COMBO_F5,
    MY_COMBO_F6,
    MY_COMBO_F7,
    MY_COMBO_F8,
    MY_COMBO_F9,
    MY_COMBO_F10,
    MY_COMBO_F11,
    MY_COMBO_F12
    // Remember to update COMBO_COUNT in config.h
};

const uint16_t PROGMEM combo_LGUI_1[] = { LOWER, KC_M, COMBO_END };
const uint16_t PROGMEM combo_LGUI_2[] = { LOWER, KC_COMM, COMBO_END };
const uint16_t PROGMEM combo_LGUI_3[] = { LOWER, KC_DOT, COMBO_END };
const uint16_t PROGMEM combo_LGUI_4[] = { LOWER, RGUI_J, COMBO_END };
const uint16_t PROGMEM combo_LGUI_5[] = { LOWER, RCTL_K, COMBO_END };
const uint16_t PROGMEM combo_LGUI_6[] = { LOWER, RSFT_L, COMBO_END };
const uint16_t PROGMEM combo_LGUI_7[] = { LOWER, KC_U, COMBO_END };
const uint16_t PROGMEM combo_LGUI_8[] = { LOWER, KC_I, COMBO_END };
const uint16_t PROGMEM combo_LGUI_9[] = { LOWER, KC_O, COMBO_END };
const uint16_t PROGMEM combo_LGUI_0[] = { LOWER, RALT_SCLN, COMBO_END };

const uint16_t PROGMEM combo_F1[] = { RAISE, KC_V, COMBO_END };
const uint16_t PROGMEM combo_F2[] = { RAISE, KC_C, COMBO_END };
const uint16_t PROGMEM combo_F3[] = { RAISE, KC_X, COMBO_END };
const uint16_t PROGMEM combo_F4[] = { RAISE, KC_Z, COMBO_END };
const uint16_t PROGMEM combo_F5[] = { RAISE, LGUI_F, COMBO_END };
const uint16_t PROGMEM combo_F6[] = { RAISE, LCTL_D, COMBO_END };
const uint16_t PROGMEM combo_F7[] = { RAISE, LSFT_S, COMBO_END };
const uint16_t PROGMEM combo_F8[] = { RAISE, LALT_A, COMBO_END };
const uint16_t PROGMEM combo_F9[] = { RAISE, KC_R, COMBO_END };
const uint16_t PROGMEM combo_F10[] = { RAISE, KC_E, COMBO_END };
const uint16_t PROGMEM combo_F11[] = { RAISE, KC_W, COMBO_END };
const uint16_t PROGMEM combo_F12[] = { RAISE, KC_Q, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    [MY_COMBO_LGUI_1] = COMBO_ACTION(combo_LGUI_1),
    [MY_COMBO_LGUI_2] = COMBO_ACTION(combo_LGUI_2),
    [MY_COMBO_LGUI_3] = COMBO_ACTION(combo_LGUI_3),
    [MY_COMBO_LGUI_4] = COMBO_ACTION(combo_LGUI_4),
    [MY_COMBO_LGUI_5] = COMBO_ACTION(combo_LGUI_5),
    [MY_COMBO_LGUI_6] = COMBO_ACTION(combo_LGUI_6),
    [MY_COMBO_LGUI_7] = COMBO_ACTION(combo_LGUI_7),
    [MY_COMBO_LGUI_8] = COMBO_ACTION(combo_LGUI_8),
    [MY_COMBO_LGUI_9] = COMBO_ACTION(combo_LGUI_9),
    [MY_COMBO_LGUI_0] = COMBO_ACTION(combo_LGUI_0),

    [MY_COMBO_F1] = COMBO_ACTION(combo_F1),
    [MY_COMBO_F2] = COMBO_ACTION(combo_F2),
    [MY_COMBO_F3] = COMBO_ACTION(combo_F3),
    [MY_COMBO_F4] = COMBO_ACTION(combo_F4),
    [MY_COMBO_F5] = COMBO_ACTION(combo_F5),
    [MY_COMBO_F6] = COMBO_ACTION(combo_F6),
    [MY_COMBO_F7] = COMBO_ACTION(combo_F7),
    [MY_COMBO_F8] = COMBO_ACTION(combo_F8),
    [MY_COMBO_F9] = COMBO_ACTION(combo_F9),
    [MY_COMBO_F10] = COMBO_ACTION(combo_F10),
    [MY_COMBO_F11] = COMBO_ACTION(combo_F11),
    [MY_COMBO_F12] = COMBO_ACTION(combo_F12),
};

#define COMBO_MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define SEND_CAP_STRING(str, capitalized) if (COMBO_MODS_SHIFT) { \
                                            clear_mods(); \
                                            SEND_STRING(capitalized); \
                                          } else { \
                                            SEND_STRING(str); \
                                          }

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case MY_COMBO_LGUI_1:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_1) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_2:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_2) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_3:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_3) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_4:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_4) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_5:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_5) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_6:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_6) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_7:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_7) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_8:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_8) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_9:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_9) SS_UP(X_LGUI));
            }
            break;
        case MY_COMBO_LGUI_0:
            if (pressed) {
                SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_0) SS_UP(X_LGUI));
            }
            break;

        case MY_COMBO_F1:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F1));
            }
            break;
        case MY_COMBO_F2:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F2));
            }
            break;
        case MY_COMBO_F3:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F3));
            }
            break;
        case MY_COMBO_F4:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F4));
            }
            break;
        case MY_COMBO_F5:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F5));
            }
            break;
        case MY_COMBO_F6:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F6));
            }
            break;
        case MY_COMBO_F7:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F7));
            }
            break;
        case MY_COMBO_F8:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F8));
            }
            break;
        case MY_COMBO_F9:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F9));
            }
            break;
        case MY_COMBO_F10:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F10));
            }
            break;
        case MY_COMBO_F11:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F11));
            }
            break;
        case MY_COMBO_F12:
            if (pressed) {
                SEND_STRING(SS_TAP(X_F12));
            }
            break;
    }
}
