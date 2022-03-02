#ifndef XERVON_COMBOS
#define XERVON_COMBOS

#include "./tap_dances.c"

const uint16_t PROGMEM esc_combo_quot_v[] = {TD_QUOTESC, TD_VESC,    COMBO_END};
const uint16_t PROGMEM esc_combo_v_quot[] = {TD_VESC,    TD_QUOTESC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	COMBO(esc_combo_quot_v, KC_ESC),
	COMBO(esc_combo_v_quot, KC_ESC),
};

#endif
