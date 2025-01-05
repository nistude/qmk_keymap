/*
 * RGB Base Layer Indicator (https://docs.qmk.fm/features/rgb_matrix#rgb-matrix-effects)
 */
bool rgb_matrix_indicators_user(void) {
    if (get_highest_layer(default_layer_state) == BASE_1) {
        // change color of L_BASE0 / L_BASE1 keys
        rgb_matrix_set_color(26, RGB_GREEN);
    } else if (get_highest_layer(layer_state) == NAV) {
        // change color of L_NAV key
        rgb_matrix_set_color(27, RGB_GREEN);
    }

    return false; // don't run keyboard-level callback
}
