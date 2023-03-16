#include QMK_KEYBOARD_H

#include "quantum.h"
#include "../lib/custom/custom.c"

  //┌───────────┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │                             │           │           │           │           │           │

  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │

  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │

  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐     ┌───────────├───────────┼───────────┴───────────┴───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │                                   │           │
 
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                                   └───────────┘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │                             │           │           │           │           │           │
      JS_Q,       JS_W,       JS_E,       JS_R,       JS_T,                                     JS_Y,       JS_U,       JS_I,       JS_O,       JS_P,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      JS_A,       JS_S,       JS_D,       JS_F,       JS_G,                                     JS_H,       JS_J,       JS_K,       JS_L,       JS_SCLN,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      JS_Z,       JS_X,       JS_C,       JS_V,       JS_B,                                     JS_N,       JS_M,       JS_COMM,    JS_DOT,     JS_SLSH,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐     ┌───────────├───────────┼───────────┴───────────┴───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │                                   │           │
      XXXXXXX,    JS_LNG2,    JS_LNG1,    RGUI_T(JS_ESC),LOWER,   LSFT_T(JS_SPC),   LCTL_T(JS_ENT),RAISE,   XXXXXXX,    XXXXXXX,   XXXXXXX,     RALT_T(JS_TAB)
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                                   └───────────┘
  ),

  [_LOWER] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │                             │           │           │           │           │           │
      JS_YEN,     S(JS_7),    S(JS_8),    S(JS_9),    XXXXXXX,                                  XXXXXXX,    S(JS_HIHU), JS_HIHU,    JS_HAT,     S(JS_YEN),
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      S(JS_ATMK), S(JS_4),    S(JS_5),    S(JS_6),    JS_LBRC,                                  JS_RBRC,    S(JS_SCLN), S(JS_CLN),  JS_ATMK,    JS_CLN,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      S(JS_HAT),  S(JS_1),    S(JS_2),    S(JS_3),    S(JS_LBRC),                               S(JS_RBRC), S(JS_BSLSH),S(JS_COMM), S(JS_DOT),  S(JS_SLSH),
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐     ┌───────────├───────────┼───────────┴───────────┴───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │                                   │           │
      _______,    _______,    _______,    _______,    _______,    _______,          _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                                   └───────────┘      
  ),

  [_RAISE] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    JS_7,       JS_8,       JS_9,       XXXXXXX,                                  XXXXXXX,    JS_HOME,    JS_UP,      JS_END,     XXXXXXX,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      WM_CTL_ALT, JS_4,       JS_5,       JS_6,       XXXXXXX,                                  JS_PGUP,    JS_LEFT,    JS_DOWN,    JS_RGHT,    JS_BSPC,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      JS_0,       JS_1,       JS_2,       JS_3,       XXXXXXX,                                  JS_PGDN,    JS_BTN4,    XXXXXXX,    JS_BTN5,    JS_DEL,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐     ┌───────────├───────────┼───────────┴───────────┴───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │                                   │           │
      _______,    _______,    _______,    _______,    _______,    _______,          _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                                   └───────────┘
),

  [_ADJUST] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    JS_F7,      JS_F8,      JS_F9,      JS_F10,                                   TOGG_WIN_MAC,XXXXXXX,   XXXXXXX,    XXXXXXX,    KBC_SAVE,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    JS_F4,      JS_F5,      JS_F6,      JS_F11,                                   SCRL_DVD,   CPI_I100,   XXXXXXX,    XXXXXXX,    XXXXXXX,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    JS_F1,      JS_F2,      JS_F3,      JS_F12,                                   SCRL_DVI,   CPI_D100,   XXXXXXX,    XXXXXXX,    XXXXXXX,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐     ┌───────────├───────────┼───────────┴───────────┴───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │                                   │           │
      _______,    _______,    _______,    _______,    _______,    _______,          _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                                   └───────────┘
  ),

    [_MOUSE] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                  XXXXXXX,    JS_BTN1,    JS_BTN3,    JS_BTN2,    SCRL_MO,
  //├───────────┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │                             │           │           │           │           │           │
      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┐     ┌───────────├───────────┼───────────┴───────────┴───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │                                   │           │
      _______,    _______,    _______,    _______,    _______,    _______,          _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______
  //└───────────┴───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                                   └───────────┘
  ),
};
