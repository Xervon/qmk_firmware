#ifndef XERVON_KEYMAP_CUSTOM_H
#define XERVON_KEYMAP_CUSTOM_H

#define HM_BASE_0 KC_LALT
#define HM_BASE_1 KC_LGUI
#define HM_BASE_2 KC_LSFT
#define HM_BASE_3 KC_LCTL
#define HM_BASE_4 KC_RCTL
#define HM_BASE_5 KC_RSFT
#define HM_BASE_6 KC_RGUI
#define HM_BASE_7 KC_RALT


#define HM_H    LALT_T(KC_H)
#define HM_I    LGUI_T(KC_I)
#define HM_E    LSFT_T(KC_E)
#define HM_A    LCTL_T(KC_A)

#define HM_T    RCTL_T(KC_T)
#define HM_R    RSFT_T(KC_R)
#define HM_N    RGUI_T(KC_N)
#define HM_S    RALT_T(KC_S)


#define  M_HOME RCTL_T(KC_HOME)
#define  M_PGDN RSFT_T(KC_PGDN)
#define  M_PGUP RGUI_T(KC_PGUP)
#define  M_END  RALT_T(KC_END)

#define HM_PSLS LALT_T(KC_PSLS)
#define HM_4    LGUI_T(KC_4)
#define HM_5    LSFT_T(KC_5)
#define HM_6    LCTL_T(KC_6)

#define HM_LEFT RCTL_T(KC_LEFT)
#define HM_DOWN RSFT_T(KC_DOWN)
#define HM_UP   RGUI_T(KC_UP)
#define HM_RGHT RALT_T(KC_RGHT)


#define HM_LBRC LALT_T(KC_LBRC)
#define HM_LCBR LGUI_T(KC_LCBR)
#define HM_LT   LSFT_T(KC_LT)
#define HM_LPRN LCTL_T(KC_LPRN)

#define HM_RPRN RCTL_T(KC_RPRN)
#define HM_GT   RSFT_T(KC_GT)
#define HM_RCBR RGUI_T(KC_RCBR)
#define HM_RBRC RALT_T(KC_RBRC)


#define HM_F4   LGUI_T(KC_F4)
#define HM_F5   LSFT_T(KC_F5)
#define HM_F6   LCTL_T(KC_F6)

#define HM_F14  RCTL_T(KC_F14)
#define HM_F15  RSFT_T(KC_F15)
#define HM_F16  RGUI_T(KC_F16)


#define HM_BRIU LSFT_T(KC_BRIU)
#define HM_BRID LCTL_T(KC_BRID)

#define HM_MPRV RCTL_T(KC_MPRV)
#define HM_VOLD RSFT_T(KC_VOLD)
#define HM_VOLU RGUI_T(KC_VOLU)
#define HM_MNXT RALT_T(KC_MNXT)

bool keymap_custom_process_record_user(uint16_t keycode, keyrecord_t *record) {
#define KEYCODE(kc) \
    case HM_##kc:\
        if (record->tap.count && record->event.pressed) {\
            tap_code16(KC_##kc);\
            return false;\
        }\
        break;

    switch (keycode) {
    	KEYCODE(LBRC)
	KEYCODE(LCBR)
	KEYCODE(LT)
	KEYCODE(LPRN)
	KEYCODE(RPRN)
	KEYCODE(GT)
	KEYCODE(RCBR)
	KEYCODE(RBRC)
    }

    return true;

#undef KEYCODE
}

#endif
