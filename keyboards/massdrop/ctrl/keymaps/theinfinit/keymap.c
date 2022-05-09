#include "keymap.h"

static uint8_t key_event_counter;       // This counter is used to check if any keys are being held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KL] = LAYOUT(
        KC_ESC,  KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5, KC_F6, KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,           KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,  KC_6,  KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,          KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,  KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC,          KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN, \
        MO(_FL), LALT_T(KC_A), LSFT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G,  KC_H,  RGUI_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), RALT_T(KC_SCLN), LT(_NSL,KC_QUOT), KC_ENT, \
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,  KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ESC,                                       KC_UP, \
        KC_LCTL, KC_LGUI,      MO(_SL),                                  KC_SPC,                                   MO(_NL),      MO(_ML),         KC_APP,           KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_ML] = LAYOUT(
        _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,   _______, _______, _______, _______,          KC_PSCR, _______, _______, \
        _______, RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,   RGB_M_T, _______, _______, _______, _______, KC_MNXT, KC_MUTE, KC_VOLU, \
        BL_BRTG, RGB_SPD,  RGB_VAI, RGB_SPI, RGB_HUI,  RGB_SAI,  _______, U_T_AUTO, U_T_AGCR, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_VOLD, \
        _______, RGB_RMOD, RGB_VAD, RGB_MOD, RGB_HUD,  RGB_SAD,  _______, _______, _______,   _______, _______, _______, _______, \
        _______, RGB_TOG,  BL_TOGG, BL_STEP, _______,  RESET,    NK_TOGG, _______, _______,   _______, _______,                                     _______, \
        _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,                                                _______, _______, _______ \
    ),
    [_NL] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      KC_F1,      KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______, _______, \
        LALT(KC_TAB), KC_EXLM,    KC_AT,        KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL,  KC_UNDS, _______, _______, _______,  _______, _______, _______, \
        _______,      KC_1,       KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
        _______,      _______,    _______,      KC_UNDS, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [_SL] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      KC_F1,      KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______, _______, \
        LALT(KC_TAB), KC_1,       KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______,  _______, _______, _______, \
        _______,      LALT(KC_A), LSFT_T(KC_S), KC_LPRN, KC_RPRN, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  KC_TILD, _______, \
        _______,      _______,    _______,      _______, KC_UNDS, _______, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [_NSL] = LAYOUT(
        _______,      _______,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      _______,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        LALT(KC_TAB), _______,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        _______,      KC_EXLM,    KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, _______, _______, _______, \
        _______,      _______,    _______,  KC_UNDS, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                             _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [_FL] = LAYOUT(
        _______, _______,         _______,      _______,       _______,       _______, _______, _______,    _______, _______,  _______,      _______, _______,             _______, _______, _______, \
        KC_TILD, KC_EXLM,         KC_AT,        KC_HASH,       KC_DLR,        KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR, KC_LPRN,  KC_RPRN,      KC_UNDS, KC_PLUS, _______,    _______, _______, _______, \
        _______, _______,         KC_PGDN,      LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP, VIM_Y,   LCTL(KC_Z), KC_END,  NEW_LINE, LSFT(KC_INS), _______, _______, _______,    _______, _______, _______, \
        _______, LALT_T(KC_INS),  LSFT_T(KC_S), VIM_D,         KC_BSPC,       VIM_G,   KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT,  KC_ENT,       _______, _______, \
        _______, COPY_ALL,        KC_DEL,       VIM_C,         _______,       _______, KC_HOME, _______,    _______, _______,  _______,      _______,                               _______, \
        _______, _______,         _______,                                             _______,                      _______,  _______,      _______, _______,             _______, _______, _______ \
    ), 
    [_VIM_YANK] = LAYOUT(
        _______, _______,  _______, _______,             _______,   _______, _______,             _______,             _______,           _______,     _______, _______, _______,           _______, _______, _______, \
        _______, _______,  _______, _______,             _______,   _______, _______,             _______,             _______,           _______,     _______, _______, _______, _______,  _______, _______, _______, \
        _______, _______,  _______, COPY_WORD_BACKWARDS, COPY_WORD, _______, COPY_LINE,           _______,             COPY_TO_EOL,       _______,     _______, _______, _______, _______,  _______, _______, _______, \
        _______, COPY_ALL, _______, _______,             _______,   _______, COPY_WORD_BACKWARDS, COPY_TWO_LINES_DOWN, COPY_TWO_LINES_UP, COPY_WORD,   _______, _______, _______,
        _______, _______,  _______, _______,             _______,   _______, COPY_TO_BOL,         _______,             _______,           _______,     _______, _______,                             _______, \
        _______, _______,  _______,                                          _______,                                                     _______,     _______, _______, _______,           _______, _______, _______ \
    ),
    [_VIM_DELETE] = LAYOUT(
        _______, _______,    _______, _______,               _______,     _______, _______,               _______,               _______,             _______,     _______, _______, _______,           _______, _______, _______, \
        _______, _______,    _______, _______,               _______,     _______, _______,               _______,               _______,             _______,     _______, _______, _______, _______,  _______, _______, _______, \
        _______, _______,    _______, DELETE_WORD_BACKWARDS, DELETE_WORD, _______, _______,               _______,               DELETE_TO_EOL,       _______,     _______, _______, _______, _______,  _______, _______, _______, \
        _______, DELETE_ALL, _______, DELETE_LINE,           _______,     _______, DELETE_WORD_BACKWARDS, DELETE_TWO_LINES_DOWN, DELETE_TWO_LINES_UP, DELETE_WORD, _______, _______, _______,
        _______, _______,    _______, _______,               _______,     _______, DELETE_TO_BOL,         _______,               _______,             _______,     _______, _______,                             _______, \
        _______, _______,    _______,                                              _______,                                                           _______,     _______, _______, _______,           _______, _______, _______ \
    ),
    [_VIM_CHANGE] = LAYOUT(
        _______, _______, _______, _______,            _______,  _______, _______,            _______,            _______,          _______,  _______, _______, _______,           _______, _______, _______, \
        _______, _______, _______, _______,            _______,  _______, _______,            _______,            _______,          _______,  _______, _______, _______, _______,  _______, _______, _______, \
        _______, _______, _______, CUT_WORD_BACKWARDS, CUT_WORD, _______, _______,            _______,            CUT_TO_EOL,       _______,  _______, _______, _______, _______,  _______, _______, _______, \
        _______, CUT_ALL, _______, _______,            _______,  _______, CUT_WORD_BACKWARDS, CUT_TWO_LINES_DOWN, CUT_TWO_LINES_UP, CUT_WORD, _______, _______, _______,
        _______, _______, _______, CUT_LINE,           _______,  _______, CUT_TO_BOL,         _______,            _______,          _______,  _______, _______,                             _______, \
        _______, _______, _______,                                        _______,                                                  _______,  _______, _______, _______,           _______, _______, _______ \
    )
};



// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    key_event_counter = 0;    // Counter to determine if keys are being held, neutral at 0.
    rgb_enabled_flag = true;  // Initially, keyboard RGB is enabled. Change to false config.h initializes RGB disabled.
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

    // Increment key event counter for every press and decrement for every release.
    if (record->event.pressed) {
        key_event_counter++;
    } else {
        key_event_counter--;
    }

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
    }

    if (record->event.pressed) {
        switch (keycode) {
            // ======================================== CUSTOM KEYCODES BELOW ========================================
            case VIM_G:
                if( get_mods() && MOD_BIT(KC_LSFT)) {
                    unregister_code(KC_LSFT);
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_END) SS_UP(X_LCTL));
                } else {
                    tap_code16(C(KC_BSPC));
                }
                return false;
            case NEW_LINE:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Create new line above cursor
                    unregister_code(KC_LSFT);
                    SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_UP) SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_ENT));
                } else {
                    // Create new line below cursor
                    SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_ENT));
                }
                return false;

            /* -------------------------- VIM Yank -------------------------- */
            case VIM_Y:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Copy to the end of line
                    SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                    tap_code16(KC_LEFT);
                } else {
                    // Activate VIM Yank one shot layer
                    layer_on(_VIM_YANK);
                    set_oneshot_layer(_VIM_YANK, ONESHOT_START);
                }
                return false;
            case COPY_ALL:
                // Select all text and copy
                tap_code16(C(KC_A));
                tap_code16(C(KC_INS));
                layer_off(_VIM_YANK);
                return false;
            case COPY_WORD:
                // Select word, copy, deselect
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_RGHT) SS_UP(X_LSFT) "c" SS_UP(X_LCTL));
                tap_code16(KC_LEFT);
                layer_off(_VIM_YANK);
                return false;
            case COPY_WORD_BACKWARDS:
                // Select word backwards, copy, deselect
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LSFT) "c" SS_UP(X_LCTL));
                tap_code16(KC_RGHT);
                layer_off(_VIM_YANK);
                return false;

            case COPY_LINE:
                // Select whole line, copy, deselect
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                tap_code16(KC_RGHT);
                layer_off(_VIM_YANK);
                return false;
            case COPY_TO_EOL:
                // Select from cursor to the end of line, copy, deselect
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                tap_code16(KC_LEFT);
                layer_off(_VIM_YANK);
                return false;
            case COPY_TO_BOL:
                // Select from cursor to the beginning of line, copy, deselect
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                tap_code16(KC_RGHT);
                layer_off(_VIM_YANK);
                return false;
            case COPY_TWO_LINES_UP:
                // Copy current line and one up
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_UP) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                tap_code16(KC_LEFT);
                layer_off(_VIM_YANK);
                return false;
            case COPY_TWO_LINES_DOWN:
                // Copy current line and one down
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_DOWN) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                tap_code16(KC_RGHT);
                layer_off(_VIM_YANK);
                return false;
            /* -------------------------------------------------------------- */

            /* -------------------------- VIM Delete -------------------------- */
            case VIM_D:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Delete to the end of line
                    SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_DEL));
                } else {
                    // Activate VIM Delete one shot layer
                    layer_on(_VIM_DELETE);
                    set_oneshot_layer(_VIM_DELETE, ONESHOT_START);
                }
                return false;
            case DELETE_ALL:
                // Delete all text
                tap_code16(C(KC_A));
                tap_code16(KC_DEL);
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_WORD:
                // Delete word forward
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_RGHT) SS_UP(X_LSFT) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_WORD_BACKWARDS:
                // Delete word backwards
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_LINE:
                // Delete current line
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_SPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_RGHT));
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_TO_EOL:
                // Delete from cursor to the end of line
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_DEL));
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_TO_BOL:
                // Delete from cursor to the beginning of line
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DEL));
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_TWO_LINES_UP:
                // Delete current line and one up
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_UP) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT) SS_TAP(X_DEL) SS_TAP(X_DEL));
                layer_off(_VIM_DELETE);
                return false;
            case DELETE_TWO_LINES_DOWN:
                // Delete current line and one down
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_DOWN) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT) SS_TAP(X_DEL) SS_TAP(X_DEL));
                layer_off(_VIM_DELETE);
                return false;
            /* -------------------------------------------------------------- */

            /* -------------------------- VIM Change -------------------------- */
            case VIM_C:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Cut to the end of line
                    SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                } else {
                    // Activate VIM Delete one shot layer
                    layer_on(_VIM_CHANGE);
                    set_oneshot_layer(_VIM_CHANGE, ONESHOT_START);
                }
                return false;
            case CUT_ALL:
                // Copy and delete all text
                tap_code16(C(KC_A));
                tap_code16(C(KC_INS));
                tap_code16(KC_DEL);
                layer_off(_VIM_CHANGE);
                return false;
            case CUT_WORD:
                // Copy and delete word forward
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_RGHT) SS_UP(X_LSFT) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;
            case CUT_WORD_BACKWARDS:
                // Copy and delete word backwards
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LSFT) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;

            case CUT_LINE:
                // Copy and delete current line
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;
            case CUT_TO_EOL:
                // Copy and delete from cursor to the end of line
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;
            case CUT_TO_BOL:
                // Copy and delete from cursor to the beginning of line
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;
            case CUT_TWO_LINES_UP:
                // Copy and delete current line and one up
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_UP) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;
            case CUT_TWO_LINES_DOWN:
                // Copy and delete current line and one down
                SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_DOWN) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                layer_off(_VIM_CHANGE);
                return false;
            /* -------------------------------------------------------------- */
        }
    }

    /* Always cancel one-shot layer when another key gets pressed */
    if (key_event_counter != 0 && get_highest_layer(layer_state) == _VIM_YANK && keycode != VIM_Y) {
        layer_off(_VIM_YANK);
        layer_off(_FL);
        return false;
    } 
    if (key_event_counter != 0 && get_highest_layer(layer_state) == _VIM_DELETE && keycode != VIM_D) {
        layer_off(_VIM_DELETE);
        layer_off(_FL);
        return false;
    } 
    if (key_event_counter != 0 && get_highest_layer(layer_state) == _VIM_CHANGE && keycode != VIM_C) {
        layer_off(_VIM_CHANGE);
        layer_off(_FL);
        return false;
    } 
    /* ---------------------------------------------------------- */

    return true; //Process all other
}
