#include "mehkee96.h"

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _FL 3

enum smt_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 0: Qwerty layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PSCN │ INS │HOME │ END │PGDN │PGUP │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │ DEL │NLCK │ P/  │ P*  │ P-  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │H_TAB│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BSPC │█████│ P7  │ P8  │ P9  │ P+  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │C_ESC│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ ENT │█████│ P4  │ P5  │ P6  │ P+  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSFT │▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│S_ENT│ UP  │ P1  │ P2  │ P3  │PENT │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTL │LGUI │LALT │█████│█████│█████│ SPC │█████│█████│█████│RALT │RGUI │ _FL │LEFT │DOWN │RGHT │ P0  │ P.  │PENT │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 0: ANSI qwerty */
  [_QWERTY] = LAYOUT_SPLITBS(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_INS,   KC_HOME,  KC_END,   KC_PGDN,  KC_PGUP, \
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS, \
    HPR_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,            KC_P7,    KC_P8,    KC_P9,    KC_PPLS, \
    CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_P4,    KC_P5,    KC_P6,    KC_PPLS, \
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            SFT_ENT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(_FL),  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),

  /* 1: Colemak layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PSCN │ INS │HOME │ END │PGDN │PGUP │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │ DEL │NLCK │ P/  │ P*  │ P-  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │H_TAB│  Q  │  W  │  F  │  P  │  G  │  J  │  L  │  U  │  Y  │  ;  │  [  │  ]  │BSPC │█████│ P7  │ P8  │ P9  │ P+  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │C_ESC│  A  │  R  │  S  │  T  │  D  │  H  │  N  │  E  │  I  │  O  │  '  │▒▒▒▒▒│ ENT │█████│ P4  │ P5  │ P6  │ P+  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSFT │▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  K  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│S_ENT│ UP  │ P1  │ P2  │ P3  │PENT │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTL │LGUI │LALT │█████│█████│█████│ SPC │█████│█████│█████│RALT │RGUI │ _FL │LEFT │DOWN │RGHT │ P0  │ P.  │PENT │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 1: ANSI colemak */
  [_COLEMAK] = LAYOUT_SPLITBS(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_INS,   KC_HOME,  KC_END,   KC_PGDN,  KC_PGUP, \
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_DEL,   KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS, \
    HPR_TAB,  KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSPC,            KC_P7,    KC_P8,    KC_P9,    KC_PPLS, \
    CTL_ESC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            KC_ENT,             KC_P4,    KC_P5,    KC_P6,    KC_PPLS, \
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            SFT_ENT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(_FL),  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),

  /* 2: Dvorak layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PSCN │ INS │HOME │ END │PGDN │PGUP │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  [  │  ]  │  \  │ DEL │NLCK │ P/  │ P*  │ P-  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │H_TAB│  '  │  ,  │  .  │  P  │  Y  │  F  │  G  │  C  │  R  │  L  │  /  │  =  │BSPC │█████│ P7  │ P8  │ P9  │ P+  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │C_ESC│  A  │  O  │  E  │  U  │  I  │  D  │  H  │  T  │  N  │  S  │  -  │▒▒▒▒▒│ ENT │█████│ P4  │ P5  │ P6  │ P+  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSFT │▒▒▒▒▒│  ;  │  Q  │  J  │  K  │  X  │  B  │  M  │  W  │  V  │  Z  │▒▒▒▒▒│S_ENT│ UP  │ P1  │ P2  │ P3  │PENT │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTL │LGUI │LALT │█████│█████│█████│ SPC │█████│█████│█████│RALT │RGUI │ _FL │LEFT │DOWN │RGHT │ P0  │ P.  │PENT │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 2: ANSI dvorak */
  [_DVORAK] = LAYOUT_SPLITBS(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,  KC_INS,   KC_HOME,  KC_END,   KC_PGDN,  KC_PGUP, \
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,   KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS, \
    HPR_TAB,  KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_EQL,   KC_BSPC,            KC_P7,    KC_P8,    KC_P9,    KC_PPLS, \
    CTL_ESC,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,            KC_ENT,             KC_P4,    KC_P5,    KC_P6,    KC_PPLS, \
    KC_LSFT,            KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,               SFT_ENT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI,  MO(_FL),  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),

  /* 3: Function layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │RESET│     │     │     │     │     │     │     │     │     │     │     │     │MUTE │VOLD │VOLU │     │RGBV-│RGBV+│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     │     │     │QWRTY│COLMK│DVORK│     │     │     │     │▒▒▒▒▒│     │     │     │     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ BL  │     │     │     │     │     │     │     │     │     │     │     │▒▒▒▒▒│ RGB │▒▒▒▒▒│     │     │     │     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │▒▒▒▒▒│     │     │ BL- │ BL  │ BL+ │     │     │     │     │     │▒▒▒▒▒│     │RGBS+│     │     │     │     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │█████│█████│█████│RGB_M│█████│█████│█████│     │     │     │RGBH-│RGBS-│RGBH+│     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 3: ANSI control layer */
	[_FL] = LAYOUT_SPLITBS(
    RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,  RGB_VAD,  RGB_VAI,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  QWERTY,   COLEMAK,  DVORAK,   _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,
    BL_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RGB_TOG,            _______,  _______,  _______,  _______,
    _______          ,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   _______,  _______,  _______,  _______,  _______,            _______,  RGB_SAI,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,                                RGB_MOD,                                _______,  _______,  MO(_FL),  RGB_HUD,  RGB_SAD,  RGB_HUI,  _______,  _______,  _______),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
