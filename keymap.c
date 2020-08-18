#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _MAIN 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

#define CODE_UP RALT(KC_UP)
#define CODE_DOWN RALT(KC_DOWN)
#define TEXT_LEFT RALT(KC_LEFT)
#define TEXT_RIGHT RALT(KC_RIGHT)
#define LOCK_MAC LCTL(LGUI(KC_Q))
#define INSPECT_ELEMENT LGUI(RALT(KC_I))

// Pane splitting Mac using Magnet
#define HALF_LT LCTL(RALT(KC_LEFT))
#define HALF_RT LCTL(RALT(KC_RIGHT))

#define LT_3RD LCTL(RALT(KC_D))
#define LT_2_3RD LCTL(RALT(KC_E))
#define CTR_3RD LCTL(RALT(KC_F))
#define RT_2_3RD LCTL(RALT(KC_T))
#define RT_3RD LCTL(RALT(KC_G))

enum custom_keycodes {
  _MAIN = SAFE_RANGE,
  _FN1,
  _FN2,
  _FN3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,    KC_9,      KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,      KC_I,     KC_O,   KC_P,    KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,     KC_K,      KC_L,   KC_SCLN,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRACKET,           KC_RBRACKET,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENTER,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                      KC_LGUI, LOWER,    KC_SPC,                    KC_SPC,    RAISE,     KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     GRAVE_ESC, _______, _______,   _______, _______,  _______,                            _______, _______, _______, KC_MINS, KC_EQL, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILDE,   KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______,    _______,                     CODE_UP, CODE_DOWN, INSPECT_ELEMENT, _______,  _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,_______,                        KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT,  _______, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  _______,  _______,  _______,  _______,  _______,  _______,          _______, TEXT_LEFT, TEXT_RIGHT, _______, _______, _______, KC_ENTER,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_SPC,                    KC_SPC,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,   _______, _______,  _______,                            _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  _______, _______, _______, KC_PGUP, KC_PGDOWN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,                  _______, KC_VOLD, KC_MUTE,  KC_VOLU, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_FN3] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LOCK_MAC, _______, _______, _______, _______, _______,                            RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, CTR_3RD,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, LT_3RD, LT_2_3RD, HALF_LT,          HALF_RT, RT_2_3RD, RT_3RD, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MAIN);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_FN1);
        update_tri_layer(_FN1, _FN2, _FN3);
      } else {
        layer_off(_FN1);
        update_tri_layer(_FN1, _FN2, _FN3);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_FN2);
        update_tri_layer(_FN1, _FN2, _FN3);
      } else {
        layer_off(_FN2);
        update_tri_layer(_FN1, _FN2, _FN3);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_FN3);
      } else {
        layer_off(_FN3);
      }
      return false;
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _FN1:
        rgblight_setrgb (RGB_TURQUOISE);
        break;
    case _FN2:
        rgblight_setrgb (RGB_PURPLE);
        break;
    case _FN3:
        rgblight_setrgb (RGB_YELLOW);
        break;
    default:
        rgblight_setrgb (RGB_AZURE);
        break;
    }
  return state;
}