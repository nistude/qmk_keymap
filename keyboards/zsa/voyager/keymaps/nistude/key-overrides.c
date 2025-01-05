/*
 * Key Overrides / Custom Shift (https://docs.qmk.fm/features/key_overrides)
 */
const key_override_t shft_bspc_del_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &shft_bspc_del_override,
};
