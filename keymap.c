#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// Layer 1 - easy access
#define TEXT_LEFT RALT(KC_LEFT)
#define TEXT_RIGHT RALT(KC_RIGHT)
#define TERMINAL LCTL(KC_GRV)

// Layer 2 - vscode
#define CODE_COMMENT LGUI(KC_SLSH)
#define CODE_UP RALT(KC_UP)
#define CODE_DOWN RALT(KC_DOWN)
#define INSPECT_ELEMENT LGUI(RALT(KC_I))
#define MULT_SEL_UP LGUI(RALT(KC_UP))
#define MULT_SEL_DN LGUI(RALT(KC_DOWN))

// Layer 3 - misc
#define HALF_LT LCTL(RALT(KC_LEFT))
#define HALF_RT LCTL(RALT(KC_RIGHT))
#define LT_3RD LCTL(RALT(KC_D))
#define LT_2_3RD LCTL(RALT(KC_E))
#define CTR_3RD LCTL(RALT(KC_F))
#define RT_2_3RD LCTL(RALT(KC_T))
#define RT_3RD LCTL(RALT(KC_G))
#define LOCK_MAC LCTL(LGUI(KC_Q))

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FAT_ARROW
};

enum {
   L_BRACES,
   R_BRACES,
   MEDIA,
   MINUS,
   EQUAL
};

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
  [L_BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_LCBR),
  [R_BRACES] = ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, KC_RCBR),
  [MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_MINS),
  [EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_EQL),
  [MEDIA] =  ACTION_TAP_DANCE_FN(dance_media)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6,    KC_7,    KC_8,    TD(MINUS), TD(EQUAL),  KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                      KC_Y,    KC_U,      KC_I,     KC_O,   KC_P,    KC_BSLASH,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,     KC_K,      KC_L,   KC_SCLN,  MT(MOD_RSFT,KC_QUOT),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,   KC_Z,     KC_X,      KC_C,    KC_V,    KC_B,   TD(L_BRACES),          TD(R_BRACES), KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
               LCMD_T(KC_SPC),  LT(_LOWER,KC_SPC),  LT(_LOWER,KC_SPC),                        LT(_RAISE,KC_SPC),  LT(_RAISE,KC_SPC), LALT_T(KC_SPC)
                                   // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌ ────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE, _______, _______,   _______, _______,  _______,                            _______, _______, _______, KC_UNDS, KC_PLUS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILDE,   KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _______,  TERMINAL,                         _______, KC_PGDOWN, KC_PGUP, _______,  _______,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, TD(MEDIA),_______,                        KC_LEFT, KC_DOWN,   KC_UP,   KC_RIGHT,  _______, KC_ENTER,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL,  _______,  _______,  KC_VOLD,  KC_MUTE,  KC_VOLU,  FAT_ARROW,          _______, TEXT_LEFT, TEXT_RIGHT, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, KC_SPC, KC_SPC,                    KC_SPC,  KC_SPC, KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ), 

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,   _______, _______,  _______,                            MULT_SEL_UP, MULT_SEL_DN, INSPECT_ELEMENT, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  CODE_DOWN, CODE_UP, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,  _______, _______, CODE_COMMENT, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, ADJUST,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LOCK_MAC, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, CTR_3RD,                            CTR_3RD, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, LT_3RD, LT_2_3RD, HALF_LT,          HALF_RT, RT_2_3RD, RT_3RD, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                        _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case FAT_ARROW:
      if (record->event.pressed) {
       SEND_STRING("=>");
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}