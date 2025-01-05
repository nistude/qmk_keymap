/*
 * CAPS_WORD (https://docs.qmk.fm/features/caps_word)
 */
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case M_AND ... M_YOU:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_UNDERSCORE:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
