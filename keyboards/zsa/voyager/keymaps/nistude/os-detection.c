/*
 * OS Detection (https://docs.qmk.fm/features/os_detection)
 */
uint32_t custom_os_settings(uint32_t trigger_time, void *cb_arg) {
    os_variant_t host     = detected_host_os();
    uint16_t     retry_ms = 500;

    if (host == OS_MACOS || host == OS_IOS) {
        // CTL on PC is like GUI on Mac...
        keymap_config.swap_lctl_lgui = true;
        // ...but in some cases, both use GUI.
        keymap_config.swap_rctl_rgui = false;
        retry_ms                     = 0;
    }

    return retry_ms;
}

void keyboard_post_init_user(void) {
    defer_exec(100, custom_os_settings, NULL);
}
