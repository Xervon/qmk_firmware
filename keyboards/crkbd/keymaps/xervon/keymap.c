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

#include "./layers.h"
#include "./keymap_custom.h"
#include "./key_overrides.c"
#include "./tap_dances.c"
#include "./combos.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MET] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
             RESET,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DF(STN),    XXXXXXX,                         XXXXXXX,    DF(PUQ),    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                       XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX
                                                 //`-----------------------------------'  `----------------------------------'
    ),

    [PUQ] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           XXXXXXX,       KC_P,       KC_U,     KC_APP,    KC_COMM,       KC_Q,                            KC_G,       KC_C,       KC_L,       KC_M,       KC_F,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,       HM_H,       HM_I,       HM_E,       HM_A,       KC_O,                            KC_D,       HM_T,       HM_R,       HM_N,       HM_S,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,       KC_K,       KC_Y,     KC_DOT, TD_QUOTESC,       KC_X,                            KC_J,    TD_VESC,       KC_W,       KC_B,       KC_Z,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                        MO(FN),    MO(SYM),     KC_SPC,        KC_ENT,    MO(NUM),     MO(FK)
                                                 //`-----------------------------------'  `----------------------------------'
    ),

    [STN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           XXXXXXX,     STN_N1,     STN_N2,     STN_N3,     STN_N4,     STN_N5,                          STN_N6,     STN_N7,     STN_N8,     STN_N9,     STN_NA,     STN_NB,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,     STN_S1,     STN_TL,     STN_PL,     STN_HL,    STN_ST1,                         STN_ST3,     STN_FR,     STN_RR,     STN_LR,     STN_TR,     STN_DR,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,     STN_S2,     STN_KL,     STN_WL,     STN_RL,    STN_ST2,                         STN_ST4,     STN_PR,     STN_BR,     STN_GR,     STN_SR,     STN_ZR,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                       XXXXXXX,      STN_A,      STN_O,         STN_E,      STN_U,    MO(PUQ)
                                                 //`-----------------------------------'  `----------------------------------'
    ),

    [NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           _______,    KC_PMNS,       KC_7,       KC_8,       KC_9,    KC_PPLS,                         XXXXXXX,     M_HOME,     M_PGDN,     M_PGUP,      M_END,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           _______,    HM_PSLS,       HM_4,       HM_5,       HM_6,    KC_PAST,                         XXXXXXX,    HM_LEFT,    HM_DOWN,      HM_UP,    HM_RGHT,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
            KC_EQL,       KC_0,       KC_1,       KC_2,       KC_3,    KC_PDOT,                         XXXXXXX,       KC_H,       KC_J,       KC_K,       KC_L,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                       _______,     KC_EQL,    _______,       KC_PENT,    _______,    _______
                                                 //`-----------------------------------'  `----------------------------------'
    ),

    [SYM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           _______,     KC_GRV,      KC_AT,    KC_HASH,     KC_DLR,    XXXXXXX,                         XXXXXXX,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           _______,    HM_LBRC,    HM_LCBR,      HM_LT,    HM_LPRN,    KC_QUES,                         KC_SLSH,    HM_RPRN,      HM_GT,    HM_RCBR,    HM_RBRC,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MINS,    KC_TILD,                         KC_PIPE,    KC_PLUS,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                       _______,    _______,    _______,       _______,    XXXXXXX,    _______
                                                 //`-----------------------------------'  `----------------------------------'
    ),

    [FK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           _______,    XXXXXXX,      KC_F7,      KC_F8,      KC_F9,    XXXXXXX,                         XXXXXXX,     KC_F17,     KC_F18,     KC_F19,    XXXXXXX,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           _______,  HM_BASE_0,      HM_F4,      HM_F5,      HM_F6,    XXXXXXX,                         XXXXXXX,     HM_F14,     HM_F15,     HM_F16,  HM_BASE_7,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           _______,    XXXXXXX,      KC_F1,      KC_F2,      KC_F3,    XXXXXXX,                          KC_F10,     KC_F11,     KC_F12,     KC_F13,    XXXXXXX,    _______,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                       _______,    _______,    _______,       _______,    _______,    _______
                                                 //`-----------------------------------'  `----------------------------------'
    ),

    [FN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                    ,-----------------------------------------------------------------------.
           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,  HM_BASE_0,  HM_BASE_1,    HM_BRIU,    HM_BRID,    XXXXXXX,                         XXXXXXX,    HM_MPRV,    HM_VOLD,    HM_VOLU,    HM_MNXT,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
           XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                    |-----------+-----------+-----------+-----------+-----------+-----------|
                                                       XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    _______
                                                 //`-----------------------------------'  `----------------------------------'
    ),
};

void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!keymap_custom_process_record_user(keycode, record)) {
        return false;
    }

    return true;
}
