/*
 * MAGIC and (Alternate) Repeat Key (https://docs.qmk.fm/features/repeat_key)
 */

// An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// held while sending the string. Additionally, the last key is set such that if
// the Repeat Key is pressed next, it produces `repeat_keycode`.
// https://github.com/getreuer/qmk-keymap/blob/7e0b11809ba920a3cf7353d02c5565f3a8e4d4f7/getreuer.c#L502
#define MAGIC_STRING(str, repeat_keycode) magic_send_string_P(PSTR(str), (repeat_keycode))

static void magic_send_string_P(const char *str, uint16_t repeat_keycode) {
    uint8_t saved_mods = 0;

    // If Caps Word is on, save the mods and hold Shift.
    if (is_caps_word_on()) {
        saved_mods = get_mods();
        register_mods(MOD_BIT(KC_LSFT));
    }

    send_string_with_delay_P(str, TAP_CODE_DELAY);
    set_last_keycode(repeat_keycode);

    // If Caps Word is on, restore the mods.
    if (is_caps_word_on()) {
        set_mods(saved_mods);
    }
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if ((mods & MOD_MASK_CTRL)) { // Was Ctrl held?
        switch (keycode) {
            case KC_A:
                return C(KC_C); // Copy after select all.
        }
    } else if ((mods & ~MOD_MASK_SHIFT) == 0) { // Was no modifier other than Shift held?
        switch (keycode) {
            // Shortcuts and macros
            case LNGR_A:
                return M_AND; // A -> ND
            case KC_D:
                return M_DER; // D -> ER
            case LNGR_DOT:
                return KC_SLASH; // . -> /
            case LNGR_GRAVE:
                return M_CODEB; // ` -> ``<cursor>```
            case I_CTL:
                return M_ING; // I -> NG
            case KC_LBRC:
                if (mods & MOD_MASK_SHIFT) {
                    return M_CURLY_BRACES; // { -> <cursor>}
                }
                return M_BRACKETS; // [ -> <cursor>]
            case LNGR_PAREN:
                return M_PAREN; // ( -> <cursor>)
            case LNGR_S:
                return M_SCH; // S -> CH
            case T_CTL:
                return M_THE; // T -> HE
            case KC_Y:
                return M_YOU; // Y -> OU
            // Single Finger Bigrams (sfb)
            case KC_J:
                return KC_U; // J -> U (just)
            case KC_P:
                return KC_A; // P -> A
        }
    }

    // Repeat unknown keys with mods applied.
    if (mods & MOD_MASK_CTRL) {
        if (mods & MOD_MASK_SHIFT) {
            if (mods & MOD_MASK_ALT) {
                return C(S(A(keycode)));
            }
            return C(S(keycode));
        } else if (mods & MOD_MASK_ALT) {
            return C(A(keycode));
        }
        return C(keycode);
    } else if (mods & MOD_MASK_SHIFT) {
        if (mods & MOD_MASK_ALT) {
            return S(A(keycode));
        }
        return S(keycode);
    } else if (mods & MOD_MASK_ALT) {
        return A(keycode);
    }

    return keycode;
}
