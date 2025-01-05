/*
 * Tap-hold (https://docs.qmk.fm/tap_hold)
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNGR_A:
        case LNGR_O:
        case LNGR_S:
        case LNGR_U:
        case OSM_LSFT: // must be left shift to activate CAPS_WORD
        case SPACE_NUM:
            /* fall through */
            return 250; // ms
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    // If you quickly hold a tap-hold key after tapping it, the tap action is
    // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    // lead to missed triggers in fast typing. Here, returning 0 means we
    // instead want to "force hold" and disable key repeating.
    // See: https://precondition.github.io/home-row-mods
    switch (keycode) {
        case N_ALT:
            return QUICK_TAP_TERM; // Enable key repeating.
        default:
            return 0; // Otherwise, force hold and disable key repeating.
    }
}
