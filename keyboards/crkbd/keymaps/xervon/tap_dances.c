#ifndef XERVON_TAP_DANCES
#define XERVON_TAP_DANCES

enum {
	TD_XESC,
	TD_JESC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_XESC] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_ESC),
	[TD_JESC] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_ESC),
};

#endif
