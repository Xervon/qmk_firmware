/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include <stdio.h>

#include "./keymap_custom.h"
#include "./key_overrides.c"
#include "./tap_dances.c"
#include "./combos.c"

enum LAYERS {
    MET,
    PUQ,
    STN,
    NUM,
    FK,
    FN,
    SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MET] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(STN), XXXXXXX,                      XXXXXXX, DF(PUQ), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [PUQ] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,    KC_P,    KC_U,  KC_APP, KC_COMM,    KC_Q,                         KC_G,    KC_C,    KC_L,    KC_M,    KC_F, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,    HM_H,    HM_I,    HM_E,    HM_A,    KC_O,                         KC_D,    HM_T,    HM_R,    HM_N,    HM_S, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,    KC_K,    KC_Y,  KC_DOT, KC_QUOT, TD_XESC,                      TD_JESC,    KC_V,    KC_W,    KC_B,    KC_Z, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             MO(FN), MO(SYM),  KC_SPC,     KC_ENT, MO(NUM),  MO(FK)
                                        //`--------------------------'  `--------------------------'
    ),

    [STN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX,  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                       STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,                      STN_ST3,  STN_FR,  STN_RR,  STN_LR,  STN_TR,  STN_DR,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,                      STN_ST4,  STN_PR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX,   STN_A,   STN_O,      STN_E,   STN_U, MO(PUQ)
                                        //`--------------------------'  `--------------------------'
    ),

    [NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, KC_PMNS,    KC_7,    KC_8,    KC_9, KC_PPLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, HM_PSLS,   HM_N4,   HM_N5,   HM_N6, KC_PAST,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_PEQL,    KC_0,    KC_1,    KC_2,    KC_3, KC_PDOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, MO(MET), _______,    KC_PENT, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [SYM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,  KC_GRV,   KC_AT, KC_HASH,  KC_DLR, KC_SLSH,                      KC_BSLS, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, HM_LBRC, HM_LCBR,   HM_LT, HM_LPRN, KC_QUES,                      KC_EXLM, HM_RPRN,   HM_GT, HM_RCBR, HM_RBRC, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_TILD,                      KC_PIPE, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, MO(MET), _______
                                        //`--------------------------'  `--------------------------'
    ),

    [FK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX,   KC_F7,   KC_F8,   KC_F9, XXXXXXX,                      XXXXXXX,  KC_F17,  KC_F18,  KC_F19, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    HM_0,   HM_F4,   HM_F5,   HM_F6, XXXXXXX,                      XXXXXXX,  HM_F14,  HM_F15,  HM_F16,    HM_7, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                       KC_F10,  KC_F11,  KC_F12,  KC_F13, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [FN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX,    HM_0,    HM_1, HM_BRIU, HM_BRID, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
};

void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI);
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
#define XERVON_FORCE(code) case code: return true;

    switch (keycode) {
        XERVON_FORCE(HM_0);
        XERVON_FORCE(HM_1);
        XERVON_FORCE(HM_2);
        XERVON_FORCE(HM_3);
        XERVON_FORCE(HM_4);
        XERVON_FORCE(HM_5);
        XERVON_FORCE(HM_6);
        XERVON_FORCE(HM_7);

        XERVON_FORCE(HM_H);
        XERVON_FORCE(HM_I);
        XERVON_FORCE(HM_E);
        XERVON_FORCE(HM_A);
        XERVON_FORCE(HM_T);
        XERVON_FORCE(HM_R);
        XERVON_FORCE(HM_N);
        XERVON_FORCE(HM_S);

        XERVON_FORCE(HM_PSLS);
        XERVON_FORCE(HM_N4);
        XERVON_FORCE(HM_N5);
        XERVON_FORCE(HM_N6);

        XERVON_FORCE(HM_LBRC);
        XERVON_FORCE(HM_LCBR);
        XERVON_FORCE(HM_LT);
        XERVON_FORCE(HM_LPRN);
        XERVON_FORCE(HM_RBRC);
        XERVON_FORCE(HM_RCBR);
        XERVON_FORCE(HM_GT);
        XERVON_FORCE(HM_RPRN);

        XERVON_FORCE(HM_F4);
        XERVON_FORCE(HM_F5);
        XERVON_FORCE(HM_F6);
        XERVON_FORCE(HM_F14);
        XERVON_FORCE(HM_F15);
        XERVON_FORCE(HM_F16);

        XERVON_FORCE(HM_BRIU);
        XERVON_FORCE(HM_BRID);
    default:
        return false;
    }

#undef XERVON_KEY
}

// Hack to always have NUM-Lock enabled
// s. https://github.com/qmk/qmk_firmware/issues/2164#issuecomment-352331791
// by @drashna
void led_set_keymap(uint8_t usb_led) {
    if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
    case L_BASE:
        oled_write_ln_P(PSTR("Default"), false);
        break;
    case L_LOWER:
        oled_write_ln_P(PSTR("Lower"), false);
        break;
    case L_RAISE:
        oled_write_ln_P(PSTR("Raise"), false);
        break;
    case L_ADJUST:
    case L_ADJUST|L_LOWER:
    case L_ADJUST|L_RAISE:
    case L_ADJUST|L_LOWER|L_RAISE:
        oled_write_ln_P(PSTR("Adjust"), false);
        break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
             record->event.key.row, record->event.key.col,
             keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}
#endif // OLED_ENABLE
