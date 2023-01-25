/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"
#include "./keymap_jp.h"

uint16_t hold_timers[MATRIX_ROWS][MATRIX_COLS];
uint16_t mem_keycode;

enum custum_keycodes {
  // hold: CTRL, tap: question
  HT_CTL_QUES = KEYBALL_SAFE_RANGE
};

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_YEN_PIPE,
  TD_HIHN_EQL,
  TD_LBRC_LBRC,
  TD_RBRC_RBRC,
  TD_BSLSH_UDSCR
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(JS_ESC, JS_CAPS),
  [TD_YEN_PIPE]  = ACTION_TAP_DANCE_DOUBLE(JS_YEN, S(JS_YEN)),
  [TD_HIHN_EQL]  = ACTION_TAP_DANCE_DOUBLE(JS_HIHU, S(JS_HIHU)),
  [TD_LBRC_LBRC] = ACTION_TAP_DANCE_DOUBLE(JS_LBRC, S(JS_LBRC)),
  [TD_RBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(JS_RBRC, S(JS_RBRC)),
  [TD_BSLSH_UDSCR] = ACTION_TAP_DANCE_DOUBLE(JS_BSLSH, S(JS_BSLSH))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    JS_Q        , JS_W     , JS_E         , JS_R     , JS_T     ,                            JS_Y     , JS_U     , JS_I     , JS_O     , JS_P     ,
    JS_A        , JS_S     , JS_D         , JS_F     , JS_G     ,                            JS_H     , JS_J     , JS_K     , JS_L     , RSFT_T(JS_SCLN),
    LCTL_T(JS_Z), JS_X     , JS_C         , JS_V     , JS_B     ,                            JS_N     , JS_M     , JS_COMM  , JS_DOT   , RCTL_T(JS_SLSH),
    JS_TAB      , JS_LALT  , JS_LEFT_GUI  ,LT(1,JS_LNG2),LT(2,JS_SPC),LT(3,JS_LNG1),JS_BSPC,LT(2,JS_ENT),XXXXXXX , XXXXXXX  , XXXXXXX  , LT(3,JS_ESC)
  ),

  [1] = LAYOUT_universal(
    XXXXXXX   , S(JS_7)  , S(JS_8)  , S(JS_9)  , S(JS_8)          ,                            S(JS_9)          , S(JS_HIHU)  , JS_HIHU   , JS_HAT   , TD(TD_YEN_PIPE),
    JS_LSFT   , S(JS_4)  , S(JS_5)  , S(JS_6)  , TD(TD_LBRC_LBRC) ,                            TD(TD_RBRC_RBRC) , S(JS_SCLN)  , S(JS_CLN) , JS_ATMK  , RSFT_T(JS_CLN),
    JS_LCTL   , S(JS_1)  , S(JS_2)  , S(JS_3)  , S(JS_COMM)       ,                            S(JS_DOT)        , S(JS_BSLSH) , S(JS_COMM), S(JS_DOT), HT_CTL_QUES,
    _______   , _______  , _______  , XXXXXXX  , XXXXXXX          , XXXXXXX  ,      _______ ,  _______          , XXXXXXX     , XXXXXXX   , XXXXXXX  , _______
  ),

  [2] = LAYOUT_universal(
    XXXXXXX   , JS_7     , JS_8     , JS_9     , JS_0     ,                            JS_HOME  , JS_LEFT  , JS_UP    , JS_RGHT  , JS_END   ,
    JS_LSFT   , JS_4     , JS_5     , JS_6     , XXXXXXX  ,                            JS_PGUP  , JS_BTN1  , JS_DOWN  , JS_BTN2  , JS_RSFT  ,
    JS_LCTL   , JS_1     , JS_2     , JS_3     , XXXXXXX  ,                            JS_PGDN  , JS_BTN4  , JS_BTN3  , JS_BTN5  , JS_RCTL  ,
    _______   , _______  , _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,      JS_DEL  ,  _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______
  ),

  [3] = LAYOUT_universal(
    XXXXXXX   , JS_F7    , JS_F8    , JS_F9    , JS_F10   ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX ,
    JS_LSFT   , JS_F4    , JS_F5    , JS_F6    , JS_F11   ,                            SCRL_DVD , CPI_I100 , XXXXXXX  , XXXXXXX , JS_RSFT ,
    JS_LCTL   , JS_F1    , JS_F2    , JS_F3    , JS_F12   ,                            SCRL_DVI , CPI_D100 , XXXXXXX  , XXXXXXX , JS_RCTL ,
    _______   , _______  , _______  , KBC_RST  , KBC_SAVE , XXXXXXX  ,      XXXXXXX ,  XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

bool is_tap (keyrecord_t *record) {
  return hold_timers[record->event.key.row][record->event.key.col]
  && timer_elapsed(hold_timers[record->event.key.row][record->event.key.col]) < TAPPING_TERM;
}

void tap_question(void){
  register_code(JS_RSFT);
  tap_code(JS_SLSH);
  unregister_code(JS_RSFT);
};

void mod_tap_action(keyrecord_t *record, bool is_same_prev, uint8_t mod, void (*cb)(void) ) {
  if (record->event.pressed) {
    add_mods(MOD_BIT(mod));
  } else {
    if (is_same_prev || is_tap(record)) {
      del_mods(MOD_BIT(mod));
      cb();
    } else {
      unregister_code(mod);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // prev keycode
  uint16_t prev_keycode = mem_keycode;
  mem_keycode = keycode;
  bool is_same_prev = prev_keycode == keycode;

  // record pressed timer
  if (record->event.pressed) {
    hold_timers[record->event.key.row][record->event.key.col] = timer_read();
  }

  switch (keycode) {
    case HT_CTL_QUES: // hold: CTRL, tap: question
      mod_tap_action(record, is_same_prev, JS_RCTL, tap_question);
      return false;
    default:
      return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD(TD_LBRC_LBRC):
    case TD(TD_RBRC_RBRC):
    case TD(TD_BSLSH_UDSCR):
    case TD(TD_HIHN_EQL):
    case TD(TD_YEN_PIPE):
      return 190;
    default:
      return TAPPING_TERM;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(1,JS_LNG2):
    case LT(3,JS_LNG1):
    case LT(3,JS_ESC):
      return false;
    default:
      return true;
  }
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
