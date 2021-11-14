#ifndef XERVON_COMBOS
#define XERVON_COMBOS

const uint16_t PROGMEM esc_combo_xj[] = {KC_X, KC_J, COMBO_END};
const uint16_t PROGMEM esc_combo_jx[] = {KC_J, KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(esc_combo_xj, KC_ESC),
	COMBO(esc_combo_jx, KC_ESC),
};

#endif
