/*
 * Combos (https://docs.qmk.fm/features/combo)
 */
const uint16_t PROGMEM e_u_combo[] = {E_ALT, LNGR_U, COMBO_END};
const uint16_t PROGMEM e_p_combo[] = {E_ALT, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(e_u_combo, M_E_GRAVE),
    COMBO(e_p_combo, M_E_ACUTE),
};
