#ifndef XERVON_KEY_OVERRIDES
#define XERVON_KEY_OVERRIDES

const key_override_t kc_left_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, KC_HOME);
const key_override_t kc_down_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, KC_PGDN);
const key_override_t kc_up_override   = ko_make_basic(MOD_MASK_SHIFT, KC_UP,   KC_PGUP);
const key_override_t kc_rght_override = ko_make_basic(MOD_MASK_SHIFT, KC_RGHT, KC_END);

const key_override_t kc_spc_override  = ko_make_basic(MOD_MASK_SHIFT, KC_SPC,  KC_BSPC);

const key_override_t kc_grv_override  = ko_make_basic(MOD_MASK_SHIFT, KC_GRV,  KC_NO);
const key_override_t kc_slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_NO);
const key_override_t kc_bsls_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_NO);

const key_override_t kc_dot_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_COLON);
const key_override_t kc_comm_override = { .trigger = KC_COMM,
                                          .trigger_mods = MOD_MASK_SHIFT,
                                          .layers = ~0,
                                          .negative_mod_mask = 0,
                                          .suppressed_mods = MOD_MASK_SHIFT,
                                          .replacement = KC_SCOLON,
                                          .options = ko_options_default,
                                          .custom_action = NULL,
                                          .context = NULL,
                                          .enabled = NULL };

const key_override_t kc_volu_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_MUTE);
const key_override_t kc_vold_override = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_MUTE);
const key_override_t kc_mnxt_override = ko_make_basic(MOD_MASK_SHIFT, KC_MNXT, KC_MPLY);

const key_override_t **key_overrides  = (const key_override_t *[]){
    &kc_left_override,
    &kc_down_override,
    &kc_up_override,
    &kc_rght_override,

    &kc_spc_override,

    &kc_grv_override,
    &kc_slsh_override,
    &kc_bsls_override,

    &kc_dot_override,
    &kc_comm_override,

    &kc_volu_override,
    &kc_vold_override,
    &kc_mnxt_override,

    NULL
};

#endif
