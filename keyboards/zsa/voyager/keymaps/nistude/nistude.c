/*
 * Custom keycodes for my Voyager
 */
enum custom_keycodes {
    TAB_ADDR = SAFE_RANGE,
    TAB_FIND,
    TAB_NEW,
    // Macros
    M_AND,
    M_BRACKETS,
    M_CURLY_BRACES,
    M_CODEB,
    M_DER,
    M_E_ACUTE,
    M_E_GRAVE,
    M_ING,
    M_PAREN,
    M_SCH,
    M_THE,
    M_YOU,
};

// simplified tap - hold actions / linger keys
// https://docs.qmk.fm/mod_tap#changing-hold-function
#define LNGR_A     LT(0, KC_A)
#define LNGR_O     LT(0, KC_O)
#define LNGR_Q     LT(0, KC_Q)
#define LNGR_S     LT(0, KC_S)
#define LNGR_U     LT(0, KC_U)
#define LNGR_COMMA LT(0, KC_COMMA)
#define LNGR_DOT   LT(0, KC_DOT)
#define LNGR_EXLM  LT(0, KC_EXCLAIM)
#define LNGR_GRAVE LT(0, KC_GRAVE)
#define LNGR_LTGT  LT(0, KC_F1) // using F1 to resolve conflict with LNGR_COMMA
#define LNGR_MINUS LT(0, KC_MINUS)
#define LNGR_PAREN LT(0, KC_LPRN)
#define LNGR_QUOTE LT(0, KC_QUOTE)
#define LNGR_LARR  LT(0, KC_F2)
#define LNGR_RARR  LT(0, KC_F3)

// Layer switches
#define L_BASE0    DF(BASE_0)
#define L_BASE1    DF(BASE_1)
#define L_NAV      TG(NAV)
#define GUI_NAV    LT(NAV, KC_NO)
#define C_SYM      LT(SYM, KC_C)
#define H_SYM      LT(SYM, KC_H)
#define SPACE_NUM  LT(NUM, KC_SPACE)

#define MAGIC      QK_AREP
#define COMPOSE    KC_NUBS
#define SPTLGHT    C(KC_SPC)
#define OSM_LALT   OSM(MOD_LALT)
#define OSM_LCTL   OSM(MOD_LCTL)
#define OSM_LGUI   OSM(MOD_LGUI)
#define OSM_LSFT   OSM(MOD_LSFT)
#define OSM_RCTL   OSM(MOD_RCTL)
#define OSM_RGUI   OSM(MOD_RGUI)
#define OSM_RSFT   OSM(MOD_RSFT)

// Home row mods
#define T_CTL      LCTL_T(KC_T)
#define I_CTL      LCTL_T(KC_I)
#define N_ALT      LALT_T(KC_N)
#define E_ALT      LALT_T(KC_E)

// Browser controls
#define TAB_CLOSE  LCTL(KC_W)
#define TAB_LEFT   LCTL(LSFT(KC_TAB))
#define TAB_RIGHT  LCTL(KC_TAB)

#define VOL_UP     KC_VOLU
#define VOL_DOWN   KC_VOLD

/*
 * Feature configuration
 */
#include "caps-word.c"
#include "combos.c"
#include "key-overrides.c"
#include "magic-repeat.c"
#include "os-detection.c"
#include "rgb-matrix.c"
#include "tap-hold.c"

/*
 * Process custom keycodes
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    // clang-format off
    uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
        keycode,
        is_combo ? 254 : record->event.key.row,
        is_combo ? 254 : record->event.key.col,
        get_highest_layer(layer_state),
        record->event.pressed,
        get_mods(),
        get_oneshot_mods(),
        record->tap.count
    );
    // clang-format on
#endif // CONSOLE_ENABLE

    const uint8_t mods       = get_mods();
    const uint8_t all_mods   = (mods | get_weak_mods() | get_oneshot_mods());
    const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
    // const bool alt = all_mods & MOD_BIT(KC_LALT);

    switch (keycode) {
        // activate _NAV layer with MOD_GUI and press TAB for window navigation
        case GUI_NAV:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_RGUI));
                tap_code16(KC_TAB);
                layer_on(NAV);
            } else {
                unregister_mods(MOD_MASK_GUI);
                layer_off(NAV);
            }
            return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            // tap: a, hold: ä
            case LNGR_A:
                if (!record->tap.count) {
                    if (shift_mods || is_caps_word_on()) {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_LSFT(SS_TAP(X_A)) SS_LSFT(SS_TAP(X_QUOTE)), TAP_CODE_DELAY);
                    } else {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_A) SS_LSFT(SS_TAP(X_QUOTE)), TAP_CODE_DELAY);
                    }
                    return false;
                }
                break;

            // tap: o, hold: ö
            case LNGR_O:
                if (!record->tap.count) {
                    if (shift_mods || is_caps_word_on()) {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_LSFT(SS_TAP(X_O)) SS_LSFT(SS_TAP(X_QUOTE)), TAP_CODE_DELAY);
                    } else {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_O) SS_LSFT(SS_TAP(X_QUOTE)), TAP_CODE_DELAY);
                    }
                    return false;
                }
                break;

            // tap: qu, hold: q
            case LNGR_Q:
                if (!record->tap.count) {
                    MAGIC_STRING(SS_TAP(X_Q), KC_NO);
                } else {
                    MAGIC_STRING(SS_TAP(X_Q) SS_TAP(X_U), KC_NO);
                }
                return false;

            // tap: s, hold: ß
            case LNGR_S:
                if (!record->tap.count) {
                    if (shift_mods || is_caps_word_on()) {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_LSFT(SS_TAP(X_S)) SS_LSFT(SS_TAP(X_S)), TAP_CODE_DELAY);
                    } else {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_S) SS_TAP(X_S), TAP_CODE_DELAY);
                    }
                    return false;
                }
                break;

            // tap: u, hold: ü
            case LNGR_U:
                if (!record->tap.count) {
                    if (shift_mods || is_caps_word_on()) {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_LSFT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_QUOTE)), TAP_CODE_DELAY);
                    } else {
                        SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_U) SS_LSFT(SS_TAP(X_QUOTE)), TAP_CODE_DELAY);
                    }
                    return false;
                }
                break;

            // tap: comma, hold: semicolon
            case LNGR_COMMA:
                if (!record->tap.count) {
                    tap_code16(KC_SEMICOLON);
                    return false;
                }
                break;

            // tap: dot, hold: colon
            case LNGR_DOT:
                if (!record->tap.count) {
                    tap_code16(KC_COLON);
                    return false;
                }
                break;

            // tap: !, hold: ?
            case LNGR_EXLM:
                if (!record->tap.count) {
                    tap_code16(KC_QUESTION);
                } else {
                    tap_code16(KC_EXCLAIM);
                }
                return false;

            // tap: grave, hold: tilde
            case LNGR_GRAVE:
                if (!record->tap.count) {
                    tap_code16(KC_TILDE);
                    return false;
                }
                break;

            // tap: <, hold: >
            case LNGR_LTGT:
                if (!record->tap.count) {
                    tap_code16(S(KC_DOT));
                } else {
                    tap_code16(S(KC_COMMA));
                }
                return false;

            // tap: -, hold: _
            case LNGR_MINUS:
                if (!record->tap.count) {
                    tap_code16(KC_UNDERSCORE);
                } else {
                    MAGIC_STRING(SS_TAP(X_MINUS), KC_NO);
                }
                return false;

            // tap: ", hold: '
            case LNGR_QUOTE:
                if (!record->tap.count) {
                    tap_code16(KC_QUOTE);
                } else {
                    tap_code16(S(KC_QUOTE));
                }
                return false;

            // tap: (, hold: )
            case LNGR_PAREN:
                if (!record->tap.count) {
                    tap_code16(S(KC_0));
                } else {
                    tap_code16(S(KC_9));
                }
                return false;

            // tap: ←, hold: ⇐
            case LNGR_LARR:
                if (!record->tap.count) {
                    SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_EQUAL) SS_LSFT(SS_TAP(X_COMMA)), TAP_CODE_DELAY);
                } else {
                    SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_MINUS), TAP_CODE_DELAY);
                }
                return false;

            // tap: →, hold: ⇒
            case LNGR_RARR:
                if (!record->tap.count) {
                    SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_EQUAL) SS_LSFT(SS_TAP(X_DOT)), TAP_CODE_DELAY);
                } else {
                    SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_MINUS) SS_LSFT(SS_TAP(X_DOT)), TAP_CODE_DELAY);
                }
                return false;

            // Macros
            case M_AND:
                MAGIC_STRING(/*a*/ "nd", KC_NO);
                break;
            case M_DER:
                MAGIC_STRING(/*d*/ "er", KC_NO);
                break;
            case M_ING:
                MAGIC_STRING(/*i*/ "ng", KC_NO);
                break;
            case M_SCH:
                MAGIC_STRING(/*s*/ "ch", KC_NO);
                break;
            case M_THE:
                MAGIC_STRING(/*t*/ "he", KC_NO);
                break;
            case M_YOU:
                MAGIC_STRING(/*y*/ "ou", KC_NO);
                break;
            case M_BRACKETS:
                SEND_STRING_DELAY(/*[*/ "]" SS_TAP(X_LEFT), TAP_CODE_DELAY);
                break;
            case M_CURLY_BRACES:
                SEND_STRING_DELAY(/*{*/ "}" SS_TAP(X_LEFT), TAP_CODE_DELAY);
                break;
            case M_CODEB:
                SEND_STRING_DELAY(/*`*/ "``\n```" SS_TAP(X_UP), TAP_CODE_DELAY);
                break;
            case M_E_ACUTE:
                SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_E) SS_TAP(X_QUOTE), TAP_CODE_DELAY);
                break;
            case M_E_GRAVE:
                SEND_STRING_DELAY(SS_TAP(X_NONUS_BACKSLASH) SS_TAP(X_E) SS_TAP(X_GRAVE), TAP_CODE_DELAY);
                break;
            case M_PAREN:
                SEND_STRING_DELAY(/*(*/ ")" SS_TAP(X_LEFT), TAP_CODE_DELAY);
                break;

            // navigation shortcuts
            case TAB_ADDR:
                // switch to address bar and activate write base layer
                tap_code16(C(KC_L));
                default_layer_set(BASE_0);
                return false;
            case TAB_FIND:
                // switch to find bar and activate write base layer
                tap_code16(C(KC_F));
                default_layer_set(BASE_0);
                return false;
            case TAB_NEW:
                // open new tab and activate write base layer
                tap_code16(C(KC_T));
                default_layer_set(BASE_0);
                return false;
        }
    }

    return true;
}
