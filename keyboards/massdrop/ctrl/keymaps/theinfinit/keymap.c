#include QMK_KEYBOARD_H
// #include "keymap.h"

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5, KC_F6, KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,  KC_6,  KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,  KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,            KC_ESC,  KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, \
        MO(6),   LALT_T(KC_A), LSFT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G,  KC_H,  RGUI_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), RALT_T(KC_SCLN), LT(5,KC_QUOT), KC_ENT, \
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,  KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT,                            KC_UP, \
        KC_LCTL, KC_LGUI, MO(3),                                         KC_SPC,                                   MO(4),        MO(2),           KC_APP,  KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_7,    KC_8,    KC_9, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_4,    KC_5,    KC_6, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_1,    KC_2,    KC_3, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                             KC_0, \
        _______, _______, _______,                            _______,                   _______, _______, _______, _______,           KC_MINS, KC_COMM, KC_DOT \
    ),
    [2] = LAYOUT(
        _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,   _______, _______, _______, _______,          KC_PSCR, _______, _______, \
        _______, RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,   RGB_M_T, _______, _______, _______, _______, KC_MNXT, KC_MUTE, KC_VOLU, \
        BL_BRTG, RGB_SPD,  RGB_VAI, RGB_SPI, RGB_HUI,  RGB_SAI,  _______, U_T_AUTO, U_T_AGCR, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_VOLD, \
        _______, RGB_RMOD, RGB_VAD, RGB_MOD, RGB_HUD,  RGB_SAD,  _______, _______, _______,   _______, _______, _______, _______, \
        _______, RGB_TOG,  BL_TOGG, BL_STEP, _______,  RESET,    NK_TOGG, _______, _______,   _______, _______,                                     _______, \
        _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,                                                _______, _______, _______ \
    ),
    [3] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      KC_F1,      KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,  _______, _______, _______, \
        LALT(KC_TAB), KC_1,       KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______,  _______, _______, _______, \
        _______,      LALT(KC_A), LSFT_T(KC_PIPE), KC_LPRN, KC_RPRN, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  KC_TILD, _______, \
        _______,      _______,    _______,      KC_UNDS, _______, _______, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [4] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      KC_F1,      KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,  _______, _______, _______, \
        LALT(KC_TAB), KC_EXLM,    KC_AT,        KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_UNDS, _______, _______, _______,  _______, _______, _______, \
        _______,      KC_1,       KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______, _______, \
        _______,      _______,    _______,      KC_UNDS, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [5] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        LALT(KC_TAB), _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        _______,      KC_EXLM,    KC_AT,        KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_UNDS,  _______, _______, \
        _______,      _______,    _______,      KC_UNDS, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [6] = LAYOUT(
        _______, _______, _______,            _______,       _______,       _______,       _______, _______,    _______, _______, _______, _______, TG(1),            _______, _______, _______, \
        KC_TILD, KC_EXLM, KC_AT,              KC_HASH,       KC_DLR,        KC_PERC,       KC_CIRC, KC_AMPR,    KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, _______, _______, _______, \
        _______, _______, _______,            LCTL(KC_LEFT), LCTL(KC_RGHT), _______,       _______, LCTL(KC_Z), KC_HOME, KC_END,  _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, LSFT_T(LCTL(KC_S)), KC_DEL,        KC_BSPC,       LCTL(KC_BSPC), KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT, KC_ENT,  _______, _______, \
        _______, _______, LCTL(KC_X),         LCTL(KC_C),    LCTL(KC_V),    _______,       _______, _______,    _______, _______, _______, _______,                            _______, \
        _______, _______, _______,                                          _______,                                     _______, _______, _______, _______,          _______, _______, _______ \
    )
};



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
//    rgb_enabled_flag = true;  // Initially, keyboard RGB is enabled. Change to false config.h initializes RGB disabled.
};

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

// Runs constantly in the background, in a loop.
void matrix_scan_user(void){};

//
#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}