#ifndef XERVON_KEY_OVERRIDES
#define XERVON_KEY_OVERRIDES

const key_override_t s_kc_spc_tab_override  = ko_make_basic(MOD_MASK_SHIFT, KC_SPC,  KC_TAB);
const key_override_t s_kc_spc_bspc_override = ko_make_basic(MOD_MASK_ALT, KC_SPC,  KC_BSPC);

const key_override_t s_kc_grv_override  = ko_make_basic(MOD_MASK_SHIFT, KC_GRV,  KC_NO);

const key_override_t s_kc_dot_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_COLON);
const key_override_t s_kc_comm_override = { .trigger = KC_COMM,
                                            .trigger_mods = MOD_MASK_SHIFT,
                                            .layers = ~0,
                                            .negative_mod_mask = 0,
                                            .suppressed_mods = MOD_MASK_SHIFT,
                                            .replacement = KC_SCOLON,
                                            .options = ko_options_default,
                                            .custom_action = NULL,
                                            .context = NULL,
                                            .enabled = NULL };

const key_override_t s_kc_ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES,  KC_EXLM);
const key_override_t s_kc_slsh_override = { .trigger = KC_SLSH,
                                            .trigger_mods = MOD_MASK_SHIFT,
                                            .layers = ~0,
                                            .negative_mod_mask = 0,
                                            .suppressed_mods = MOD_MASK_SHIFT,
                                            .replacement = KC_BSLS,
                                            .options = ko_options_default,
                                            .custom_action = NULL,
                                            .context = NULL,
                                            .enabled = NULL };

const key_override_t s_kc_volu_override = ko_make_basic(MOD_MASK_SHIFT, HM_VOLU, KC_MUTE);
const key_override_t s_kc_vold_override = ko_make_basic(MOD_MASK_SHIFT, HM_VOLD, KC_MUTE);
const key_override_t s_kc_mnxt_override = ko_make_basic(MOD_MASK_SHIFT, HM_MNXT, KC_MPLY);

const key_override_t **key_overrides  = (const key_override_t *[]){
    &s_kc_spc_tab_override,
    &s_kc_spc_bspc_override,

    &s_kc_grv_override,

    &s_kc_dot_override,
    &s_kc_comm_override,

    &s_kc_ques_override,
    &s_kc_slsh_override,

    &s_kc_volu_override,
    &s_kc_vold_override,
    &s_kc_mnxt_override,

    NULL
};

#endif
