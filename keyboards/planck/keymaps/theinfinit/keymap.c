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


enum planck_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

// Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GUINO MO(_GUINO)
#define FKEYS MO(_FKEYS)
#define FN MO(_FN)

// Mod on hold, key on tap
#define LALT_A LALT_T(KC_A)
#define LSFT_S LSFT_T(KC_S) 
#define LCTL_D LCTL_T(KC_D) 
#define LGUI_F LGUI_T(KC_F)

#define YANK  LCTL(KC_C)
#define PASTE LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,------------------------------------------------  ------------------------------------------------.
 * | Tab   |   Q   |   W   |   E   |   R   |   T   |  |   Y   |   U   |   I   |   O   |   P   | Esc   |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * | _TL   | Alt/A |   S   |   D   |   F   |   G   |  |   H   |   J   |   K   |   L   |   ;   |  '    |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * | Shift |   Z   |   X   |   C   |   V   |   B   |  |   N   |   M   |   ,   |   .   |   /   | Enter |
 * |-------+-------+---------------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * | Ctrl  |  Gui  | FKEYS |  Alt  | Raise | GuiNo |  | Space | Lower |       | PrtSc |  Fn   | Menu  |
 * `------------------------------------------------  ------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,  KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_ESC,
    MO(_TL), LALT_A,  LSFT_S, LCTL_D,  LGUI_F, KC_G,  KC_H,   RGUI_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), RALT_T(KC_SCLN), LT(_NSL,KC_QUOT),
    KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,  KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ENT,
    KC_LCTL, KC_LGUI, FKEYS,  KC_LALT, RAISE,  GUINO, KC_SPC, LOWER,        _______,      KC_PSCR,      FN,              KC_APP
),

/* Lower 
 * ,------------------------------------------------  ------------------------------------------------.
 * |       |       |       |       |       |       |  |   _   |   7   |   8   |   9   |   *   |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |   +   |  |   -   |   4   |   5   |   6   |   0   |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |   =   |   1   |   2   |   3   |       |       |
 * |-------+-------+---------------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * `------------------------------------------------  ------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_UNDS, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
    _______, _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, KC_EQL,  KC_1,    KC_2,    KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise 
 * ,------------------------------------------------  ------------------------------------------------.
 * |       |       |       |       |       |       |  |   _   |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |   (   |   )   |   +   |  |   -   |   [   |   ]   |   \   |   `   |   ~   |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       | Copy  | Paste |       |  |   =   |   {   |   }   |       |       |       |
 * |-------+-------+---------------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * `------------------------------------------------  ------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  KC_TILD,
    _______, _______, _______, YANK,    PASTE,   _______, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/*  [_RAISE] = LAYOUT_planck_grid(
 *      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
 *      KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
 *      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
 *      _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
 *  ),
 */ 

/* GuiNo 
 * ,------------------------------------------------  ------------------------------------------------.
 * |       |       |       | Gui+0 | Gui+9 |       |  | Yank  | Ctl+z | Home  |  End  | Paste |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       | Gui+6 | Gui+7 | Gui+6 | Gui+5 |       |  | Left  | Down  |  Up   | Right | Enter |NewLine|
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       | Gui+4 | Gui+3 | Gui+2 | Gui+1 |       |  |       |       |       |       |       |       |
 * |-------+-------+---------------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * `------------------------------------------------  ------------------------------------------------'
 */
[_GUINO] = LAYOUT_planck_grid(
    _______, KC_INS,  KC_PGDN, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP, LCTL(KC_INS), LCTL(KC_Z), KC_HOME, KC_END,  LSFT(KC_INS), _______, 
    _______, _______, _______, _______,       _______,       _______, KC_LEFT,      KC_DOWN,    KC_UP,   KC_RGHT, KC_ENT,       NEW_LINE,
    _______, _______, _______, _______,       _______,       _______, _______,      _______,    _______, _______, _______,      _______,
    _______, _______, _______, _______,       _______,       _______, _______,      _______,    _______, _______, _______,      _______
),

/* FKEYS 
 * ,------------------------------------------------  ------------------------------------------------.
 * |       |  F12  |  F11  |  F10  |  F9   |       |  |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |  F6   |  F7   |  F6   |  F5   |       |  |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |  F4   |  F3   |  F2   |  F1   |       |  |       |       |       |       |       |       |
 * |-------+-------+---------------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * `------------------------------------------------  ------------------------------------------------'
 */
[_FKEYS] = LAYOUT_planck_grid(
    _______, KC_F12,  KC_F11,  KC_F10,  KC_F9,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F4,   KC_F3,   KC_F2,   KC_F1,   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
    
/* Plover layer (https://www.openstenoproject.org/)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Brite |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_FL] = LAYOUT_planck_grid(
    _______, _______,        KC_PGDN,      LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP,       YANK,    LCTL(KC_Z), KC_HOME, KC_END,  LSFT(KC_INS), _______, 
    _______, LALT_T(KC_INS), LSFT_T(KC_S), KC_DEL,        KC_BSPC,       LCTL(KC_BSPC), KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT, KC_ENT,       NEW_LINE,
    _______, _______,        LCTL(KC_X),   COPY_CUT,      LSFT(KC_INS),  _______,       _______, _______,    _______, _______, _______,      _______,          
    _______, _______,        _______,      _______,       _______,       _______,       _______, _______,    _______, _______, _______,      _______
)


/* Layer 
 * ,------------------------------------------------  ------------------------------------------------.
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * |-------+-------+---------------+-------+-------+  +-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  |       |       |       |       |       |       |
 * `------------------------------------------------  ------------------------------------------------'
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            print("mode just switched to qwerty and this is a huge string\n");
            set_single_persistent_default_layer(_QWERTY);
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
            layer_off(_ADJUST);
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
  }
  return true;
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
                    layer_on(_ADJUST); 
            } else {
                #ifdef AUDIO_ENABLE
                    if (play_sound) { PLAY_SONG(plover_gb_song); }
                #endif
                    layer_off(_ADJUST);
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
