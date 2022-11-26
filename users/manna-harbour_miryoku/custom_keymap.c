// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

// key repeat

enum custom_keycodes {
  KC_CUSTOM_REP = SAFE_RANGE
};

uint16_t repeat_key = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (keycode == KC_CUSTOM_REP) {
      tap_code(repeat_key);
      return false;
    } else {
      repeat_key = keycode;
    }
  }
  return true;
}

const uint16_t PROGMEM repeat_home[] = {MIRYOKU_THUMBKEY_LM, MIRYOKU_THUMBKEY_RM, COMBO_END};

#define MIRYOKU_CUSTOM_COMBOS \
  COMBO(repeat_home, KC_CUSTOM_REP)
