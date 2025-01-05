enum layers {
    BASE_0,
    BASE_1,
    NAV,
    NUM,
    SYM,
};

enum custom_keycodes {
    M_AND = SAFE_RANGE,
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
    TAB_ADDR,
    TAB_FIND,
    TAB_NEW,
};

// simplified tap - hold actions / linger keys
// https://docs.qmk.fm/mod_tap#changing-hold-function
#define LNGR_A      LT(0, KC_A)
#define LNGR_O      LT(0, KC_O)
#define LNGR_Q      LT(0, KC_Q)
#define LNGR_S      LT(0, KC_S)
#define LNGR_U      LT(0, KC_U)
#define LNGR_COMMA  LT(0, KC_COMMA)
#define LNGR_DOT    LT(0, KC_DOT)
#define LNGR_EXLM   LT(0, KC_EXLM)
#define LNGR_GRAVE  LT(0, KC_GRAVE)
#define LNGR_LTGT   LT(0, KC_F1) // using F1 to resolve conflict with LNGR_COMMA
#define LNGR_MINUS  LT(0, KC_MINUS)
#define LNGR_PAREN  LT(0, KC_LPRN)
#define LNGR_QUOTE  LT(0, KC_QUOTE)
#define LNGR_LARR   LT(0, KC_NO)
#define LNGR_RARR   LT(0, KC_NO)

// Layer switches
#define L_BASE0     DF(BASE_0)
#define L_BASE1     DF(BASE_1)
#define L_NAV       TG(NAV)
#define GUI_NAV     LT(NAV, KC_NO)
#define C_SYM       LT(SYM, KC_C)
#define H_SYM       LT(SYM, KC_H)
#define SPACE_NUM   LT(NUM, KC_SPACE)

#define MAGIC       QK_AREP
#define COMPOSE     KC_NUBS
#define SPTLGHT     C(KC_SPC)
#define OSM_LALT    OSM(MOD_LALT)
#define OSM_LCTL    OSM(MOD_LCTL)
#define OSM_LGUI    OSM(MOD_LGUI)
#define OSM_LSFT    OSM(MOD_LSFT)
#define OSM_RCTL    OSM(MOD_RCTL)
#define OSM_RGUI    OSM(MOD_RGUI)
#define OSM_RSFT    OSM(MOD_RSFT)

// Home row mods
#define T_CTL       LCTL_T(KC_T)
#define I_CTL       LCTL_T(KC_I)
#define N_ALT       LALT_T(KC_N)
#define E_ALT       LALT_T(KC_E)

// Browser controls
#define TAB_CLOSE   LCTL(KC_W)
#define TAB_LEFT    LCTL(LSFT(KC_TAB))
#define TAB_RIGHT   LCTL(KC_TAB)

#define VOL_UP      KC_VOLU
#define VOL_DOWN    KC_VOLD
