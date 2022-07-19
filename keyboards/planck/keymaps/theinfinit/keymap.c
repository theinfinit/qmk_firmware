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

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_steno.h"

enum planck_layers {
  _QWERTY,
  _MAC,
  _PLOVER,
  _LOWER,
  _SL,
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
  NEW_LINE
};

#define IGNORE_MOD_TAP_INTERRUPT

// Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FKEYS MO(_FKEYS)
#define FN MO(_FN)
#define NAV MO(_NAV)
#define iNAV MO(_iNAV)

// Mod on hold, key on tap
#define LALT_A LALT_T(KC_A)       // Hold: Left Alt    // Tap: A
#define LSFT_S LSFT_T(KC_S)       // Hold: Left Shift  // Tap: S
#define LCTL_D LCTL_T(KC_D)       // Hold: Left Ctrl   // Tap: D
#define LGUI_F LGUI_T(KC_F)       // Hold: Left GUI    // Tap: F

#define RGUI_J RGUI_T(KC_J)       // Hold: Right GUI   // Tap: J
#define RCTL_K RCTL_T(KC_K)       // Hold: Right Ctrl  // Tap: K
#define RSFT_L RSFT_T(KC_L)       // Hold: Right Shift // Tap: L
#define RALT_SCLN RALT_T(KC_SCLN) // Hold: Right Alt   // Tap: ;

#define LCTL_PS LCTL_T(KC_PSCR) // Hold: Left Ctrl   // Tap: Print Screen
#define LGUI_PS LGUI_T(KC_PSCR) // Hold: Left Ctrl   // Tap: Print Screen

// Shortcuts
#define YANK  LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define ALT_F4 LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer (Qwerty)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │ Tab │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │  '  │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │ _TL │Alt/A│Sft/S│Ctl/D│Gui/F│  G  │   │  H  │Gui/J│Ctl/K│Sft/L│Alt/;│Enter│
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │ Sft │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ Esc │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 * Tap for PrSc -- │ Ctl │ Gui │FKEYS│ Alt │Raise│Space│   │ Nav │Lower│ _SL │ Ins │ Fn  │ App │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,      KC_QUOT,
    MO(_TL), LALT_A,  LSFT_S, LCTL_D,  LGUI_F, KC_G,   KC_H,  RGUI_J, RCTL_K,  RSFT_L, RALT_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_ESC,
    LCTL_PS, KC_LGUI, FKEYS,  KC_LALT, RAISE,  KC_SPC, NAV,   LOWER,  MO(_SL), KC_INS, FN,        KC_APP
),

/* Base layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │ Tab │  Q  │  W  │  E  │  R  │  T  │   │  Y  │  U  │  I  │  O  │  P  │  '  │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │ iTL │Alt/A│Sft/S│Gui/F│Ctl/D│  G  │   │  H  │Ctl/K│Gui/J│Sft/L│Alt/;│Enter│
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │ Sft │  Z  │  X  │  C  │  V  │  B  │   │  N  │  M  │  ,  │  .  │  /  │ Esc │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 * Tap for PrSc -- │ Gui │ Ctl │FKEYS│ Alt │Raise│Space│   │iNav │Lower│ _SL │ Ins │ Fn  │ App │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_MAC] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_Y,  KC_U,   KC_I,    KC_O,   KC_P,      KC_QUOT,
    MO(_iTL), LALT_A,  LSFT_S, LGUI_F,  LCTL_D, KC_G,  KC_H,  RCTL_K, RGUI_J,  RSFT_L, RALT_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_ESC,
    LGUI_PS, KC_LCTL, FKEYS,  KC_LALT, RAISE,  KC_SPC, iNAV,  LOWER,  MO(_SL), KC_INS, FN,        KC_APP
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
 *                 │     │     │     │     │     │     │   │  _  │  &  │  *  │  ~  │  *  │     │╲
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤ |
 *                 │     │     │     │     │     │     │   │ndash│  $  │  %  │  ^  │  `  │     │ |-- Mostly shifted version
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤ |   of lower layer
 *                 │     │     │     │     │     │     │   │mdash│  !  │  @  │  #  │  /  │     │╱
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼┬┬┬┬┬┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │││││││     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴┴┴┴┴┴┴─────┴─────┴─────╯
 */
[_SL] = LAYOUT_planck_grid(
_______, _______, _______,  _______, _______, _______, KC_UNDS, KC_AMPR, KC_ASTR, KC_TILD, KC_ASTR, _______,
_______, _______, _______,  _______, _______, _______, _______, KC_DLR,  KC_PERC, KC_CIRC, KC_GRV,  _______,
_______, _______, _______,  _______, _______, _______, _______, KC_EXLM, KC_AT,   KC_HASH, _______, _______,
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
 *                 │     │ F6  │ F7  │ F6  │ F5  │     │   │     │     │     │     │     │     │
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
 *                RGB CONTROL -----/````````````````````````````````````````````````````````\
 *           ╭──────┬──────┬──────┬──────┬──────┬──────┬   ┬──────┬──────┬──────┬──────┬──────┬──────╮
 *           │      │Reset │Debug │ RGB  │RGBMOD│ HUE+ │   │ HUE- │ SAT+ │ SAT- │BRGTH+│BRGTH-│  Del │
 *           ├──────┼──────┼──────┼──────┼──────┼──────┼   ┼──────┼──────┼──────┼──────┼──────┼──────┤
 *           │      │      │MUSmod│Aud on│Audoff│AGnorm│   │AGswap│Qwerty│ Mac  │Plover│      │      │
 *           ├──────┼──────┼──────┼──────┼──────┼──────┼   ┼──────┼──────┼──────┼──────┼──────┼──────┤
 *           │      │Voice-│Voice+│Mus on│Musoff│MIDIon│   │MIDIof│TermOn│TermOf│      │      │      │
 *           ├──────┼──────┼──────┼──────┼──────┼──────┼   ┼──────┼──────┼──────┼──────┼┬┬┬┬┬┬┼──────┤
 *           │Brite │      │      │      │      │      │   │      │      │      │      ││││││││      │
 *           ╰──────┴──────┴──────┴──────┴──────┴──────┴   ┴──────┴──────┴──────┴──────┴┴┴┴┴┴┴┴──────╯
 */
[_FN] = LAYOUT_planck_grid(
    _______, QK_BOOT, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  MAC,      PLOVER,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Navigation layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Ctl+←│Ctl+→│PgUp │   │Copy │Ctl+z│Home │ End │Paste│     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │Gui+0│Gui+9│Gui+8│Gui+7│Gui+6│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │Gui+5│Gui+4│Gui+3│Gui+2│Gui+1│   │     │C+End│C+Hom│     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │││││││     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴┴┴┴┴┴┴─────┴─────┴─────┴─────┴─────╯
 */
[_NAV] = LAYOUT_planck_grid(
    _______, _______,    KC_PGDN,            LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP,    LCTL(KC_INS), LCTL(KC_Z),   KC_HOME,       KC_END,  LSFT(KC_INS), _______, 
    _______, LGUI(KC_0), LSFT_T(LGUI(KC_9)), LGUI(KC_8),    LGUI(KC_7),    LGUI(KC_6), KC_LEFT,      KC_DOWN,      KC_UP,         KC_RGHT, KC_ENT,       NEW_LINE,
    _______, LGUI(KC_5), LGUI(KC_4),         LGUI(KC_3),    LGUI(KC_2),    LGUI(KC_1), _______,      LCTL(KC_END), LCTL(KC_HOME), _______, _______,      _______,
    _______, _______,    _______,            _______,       _______,       _______,    _______,      _______,      _______,       _______, _______,      _______
),

/* Top Layer
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Ctl+←│Ctl+→│PgUp │   │Copy │Ctl+z│Home │ End │Paste│     │
 *                 ├┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │││││││     │     │ Del │Bspc │C+Bsp│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├┴┴┴┴┴┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │Copy │Paste│     │   │     │C+End│C+Hom│     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │     │     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴─────┴─────┴─────┴─────┴─────┴─────╯
 */
[_TL] = LAYOUT_planck_grid(
    _______, _______, KC_PGDN,      LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP,       YANK,    LCTL(KC_Z),   KC_HOME,       KC_END,  LSFT(KC_INS), _______, 
    _______, _______, LSFT_T(KC_S), KC_DEL,        KC_BSPC,       LCTL(KC_BSPC), KC_LEFT, KC_DOWN,      KC_UP,         KC_RGHT, KC_ENT,       NEW_LINE,
    _______, _______, _______,      YANK,          PASTE,         _______,       _______, LCTL(KC_END), LCTL(KC_HOME), _______, _______,      _______,          
    _______, _______, _______,      _______,       _______,       _______,       _______, _______,      _______,       _______, _______,      _______
),

/* Navigation layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Alt+←│Alt+→│PgUp │   │Copy │Undo │Home │ End │Paste│     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │Gui+0│Gui+9│Gui+8│Gui+7│Gui+6│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │Gui+5│Gui+4│Gui+3│Gui+2│Gui+1│   │     │ C+↓ │ C+↑ │     │     │     │
 *                 ├─────┼─────┼─────┼─────┼─────┼─────┼   ┼┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │     │     │     │     │   │││││││     │     │     │     │     │
 *                 ╰─────┴─────┴─────┴─────┴─────┴─────┴   ┴┴┴┴┴┴┴─────┴─────┴─────┴─────┴─────╯
 */
[_iNAV] = LAYOUT_planck_grid(
    _______, _______,    LCTL(KC_DOWN),      LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_UP), LGUI(KC_C), LGUI(KC_Z),    LCTL(KC_LEFT), LCTL(KC_RGHT), LGUI(KC_V), _______, 
    _______, LGUI(KC_0), LSFT_T(LGUI(KC_9)), LGUI(KC_8),    LGUI(KC_7),    LGUI(KC_6),  KC_LEFT,    KC_DOWN,       KC_UP,         KC_RGHT,       KC_ENT,     NEW_LINE,
    _______, LGUI(KC_5), LGUI(KC_4),         LGUI(KC_3),    LGUI(KC_2),    LGUI(KC_1),  _______,    LCTL(KC_DOWN), LCTL(KC_UP),   _______,       _______,    _______,
    _______, _______,    _______,            _______,       _______,       _______,     _______,    _______,       _______,       _______,       _______,    _______
),

/* Top Layer (Mac/iPad)
 *                 ╭─────┬─────┬─────┬─────┬─────┬─────┬   ┬─────┬─────┬─────┬─────┬─────┬─────╮
 *                 │     │     │PgDn │Alt+←│Alt+→│PgUp │   │Copy │Undo │Home │ End │Paste│     │
 *                 ├┬┬┬┬┬┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │││││││     │     │ Del │Bspc │A+Bsp│   │  ←  │  ↓  │  ↑  │  →  │Enter│NwLine
 *                 ├┴┴┴┴┴┼─────┼─────┼─────┼─────┼─────┼   ┼─────┼─────┼─────┼─────┼─────┼─────┤
 *                 │     │     │Cut  │Copy │Paste│     │   │     │ C+↓ │ C+↑ │     │     │     │
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

// Probably to enable activation of layer by pressing Lower + Raise
// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _FN);
// }

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
