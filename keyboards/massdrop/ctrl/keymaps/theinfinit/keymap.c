#include "keymap.h"
#include "keymap_extras/keymap_polish.h"

static uint8_t key_event_counter;       // This counter is used to check if any keys are being held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KL] = LAYOUT(
        KC_ESC,  KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5, KC_F6, KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,          KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,  KC_6,  KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,         KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,  KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,            KC_QUOT,         KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN, \
        MO(_FL), LALT_T(KC_A), LSFT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G,  KC_H,  RGUI_T(KC_J), RCTL_T(KC_K), RSFT_T(KC_L), RALT_T(KC_SCLN), LT(_NSL,KC_ENT), KC_ENT, \
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,  KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ESC,                                      KC_UP, \
        KC_LCTL, KC_LGUI,      MO(_SL),                                  KC_SPC,                                   MO(_NL),      MO(_ML),         KC_APP,          KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5, KC_F6, KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,           KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,         KC_2,         KC_3,         KC_4,         KC_5,  KC_6,  KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,          KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,  KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC,          KC_RBRC, KC_BSLS,  KC_DEL,  KC_END,  KC_PGDN, \
        MO(_FL), KC_A, KC_S, KC_D, KC_F, KC_G,  KC_H,  KC_J, KC_K, KC_L, KC_SCLN, LT(_NSL,KC_QUOT), KC_ENT, \
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,  KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ESC,                                       KC_UP, \
        KC_LCTL, KC_LGUI,      MO(_SL),                                  KC_SPC,                                   MO(_NL),      MO(_ML),         KC_APP,           KC_RCTL,           KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_ML] = LAYOUT(
        _______, KL,       QWERTY,  _______, _______,  _______,  _______, _______, _______,   _______, _______, _______, _______,          KC_PSCR, _______, _______, \
        _______, RGB_M_P,  RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,   RGB_M_T, _______, _______, _______, _______, KC_MNXT, KC_MUTE, KC_VOLU, \
        BL_BRTG, RGB_SPD,  RGB_VAI, RGB_SPI, RGB_HUI,  RGB_SAI,  _______, U_T_AUTO, U_T_AGCR, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_VOLD, \
        _______, RGB_RMOD, RGB_VAD, RGB_MOD, RGB_HUD,  RGB_SAD,  _______, _______, _______,   _______, _______, _______, _______, \
        _______, RGB_TOG,  BL_TOGG, BL_STEP, _______,  QK_BOOT,    NK_TOGG, _______, _______,   _______, _______,                                     _______, \
        _______, _______,  _______, _______, _______,  _______,  _______, _______, _______,                                                _______, _______, _______ \
    ),
    [_NL] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        LALT(KC_TAB), KC_F1,      KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______, _______, \
        _______,      KC_1,       KC_2,         KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
        _______,      _______,    _______,      _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [_SL] = LAYOUT(
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      _______,    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        LALT(KC_TAB), KC_F1,      KC_F2,        KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, _______, _______, \
        _______,      LALT(KC_A), LSFT_T(KC_S), KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,  KC_TILD, _______, \
        _______,      _______,    _______,      _______, KC_UNDS, _______, KC_EQL,  KC_LCBR, KC_RCBR, _______, _______, _______,                             _______, \
        _______,      _______,    _______,                                 _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [_NSL] = LAYOUT(
        _______,      _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, \
        _______,      _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        LALT(KC_TAB), _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
        _______,      KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, _______, _______, _______, \
        _______,      _______, _______,  KC_UNDS, _______, _______, KC_EQL,  KC_LBRC, KC_RBRC, _______, _______, _______,                             _______, \
        _______,      _______, _______,                             _______,                   _______, _______, _______, _______,           _______, _______, _______ \
    ),
    [_FL] = LAYOUT(
        _______, _______,        _______,      _______,       _______,       _______,       _______, _______,    _______, _______,  _______,      _______,  _______,             _______, _______, _______, \
        KC_TILD, KC_EXLM,        KC_AT,        KC_HASH,       KC_DLR,        KC_PERC,       KC_CIRC, KC_AMPR,    KC_ASTR, KC_LPRN,  KC_RPRN,      KC_UNDS,  KC_PLUS, _______,    _______, _______, _______, \
        _______, _______,        KC_PGDN,      LCTL(KC_LEFT), LCTL(KC_RGHT), KC_PGUP,       YANK,    LCTL(KC_Z), KC_HOME, KC_END,   LSFT(KC_INS), _______,  _______, _______,    _______, _______, _______, \
        _______, LALT_T(KC_INS), LSFT_T(KC_S), KC_DEL,        KC_BSPC,       LCTL(KC_BSPC), KC_LEFT, KC_DOWN,    KC_UP,   KC_RGHT,  KC_ENT,       NEW_LINE, _______, \
        _______, _______,        LCTL(KC_X),   COPY_CUT,      LSFT(KC_INS),  _______,       _______, _______,    _______, _______,  _______,      _______,                                _______, \
        _______, _______,        _______,                                                   _______,                      _______,  _______,      _______,  _______,             _______, _______, _______ \
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
            case KL:
                if (record->event.pressed) {
                    set_single_persistent_default_layer(_KL);
                }
                return false;
                break;
            case QWERTY:
                if (record->event.pressed) {
                    set_single_persistent_default_layer(_QWERTY);
                }
                return false;
                break;
    }

    if (record->event.pressed) {
        switch (keycode) {
            // ======================================== CUSTOM KEYCODES BELOW ========================================
            case NEW_LINE:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Create new line above cursor
                    unregister_code(KC_LSFT);
                    SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_ENT) SS_TAP(X_UP));
                } else {
                    // Create new line below cursor
                    SEND_STRING(SS_TAP(X_END) SS_TAP(X_END) SS_TAP(X_ENT));
                }
                return false;
                break;

            /* -------------------------- VIM Yank -------------------------- */
            case YANK:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Copy to the end of line
                    SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                    tap_code16(KC_LEFT);
                } else {
                    // Ctrl + Ins (Copy)
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                }
                return false;

            /* -------------------------- VIM Change -------------------------- */
            case COPY_CUT:
                if( get_mods() && MOD_BIT(KC_LSFT) ) {
                    // Cut current line
                    unregister_code(KC_LSFT);
                    SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSFT) SS_TAP(X_END) SS_TAP(X_END) SS_UP(X_LSFT));
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL) SS_TAP(X_DEL));
                } else {
                    // Ctrl + C (Copy)
                    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_INS) SS_UP(X_LCTL));
                }
                return false;
        }
    }

    return true; //Process all other
}

// ----------------------------------- COMBOS ----------------------------------

enum combo_events {
    MY_COMBO_SIE, // się        │
    MY_COMBO_ZE,  // że         │
    MY_COMBO_NI,  // nie        │ Nie
    MY_COMBO_JE,  // jest       │ Jest  ...em
    MY_COMBO_JK,  // jak        │ Jak
    MY_COMBO_PA,  // pan        │ Pan
    MY_COMBO_CI,  // Cię        │ cię
    MY_COMBO_BA,  // bardzo     │ Bardzo
    MY_COMBO_SER, // serdecznie │ Serdecznie
    MY_COMBO_TM,  // tym        │ Tym
    MY_COMBO_CB,  // Ciebie     │ ciebie
    MY_COMBO_AL,  // ale        │ Ale
    MY_COMBO_PZ,  // pozdrawiam │ Pozdrawiam
    MY_COMBO_BG,  // Bóg        │ bóg
    MY_COMBO_NAS, // nas        │ Nas
    MY_COMBO_JW,  // jw.org     │ JW.ORG
    MY_COMBO_CZ,  // czy        │ Czy
    MY_COMBO_DL,  // dla        │ Dla
    MY_COMBO_TA,  // tak        │ Tak
    MY_COMBO_KT,  // któr...    │ y, ych, e, a, ą 
    MY_COMBO_BE,  // będzie     │ Będzie
    MY_COMBO_MN,  // mnie       │ Mnie
    MY_COMBO_NDZ, // nadziej... │ Nadziej... a, ę, ą
    MY_COMBO_JU,  // już        │ Już
    MY_COMBO_ROW, // również    │ Również
    MY_COMBO_JEZ, // Jezus      │
    MY_COMBO_WI,  // Witam      │ witam
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM combo_SIE[] = { LSFT_T(KC_S), KC_I, KC_E, COMBO_END };
const uint16_t PROGMEM combo_ZE[] = { KC_Z, KC_E, COMBO_END };
const uint16_t PROGMEM combo_NI[] = { KC_N, KC_I, COMBO_END };
const uint16_t PROGMEM combo_JE[] = { RGUI_T(KC_J), KC_E, COMBO_END };
const uint16_t PROGMEM combo_JK[] = { RGUI_T(KC_J), RCTL_T(KC_K), COMBO_END };
const uint16_t PROGMEM combo_PA[] = { KC_P, LALT_T(KC_A), COMBO_END };
const uint16_t PROGMEM combo_CI[] = { KC_C, KC_I, COMBO_END };
const uint16_t PROGMEM combo_BA[] = { KC_B, LALT_T(KC_A), COMBO_END };
const uint16_t PROGMEM combo_SER[] = { LSFT_T(KC_S), KC_E, KC_R, COMBO_END };
const uint16_t PROGMEM combo_TM[] = { KC_T, KC_M, COMBO_END };
const uint16_t PROGMEM combo_CB[] = { KC_C, KC_B, COMBO_END };
const uint16_t PROGMEM combo_AL[] = { LALT_T(KC_A), RSFT_T(KC_L), COMBO_END };
const uint16_t PROGMEM combo_PZ[] = { KC_P, KC_Z, COMBO_END };
const uint16_t PROGMEM combo_BG[] = { KC_B, KC_G, COMBO_END };
const uint16_t PROGMEM combo_NAS[] = { KC_N, LALT_T(KC_A), LSFT_T(KC_S), COMBO_END };
const uint16_t PROGMEM combo_JW[] = { RGUI_T(KC_J), KC_W, COMBO_END };
const uint16_t PROGMEM combo_CZ[] = { KC_C, KC_Z, COMBO_END };
const uint16_t PROGMEM combo_DL[] = { LCTL_T(KC_D), RSFT_T(KC_L), COMBO_END };
const uint16_t PROGMEM combo_TA[] = { KC_T, LALT_T(KC_A), COMBO_END };
const uint16_t PROGMEM combo_KT[] = { RCTL_T(KC_K), KC_T, COMBO_END };
const uint16_t PROGMEM combo_BE[] = { KC_B, KC_E, COMBO_END };
const uint16_t PROGMEM combo_MN[] = { KC_M, KC_N, COMBO_END };
const uint16_t PROGMEM combo_NDZ[] = { KC_N, LCTL_T(KC_D), KC_Z, COMBO_END };
const uint16_t PROGMEM combo_JU[] = { RGUI_T(KC_J), KC_U, COMBO_END };
const uint16_t PROGMEM combo_ROW[] = { KC_R, KC_O, KC_W, COMBO_END };
const uint16_t PROGMEM combo_JEZ[] = { RGUI_T(KC_J), KC_E, KC_Z, COMBO_END };

const uint16_t PROGMEM combo_WI[] = { KC_W, KC_I, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    [MY_COMBO_SIE] = COMBO_ACTION(combo_SIE),
    [MY_COMBO_ZE] = COMBO_ACTION(combo_ZE),
    [MY_COMBO_NI] = COMBO_ACTION(combo_NI),
    [MY_COMBO_JE] = COMBO_ACTION(combo_JE),
    [MY_COMBO_JK] = COMBO_ACTION(combo_JK),
    [MY_COMBO_PA] = COMBO_ACTION(combo_PA),
    [MY_COMBO_CI] = COMBO_ACTION(combo_CI),
    [MY_COMBO_BA] = COMBO_ACTION(combo_BA),
    [MY_COMBO_SER] = COMBO_ACTION(combo_SER),
    [MY_COMBO_TM] = COMBO_ACTION(combo_TM),
    [MY_COMBO_CB] = COMBO_ACTION(combo_CB),
    [MY_COMBO_AL] = COMBO_ACTION(combo_AL),
    [MY_COMBO_PZ] = COMBO_ACTION(combo_PZ),
    [MY_COMBO_BG] = COMBO_ACTION(combo_BG),
    [MY_COMBO_NAS] = COMBO_ACTION(combo_NAS),
    [MY_COMBO_JW] = COMBO_ACTION(combo_JW),
    [MY_COMBO_CZ] = COMBO_ACTION(combo_CZ),
    [MY_COMBO_DL] = COMBO_ACTION(combo_DL),
    [MY_COMBO_TA] = COMBO_ACTION(combo_TA),
    [MY_COMBO_KT] = COMBO_ACTION(combo_KT),
    [MY_COMBO_BE] = COMBO_ACTION(combo_BE),
    [MY_COMBO_MN] = COMBO_ACTION(combo_MN),
    [MY_COMBO_NDZ] = COMBO_ACTION(combo_NDZ),
    [MY_COMBO_JU] = COMBO_ACTION(combo_JU),
    [MY_COMBO_ROW] = COMBO_ACTION(combo_ROW),
    [MY_COMBO_JEZ] = COMBO_ACTION(combo_JEZ),

    [MY_COMBO_WI] = COMBO_ACTION(combo_WI),
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
        case MY_COMBO_SIE:
            if (pressed) {
                SEND_STRING("si");
                tap_code16(PL_EOGO);
            }
            break;
        case MY_COMBO_ZE:
            if (pressed) {
                tap_code16(PL_ZDOT);
                SEND_STRING("e");
            }
            break;
        case MY_COMBO_NI:
            if (pressed) {
                SEND_CAP_STRING("nie", "Nie");
            }
            break;
        case MY_COMBO_JE:
            if (pressed) {
                SEND_CAP_STRING("jest", "Jest");
            }
            break;
        case MY_COMBO_JK:
            if (pressed) {
                SEND_CAP_STRING("jak", "Jak");
            }
            break;
        case MY_COMBO_PA:
            if (pressed) {
                SEND_CAP_STRING("pan", "Pan");
            }
            break;
        case MY_COMBO_CI:
            if (pressed) {
                if (COMBO_MODS_SHIFT) { \
                        clear_mods(); \
                        SEND_STRING("ci"); \
                        tap_code16(PL_EOGO);
                    } else { \
                        SEND_STRING("Ci"); \
                        tap_code16(PL_EOGO);
                    }
            }
            break;
        case MY_COMBO_BA:
            if (pressed) {
                SEND_CAP_STRING("bardzo", "Bardzo");
            }
            break;
        case MY_COMBO_SER:
            if (pressed) {
                SEND_CAP_STRING("serdecznie", "Serdecznie");
            }
            break;
        case MY_COMBO_TM:
            if (pressed) {
                SEND_CAP_STRING("tym", "Tym");
            }
            break;
        case MY_COMBO_CB:
            if (pressed) {
                SEND_CAP_STRING("Ciebie", "ciebie");
            }
            break;
        case MY_COMBO_AL:
            if (pressed) {
                SEND_CAP_STRING("ale", "Ale");
            }
            break;
        case MY_COMBO_PZ:
            if (pressed) {
                SEND_CAP_STRING("pozdrawiam", "Pozdrawiam");
            }
            break;
        case MY_COMBO_BG:
            if (pressed) {
                if (COMBO_MODS_SHIFT) { \
                        clear_mods(); \
                        SEND_STRING("b"); \
                        tap_code16(PL_OACU); \
                        SEND_STRING("g");
                    } else { \
                        SEND_STRING("B"); \
                        tap_code16(PL_OACU); \
                        SEND_STRING("g");
                    }
            }
            break;
        case MY_COMBO_NAS:
            if (pressed) {
                SEND_CAP_STRING("nas", "Nas");
            }
            break;
        case MY_COMBO_JW:
            if (pressed) {
                SEND_CAP_STRING("jw.org", "JW.ORG");
            }
            break;
        case MY_COMBO_CZ:
            if (pressed) {
                SEND_CAP_STRING("czy", "Czy");
            }
            break;
        case MY_COMBO_DL:
            if (pressed) {
                SEND_CAP_STRING("dla", "Dla");
            }
            break;
        case MY_COMBO_TA:
            if (pressed) {
                SEND_CAP_STRING("tak", "Tak");
            }
            break;
        case MY_COMBO_KT:
            if (pressed) {
                if (COMBO_MODS_SHIFT) { \
                        clear_mods(); \
                        SEND_STRING("Kt"); \
                        tap_code16(PL_OACU); \
                        SEND_STRING("r");
                    } else { \
                        SEND_STRING("kt"); \
                        tap_code16(PL_OACU); \
                        SEND_STRING("r");
                    }
            }
            break;
        case MY_COMBO_BE:
            if (pressed) {
                if (COMBO_MODS_SHIFT) { \
                        clear_mods(); \
                        SEND_STRING("B"); \
                        tap_code16(PL_EOGO); \
                        SEND_STRING("dzie");
                    } else { \
                        SEND_STRING("b"); \
                        tap_code16(PL_EOGO); \
                        SEND_STRING("dzie");
                    }
            }
            break;
        case MY_COMBO_MN:
            if (pressed) {
                SEND_CAP_STRING("mnie", "Mnie");
            }
            break;
        case MY_COMBO_NDZ:
            if (pressed) {
                SEND_CAP_STRING("nadziej", "Nadziej");
            }
            break;
        case MY_COMBO_JU:
            if (pressed) {
                if (COMBO_MODS_SHIFT) { \
                        clear_mods(); \
                        SEND_STRING("Ju"); \
                        tap_code16(PL_ZDOT);
                    } else { \
                        SEND_STRING("ju"); \
                        tap_code16(PL_ZDOT);
                    }
            }
            break;
        case MY_COMBO_ROW:
            if (pressed) {
                if (COMBO_MODS_SHIFT) { \
                        clear_mods(); \
                        SEND_STRING("R"); \
                        tap_code16(PL_OACU); \
                        SEND_STRING("wnie"); \
                        tap_code16(PL_ZDOT);
                    } else { \
                        SEND_STRING("r"); \
                        tap_code16(PL_OACU); \
                        SEND_STRING("wnie"); \
                        tap_code16(PL_ZDOT);
                    }
            }
            break;
        case MY_COMBO_JEZ:
            if (pressed) {
                SEND_STRING("Jezus");
            }
            break;

        case MY_COMBO_WI:
            if (pressed) {
                SEND_CAP_STRING("Witam", "witam");
            }
            break;
    }
}
