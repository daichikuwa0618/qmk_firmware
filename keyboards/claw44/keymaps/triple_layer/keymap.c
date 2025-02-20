/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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
#include <secret.h> // make your secret file which contains PASSWORD macro.

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

enum custom_keycodes {
  KC_PW1 = SAFE_RANGE,
  KC_PW2,
  KC_ML1,
  KC_ML2
};

#define KC_L_SPC LT(_LOWER, KC_SPC)  // lower
#define KC_R_ENT LT(_RAISE, KC_ENT)  // raise
#define ADJUST MO(_ADJUST)
#define KC_G_JA LGUI_T(KC_LANG1)     // cmd or win
#define KC_G_EN LGUI_T(KC_LANG2)     // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC)      // ctrl
#define KC_A_DEL ALT_T(KC_DEL)       // alt

#define KC_C0 LCTL(KC_0)
#define KC_C1 LCTL(KC_1)
#define KC_C2 LCTL(KC_2)
#define KC_C3 LCTL(KC_3)
#define KC_C4 LCTL(KC_4)
#define KC_C5 LCTL(KC_5)
#define KC_C6 LCTL(KC_6)
#define KC_C7 LCTL(KC_7)
#define KC_C8 LCTL(KC_8)
#define KC_C9 LCTL(KC_9)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
    //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------.
       KC_ESC , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_MINS,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_TAB , KC_A   , KC_S    , KC_D   , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_QUOT,
    //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------|
       KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT,
    //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------'
                         KC_A_DEL, KC_G_EN, KC_L_SPC, KC_C_BS,     KC_C_BS, KC_R_ENT, KC_G_JA, KC_A_DEL
    //                 `----------+--------+---------+--------'   `--------+---------+--------+---------'
    ),

    [_RAISE] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,     KC_AT  , KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       KC_LPRN, KC_HASH, KC_DLR , KC_DQT , KC_QUOT, KC_TILD,     KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_GRV , KC_RPRN,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, KC_LCBR, KC_LBRC,     KC_RBRC, KC_RCBR, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                         _______, _______, ADJUST , _______,     _______, _______, _______, RESET
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_LOWER] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_C1  , KC_C2  , KC_C3  , KC_C4  , KC_C5  ,     _______, KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_C6  , KC_C7  , KC_C8  , KC_C9  , KC_C0  ,     _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                         RESET  , _______, _______, _______,     _______, ADJUST, _______, _______
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_ADJUST] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
       _______, KC_ML1 , KC_ML2 , _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, KC_PW1 , KC_PW2 , _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                         _______, _______, _______, _______,     _______, _______, _______, _______
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_PW1:
      if (record->event.pressed) {
        tap_code(KC_LANG2);
        SEND_STRING(PASSWORD1);
      }
      return false;
      break;
    case KC_PW2:
      if (record->event.pressed) {
        tap_code(KC_LANG2);
        SEND_STRING(PASSWORD2);
      }
      return false;
      break;
    case KC_ML1:
      if (record->event.pressed) {
        tap_code(KC_LANG2);
        SEND_STRING(MAIL1);
      }
      return false;
      break;
    case KC_ML2:
      if (record->event.pressed) {
        tap_code(KC_LANG2);
        SEND_STRING(MAIL2);
      }
      return false;
      break;
  }
  return true;
}
