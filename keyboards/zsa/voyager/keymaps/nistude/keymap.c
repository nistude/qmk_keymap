// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "nistude.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_0] = LAYOUT(
        KC_ESC,  _______, SPTLGHT,  GUI_NAV, _______,   _______,            L_BASE1,  L_NAV,  COMPOSE,    _______,  _______,    KC_PSCR,
        KC_BSLS, KC_V,    KC_G,     KC_L,    MAGIC,     LNGR_Q,             KC_BSPC,  LNGR_U, LNGR_O,     KC_P,     KC_Z,       KC_SLASH,
        KC_TAB,  C_SYM,   LNGR_S,   N_ALT,   T_CTL,     KC_M,               KC_K,     I_CTL,  E_ALT,      LNGR_A,   H_SYM,      KC_ENTER,
        KC_PIPE, KC_X,    KC_F,     KC_W,    KC_D,      KC_B,               KC_J,     KC_Y,   LNGR_COMMA, LNGR_DOT, LNGR_QUOTE, LNGR_MINUS,
                                             SPACE_NUM, OSL(NAV),           OSM_LSFT, KC_R
    ),
    [BASE_1] = LAYOUT(
        _______, _______, _______,  GUI_NAV,  _______,   QK_BOOT,           L_BASE0,  _______, _______, _______,  _______, _______,
        _______, _______, _______,  _______,  TAB_ADDR,  _______,           _______,  KC_PGUP, KC_UP,   KC_PGDN,  _______, _______,
        _______, _______, TAB_FIND, TAB_LEFT, TAB_RIGHT, TAB_NEW,           KC_HOME,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  _______,
        _______, _______, _______,  _______,  TAB_CLOSE, _______,           _______,  _______, _______, _______,  _______, _______,
                                              _______,   _______,           OSM_LSFT, _______
    ),
    [NAV] = LAYOUT(
        _______, _______,  _______,  _______,  _______,  _______,           _______, L_NAV,   _______, _______,  _______, _______,
        _______, _______,  _______,  _______,  _______,  _______,           KC_TRNS, KC_PGUP, KC_UP,   KC_PGDN,  _______, _______,
        _______, _______,  OSM_LGUI, OSM_LALT, OSM_LCTL, _______,           KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  _______,
        _______, _______,  _______,  _______,  _______,  _______,           _______, _______, _______, _______,  _______, _______,
                                               _______,  XXXXXXX,           KC_TRNS, _______
    ),
    [NUM] = LAYOUT(
        _______, _______,  _______,  _______,  _______,  _______,           QK_LLCK,  _______, KC_TRNS, _______, _______, _______,
        _______, _______,  _______,  _______,  _______,  _______,           KC_TRNS,  KC_7,    KC_8,    KC_9,    KC_ASTR, KC_SLASH,
        _______, _______,  OSM_LGUI, OSM_LALT, OSM_LCTL, _______,           KC_CIRC,  KC_1,    KC_2,    KC_3,    KC_PLUS, KC_MINUS,
        _______, _______,  _______,  _______,  _______,  _______,           KC_COMMA, KC_4,    KC_5,    KC_6,    KC_DOT,  KC_EQUAL,
                                               XXXXXXX,  _______,           KC_TRNS,  KC_0
    ),
    [SYM] = LAYOUT(
        _______, _______,  KC_BRID,  _______,  KC_BRIU,  _______,           QK_LLCK,    _______,    KC_TRNS,   _______, _______, _______,
        _______, _______,  VOL_DOWN, KC_MUTE,  VOL_UP,   _______,           KC_TRNS,    LNGR_PAREN, LNGR_EXLM, KC_AT,   KC_PERC, _______,
        _______, XXXXXXX,  OSM_LGUI, OSM_LALT, OSM_LCTL, _______,           LNGR_GRAVE, KC_LBRC,    KC_RBRC,   KC_HASH, KC_DLR,  KC_AMPR,
        _______, _______,  _______,  _______,  _______,  _______,           LNGR_LARR,  LNGR_LTGT,  _______,   _______, _______, LNGR_RARR,
                                               _______,  _______,           KC_TRNS,    _______
    ),
};
