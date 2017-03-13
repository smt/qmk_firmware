#include "tada68.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define ALT_GRV     ALT_T(KC_GRV)               // Tap for Backtick, hold for Alt
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
#define SFT_RSE     TD(KC_LSFT, OS(_RAISE))     // Double-tap for RAISE one-shot, otherwise Left Shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWERTY: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |HypTb|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CtrlEsc|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |         Space         |Alt| Fn|Ctrl|Lft|Dwn|Rgt |
   * `----------------------------------------------------------------'
   */
[_QWERTY] = KEYMAP_ANSI(
  KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_GRV, \
  HPR_TAB,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,KC_DEL, \
  CTL_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_ENT, KC_PGUP, \
  SFT_RSE,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_UP,  KC_PGDN, \
  KC_LCTL,KC_LGUI,KC_LALT,              KC_SPC,                        KC_RALT,MO(_LOWER),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _COLEMAK: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |HypTb|  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |CtrlEsc|  A|  R|  S|  T|  D|  H|  N|  E|  I|  O|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |         Space         |Alt| Fn|Ctrl|Lft|Dwn|Rgt |
   * `----------------------------------------------------------------'
   */
[_COLEMAK] = KEYMAP_ANSI(
  KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_GRV, \
  HPR_TAB,KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_LBRC,KC_RBRC,KC_BSLS,KC_DEL, \
  CTL_ESC,KC_A,   KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,        KC_ENT, KC_PGUP,  \
  SFT_RSE,        KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,KC_UP,  KC_PGDN, \
  KC_LCTL,KC_LGUI,KC_LALT,              KC_SPC,                        KC_RALT,MO(_LOWER),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _DVORAK: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |HypTb|  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|  \  |Del |
   * |----------------------------------------------------------------|
   * |CtrlEsc|  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |         Space         |Alt| Fn|Ctrl|Lft|Dwn|Rgt |
   * `----------------------------------------------------------------'
   */
[_DVORAK] = KEYMAP_ANSI(
  KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC,KC_RBRC,KC_BSPC,KC_GRV, \
  HPR_TAB,KC_QUOT,KC_COMM,KC_DOT, KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,   KC_SLSH,KC_EQL, KC_BSLS,KC_DEL, \
  CTL_ESC,KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,   KC_MINS,        KC_ENT, KC_PGUP,  \
  SFT_RSE,        KC_SCLN,KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,   KC_RSFT,KC_UP,  KC_PGDN, \
  KC_LCTL,KC_LGUI,KC_LALT,              KC_SPC,                        KC_RALT,MO(_LOWER),KC_RCTL,KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _LOWER: Function Layer
   * ,----------------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |  ~ |
   * |----------------------------------------------------------------|
   * |     |Hom| Up|End|   |   |   |   |   |   |Mut|BL-|BL+|BL   |Bspc|
   * |----------------------------------------------------------------|
   * |      |Lft|Dwn|Rgt|   |   |Lft|Dwn| Up|Rgt|Vo+|Pg+|        |Home|
   * |----------------------------------------------------------------|
   * |        |   |   |Prv|Ply|Nxt|   |   |   |Vo-|Pg-|      |   | End|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[_LOWER] = KEYMAP_ANSI(
  KC_GRV ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_DEL, KC_TILD,  \
  _______,KC_HOME,KC_UP  ,KC_END ,_______,_______,_______,_______,_______,_______,KC_MUTE,BL_DEC ,BL_INC ,BL_TOGG,KC_BSPC, \
  _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_VOLU,KC_PGUP,        _______,KC_HOME, \
  KC_LSFT        ,_______,_______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,_______,KC_VOLD,KC_PGDN,_______,_______,KC_END, \
  _______,_______,_______                ,_______                        ,_______,_______,_______,_______,_______,_______),

  /* Keymap _RAISE: Function Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   | RESET |    |
   * |----------------------------------------------------------------|
   * |     RESET   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |Qwe|Col|Dvo|   |   |        |    |
   * |----------------------------------------------------------------|
   * |        | F1|F2 | F3|F4 | F5| F6| F7| F8|   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |    |
   * `----------------------------------------------------------------'
   */
[_RAISE] = KEYMAP_ANSI(
  #ifdef RGBLIGHT_ENABLE
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET  ,_______, \
  _______,RESET  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,QWERTY ,COLEMAK,DVORAK ,_______,_______,        _______,_______, \
  KC_LSFT        ,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______,_______,_______, \
  _______,_______,_______                ,_______                        ,_______,XXXXXXX,_______,_______,_______,_______
  #else
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RESET  ,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______,_______,_______,_______,_______,QWERTY ,COLEMAK,DVORAK ,_______,_______,        _______,_______, \
  KC_LSFT        ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
  _______,_______,_______                ,_______                        ,_______,XXXXXXX,_______,_______,_______,_______
  #endif
  )
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
