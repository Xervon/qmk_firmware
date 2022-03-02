#ifndef XERVON_TAP_DANCES
#define XERVON_TAP_DANCES

enum {
	TD_QUOTESC_INT,
	TD_VESC_INT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_QUOTESC_INT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_ESC),
	[TD_VESC_INT]    = ACTION_TAP_DANCE_DOUBLE(KC_V,    KC_ESC),
};

#define TD_QUOTESC TD(TD_QUOTESC_INT)
#define TD_VESC    TD(TD_VESC_INT)

#endif
