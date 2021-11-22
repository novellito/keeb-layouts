/* Copyright 2019 COSEYFANNITUTTI
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum {
   MEDIA,
};

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_65_ansi(
      KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_MPLY,
      MO(1), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_VOLU,
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_VOLD,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 KC_RALT, KC_RGUI, _______,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  [1] = LAYOUT_65_ansi(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,   KC_INS,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \      delete*/ 
      KC_TRNS, KC_TRNS, KC_TRNS, EXPLORER, KC_MPLY,  TERMINAL,KC_TRNS,KC_TRNS,KC_INS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_MPLY,
     /*  caps     A       S        D        F        G      H        J      K        L        ;        '        enter             pg up*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE,GIT,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT, KC_TRNS, KC_TRNS,  KC_TRNS,            KC_MNXT,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      KC_LSFT,          KC_TRNS, KC_TRNS, KC_CAPS,KC_TRNS,TOGGLE_SIDEBAR,KC_TRNS,KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,  KC_MS_BTN1, KC_MS_UP,  KC_MPRV,
     /* ctrl     alt      cmd                              space                     fn      alt     ctrl      left     down     right*/
      KC_LCTL, KC_LALT, KC_LGUI,                          SWITCH_WINDOW,                KC_TRNS, KC_RALT, KC_RCTL,  KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT)
};
