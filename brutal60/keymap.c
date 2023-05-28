/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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
enum {
   MEDIA,
};
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

#define TERMINAL LCTL(KC_GRV)
#define EXPLORER LALT(LSFT(KC_E))
#define TOGGLE_SIDEBAR LALT(LSFT(KC_B))
#define SWITCH_WINDOW LALT(KC_GRV)
#define GIT LCTL(LSFT(KC_G))

void dance_media (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code (KC_MNXT);
    } else if (state->count == 3) {
        tap_code(KC_MPRV);
    } else {
        reset_tap_dance (state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [MEDIA] =  ACTION_TAP_DANCE_FN(dance_media),
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_60_tsangan_hhkb(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSLS, KC_GRV, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSPC, \
    MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,                 KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,                 KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT, TD(MEDIA),\
    KC_LCTL, KC_LGUI, KC_LALT,                            LT(KC_LCTL, KC_SPC)  ,                                          KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_FN1] = LAYOUT_60_tsangan_hhkb(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLD,  KC_VOLU,  KC_DEL, _______,\
    SWITCH_WINDOW, _______, KC_UP,   EXPLORER, TD(MEDIA), TERMINAL, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE, GIT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,          _______, \
    BL_INC,  BL_DEC,  BL_TOGG, _______, KC_SPC, TOGGLE_SIDEBAR, _______, _______, _______, _______, _______,                   _______, _______,\
    _______,  _______, _______,                            _______,                            _______, _______, RESET
  )
  //  ! original fn1 layer [_FN1] = LAYOUT_60_tsangan_hhkb(
  //   KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______,\
  //   RGB_TOG, RGB_MOD, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  //   BL_BRTG, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  //   BL_INC,  BL_DEC,  BL_TOGG, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,\
  //   _______,  _______, _______,                            _______,                            _______, _______, RESET
  // )
};
