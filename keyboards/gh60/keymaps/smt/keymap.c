#include "gh60.h"
#include "action_layer.h"

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _FN 3
#define _UTIL 4

// Keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  FN,
  UTIL
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define FN_ESC      LT(_FN, KC_ESC)                      // Tap for Esc, hold for Function Layer
#define HPR_TAB     ALL_T(KC_TAB)                        // Tap for Tab, hold for Hyper
#define RGB_ON      F(0) // ACTION_FUNCTION(RGBLED_TOGGLE)       // Turn on/off underglow
#define RGB_STEP    F(1) // ACTION_FUNCTION(RGBLED_STEP_MODE)    // Change underglow mode
#define RGB_HUE_INC F(2) // ACTION_FUNCTION(RGBLED_INCREASE_HUE)
#define RGB_HUE_DEC F(3) // ACTION_FUNCTION(RGBLED_DECREASE_HUE)
#define RGB_SAT_INC F(4) // ACTION_FUNCTION(RGBLED_INCREASE_SAT)
#define RGB_SAT_DEC F(5) // ACTION_FUNCTION(RGBLED_DECREASE_SAT)
#define RGB_VAL_INC F(6) // ACTION_FUNCTION(RGBLED_INCREASE_VAL)
#define RGB_VAL_DEC F(7) // ACTION_FUNCTION(RGBLED_DECREASE_VAL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |   Bksp    |
 * |-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|
 * |HyperTab|   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |    \     |
 * |--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|
 * | Fn/Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter      |
 * |---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|
 * |    Shift    |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |        Shift        |
 * |-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|
 * |   Ctrl  |   GUI   |   Alt   |                     Space                  |   Alt   |   Fn    |   GUI   |   Ctrl   |
 *  `--------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'
 */
[_QWERTY] = KEYMAP(
/*,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------.*/
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,  KC_BSPC  ,
/*|-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|*/
    HPR_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,  KC_BSLS ,
/*|--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|*/
     FN_ESC ,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT, XXXXXXX, KC_ENT ,
/*|---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|*/
 KC_LSFT,XXXXXXX,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,  XXXXXXX,  KC_RSFT  ,
/*|-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|*/
    KC_LCTL , KC_LGUI , KC_LALT ,                KC_SPC , XXXXXXX            , KC_RALT ,    FN   , KC_RGUI , KC_RCTL ),
/*`---------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'*/

/* Colemak
 *
 * ,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |   Bksp    |
 * |-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|
 * |HyperTab|   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |    \     |
 * |--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|
 * | Fn/Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter      |
 * |---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|
 * |    Shift    |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |        Shift        |
 * |-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|
 * |   Ctrl  |   GUI   |   Alt   |                     Space                  |   Alt   |   Fn    |   GUI   |   Ctrl   |
 *  `--------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'
 */
[_COLEMAK] = KEYMAP(
/*,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------.*/
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,  KC_BSPC  ,
/*|-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|*/
    HPR_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,  KC_BSLS ,
/*|--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|*/
     FN_ESC ,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT, XXXXXXX, KC_ENT ,
/*|---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|*/
 KC_LSFT,XXXXXXX,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,  XXXXXXX,  KC_RSFT  ,
/*|-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|*/
    KC_LCTL , KC_LGUI , KC_LALT ,                KC_SPC , XXXXXXX            , KC_RALT ,    FN   , KC_RGUI , KC_RCTL ),
/*`---------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'*/

/* Dvorak
 *
 * ,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |   Bksp    |
 * |-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|
 * |HyperTab|   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |   ]   |    \     |
 * |--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|
 * | Fn/Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |      Enter      |
 * |---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|
 * |    Shift    |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |        Shift        |
 * |-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|
 * |   Ctrl  |   GUI   |   Alt   |                     Space                  |   Alt   |   Fn    |   GUI   |   Ctrl   |
 *  `--------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'
 */
[_DVORAK] = KEYMAP(
/*,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------.*/
    KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_LBRC,KC_RBRC,  KC_BSPC  ,
/*|-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|*/
    HPR_TAB,KC_QUOT,KC_COMM, KC_DOT,   KC_P,   KC_Y,   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,KC_SLSH, KC_EQL,  KC_BSLS ,
/*|--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|*/
     FN_ESC ,   KC_A,   KC_O,   KC_E,   KC_U,   KC_I,   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,KC_MINS, XXXXXXX, KC_ENT ,
/*|---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|*/
 KC_LSFT,XXXXXXX,KC_SCLN,   KC_Q,   KC_J,   KC_K,   KC_X,   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,  XXXXXXX,  KC_RSFT  ,
/*|-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|*/
    KC_LCTL , KC_LGUI , KC_LALT ,                KC_SPC , XXXXXXX            , KC_RALT ,    FN   , KC_RGUI , KC_RCTL ),
/*`---------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'*/

/* Function Layer
 *
 * ,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------.
 * |  Esc  |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |    Del    |
 * |-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|
 * |        |       |  Up   |       |       |       |       |       |       |       |PrntScr|ScrLock| Pause |   PgUp   |
 * |--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|
 * |         | Left  | Down  | Right |       | Home  | Left  | Down  |  Up   | Right |  End  |       |       PgDn      |
 * |---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|
 * |             |       |       |       |       |       |       |       |       |       |       |                     |
 * |-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|
 * |         |         |         |                     Utils                  |         |         |         |          |
 *  `--------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'
 */
[_FN] = KEYMAP(
/*,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------.*/
    KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,   KC_DEL  ,
/*|-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|*/
    _______,_______,  KC_UP,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,  KC_PGUP ,
/*|--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|*/
    _______ ,KC_LEFT,KC_DOWN,KC_RGHT,_______,KC_HOME,KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT, KC_END,_______, _______, KC_PGDN,
/*|---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|*/
 _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,  _______  ,
/*|-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|*/
    _______ , _______ , _______ ,              TG(UTIL) , _______            , _______ , _______ , _______ , _______ ),
/*`---------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'*/

/* Utility Layer
 *
 * ,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |           |
 * |-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|
 * |        |       |       |       |       |       |       |       |       |       |       |       |       |          |
 * |--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|
 * |         |RGB On |RGBStep|       |       |       |       |Qwerty |Colemak| Dvorak|       |       |                 |
 * |---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|
 * |             |       |RGBHue+|RGBHue-|RGBSat+|RGBSat-|RGBVal+|RGBVal-|       |       |       |                     |
 * |-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|
 * |         |         |         |                      Exit                  |         |         |         |          |
 *  `--------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'
 */
[_UTIL] = KEYMAP(
/*,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+----------.*/
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______  ,
/*|-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------|*/
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______ ,
/*|--------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`----------|*/
    _______ , RGB_ON,RGB_STEP,_______,_______,_______,_______,QWERTY ,COLEMAK, DVORAK,_______,_______, _______, _______,
/*|---------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-----------------|*/
_______,_______,_______,RGB_HUE_INC,RGB_HUE_DEC,RGB_SAT_INC,RGB_SAT_DEC,RGB_VAL_INC,RGB_VAL_DEC,_______,_______,_______,_______,_______,
/*|-------------`-------`-------`-------`-------`-------`-------`-------`-------`-------`-------`---------------------|*/
    _______ , _______ , _______ ,              TG(UTIL) , _______            , _______ , _______ , _______ , _______ ),
/*`---------+---------+---------+----------------------^^^-------------------+---------+---------+---------+----------'*/
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

enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(RGBLED_TOGGLE), //Turn on/off underglow
    [1] = ACTION_FUNCTION(RGBLED_STEP_MODE), // Change underglow mode
    [2] = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
    [3] = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
    [4] = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
    [5] = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
    [6] = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
    [7] = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void matrix_scan_user(void) {

// Layer LED indicators
// ESC led on when in function layer, WASD cluster leds enabled when on arrow cluster
    uint32_t layer = layer_state;
    if (layer & (1<<_FN)) {
        gh60_wasd_leds_on();
    } else {
        gh60_wasd_leds_off();
    }

    if (layer & (1<<_UTIL)) {
        gh60_esc_led_on();
    } else {
        gh60_esc_led_off();
    }
};

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      //led operations
      if (record->event.pressed) {
        rgblight_toggle();
        }
        break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
        }
        break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
        }
        break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
        }
        break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
        }
        break;
    case RGBLED_INCREASE_VAL:
        if (record->event.pressed) {
          rgblight_increase_val();
        }
        break;
    case RGBLED_DECREASE_VAL:
        if (record->event.pressed) {
          rgblight_decrease_val();
        }
        break;
    case RGBLED_STEP_MODE:
        if (record->event.pressed) {
          rgblight_step();
        }
        break;
  }
};
