// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once


#define MIRYOKU_ALTERNATIVES_BASE_ISRT \
KC_Y,                   KC_C,                   KC_L,                   KC_M,                   KC_K,                   KC_Z,                   KC_F,                   KC_U,                   KC_COMM,                KC_QUOT,                \
LGUI_T(KC_I),           LALT_T(KC_S),           LCTL_T(KC_R),           LSFT_T(KC_T),           KC_G,                   KC_P,                   LSFT_T(KC_N),           LCTL_T(KC_E),           LALT_T(KC_A),           LGUI_T(KC_O),           \
LT(U_BUTTON,KC_Q),      ALGR_T(KC_V),           KC_W,                   KC_D,                   KC_J,                   KC_B,                   KC_H,                   KC_SLSH,                ALGR_T(KC_DOT),         LT(U_BUTTON,KC_X),      \
U_NP,                   U_NP,                   MIRYOKU_THUMBKEY_LO,    MIRYOKU_THUMBKEY_LM,    MIRYOKU_THUMBKEY_LI,    MIRYOKU_THUMBKEY_RI,    MIRYOKU_THUMBKEY_RM,    MIRYOKU_THUMBKEY_RO,    U_NP,                   U_NP

#define MIRYOKU_ALTERNATIVES_TAP_ISRT \
KC_Y,                   KC_C,                   KC_L,                   KC_M,                   KC_K,                   KC_Z,                   KC_F,                   KC_U,                   KC_COMM,                KC_QUOT,                \
KC_I,                   KC_S,                   KC_R,                   KC_T,                   KC_G,                   KC_P,                   KC_N,                   KC_E,                   KC_A,                   KC_O,                   \
KC_Q,                   KC_V,                   KC_W,                   KC_D,                   KC_J,                   KC_B,                   KC_H,                   KC_SLSH,                KC_DOT,                 KC_X,                   \
U_NP,                   U_NP,                   MIRYOKU_THUMBKEY_LO_KC, MIRYOKU_THUMBKEY_LM_KC, MIRYOKU_THUMBKEY_LI_KC, MIRYOKU_THUMBKEY_RI_KC, MIRYOKU_THUMBKEY_RM_KC, MIRYOKU_THUMBKEY_RO_KC, U_NP,                   U_NP

#define MIRYOKU_LAYER_BASE MIRYOKU_ALTERNATIVES_BASE_ISRT
#define MIRYOKU_LAYER_TAP MIRYOKU_ALTERNATIVES_TAP_ISRT
