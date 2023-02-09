#include QMK_KEYBOARD_H

#include "quantum.h"
#include "../lib/custom/keymap_jp.h"

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

  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐     ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │

  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │

  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │

  //└───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────────────────┼───────────┼───────────┘
  //            │           │           │           │           │           │     │           │           │                       │           │
 
  //            └───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                       └───────────┘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐     ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      JS_TAB,     JS_Q,       JS_W,       JS_E,       JS_R,       JS_T,             JS_Y,       JS_U,       JS_I,       JS_O,       JS_P,       XXXXXXX,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      JS_LSFT,    JS_A,       JS_S,       JS_D,       JS_F,       JS_G,             JS_H,       JS_J,       JS_K,       JS_L,       JS_SCLN,    JS_RSFT,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      JS_LCTL,    JS_Z,       JS_X,       JS_C,       JS_V,       JS_B,             JS_N,       JS_M,       JS_COMM,    JS_DOT,     JS_SLSH,    JS_RCTL,
  //└───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────────────────┼───────────┼───────────┘
  //            │           │           │           │           │           │     │           │           │                       │           │
                 JS_LALT,    JS_LEFT_GUI,LT(1,JS_LNG2),LT(2,JS_SPC),LT(3,JS_LNG1), JS_BSPC,     LT(2,JS_ENT),XXXXXXX,   XXXXXXX,    LT(3,JS_ESC)
  //            └───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                       └───────────┘
  ),

  [1] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐     ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    S(JS_7),    S(JS_8),    S(JS_9),    S(JS_8),          S(JS_9),    S(JS_HIHU), JS_HIHU,    JS_HAT,     TD(TD_YEN_PIPE), _______,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    S(JS_4),    S(JS_5),    S(JS_6),    TD(TD_LBRC_LBRC), TD(TD_RBRC_RBRC),S(JS_SCLN),S(JS_CLN),JS_ATMK,  JS_CLN,     _______,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    S(JS_1),    S(JS_2),    S(JS_3),    S(JS_COMM),       S(JS_DOT),  S(JS_BSLSH),S(JS_COMM), S(JS_DOT),  S(JS_SLSH), _______,
  //└───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────────────────┼───────────┼───────────┘
  //            │           │           │           │           │           │     │           │           │                       │           │
                  _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,          _______,    _______,    XXXXXXX,    XXXXXXX,    _______
  //            └───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                       └───────────┘           
  ),

  [2] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐     ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    JS_7,       JS_8,       JS_9,       JS_0,             JS_HOME,    JS_LEFT,    JS_UP,      JS_RGHT,    JS_END,     _______,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    JS_4,       JS_5,       JS_6,       XXXXXXX,          JS_PGUP,    JS_BTN1,    JS_DOWN,    JS_BTN2,    XXXXXXX,    _______,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    JS_1,       JS_2,       JS_3,       XXXXXXX,          JS_PGDN,    JS_BTN4,    JS_BTN3,    JS_BTN5,    XXXXXXX,    _______,
  //└───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────────────────┼───────────┼───────────┘
  //            │           │           │           │           │           │     │           │           │                       │           │
                  _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,          JS_DEL,     JS_RCTL,    XXXXXXX,    XXXXXXX,     _______
  //            └───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                       └───────────┘
  ),

  [3] = LAYOUT_universal(
  //┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐     ┌───────────┬───────────┬───────────┬───────────┬───────────┬───────────┐
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    JS_F7,      JS_F8,      JS_F9,      JS_F10,           CG_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    JS_F4,      JS_F5,      JS_F6,      JS_F11,           SCRL_DVD,   CPI_I100,   XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
  //├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤
  //│           │           │           │           │           │           │     │           │           │           │           │           │           │
      _______,    XXXXXXX,    JS_F1,      JS_F2,      JS_F3,      JS_F12,           SCRL_DVI,   CPI_D100,   XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
  //└───────────┼───────────┼───────────┼───────────┼───────────┼───────────┤     ├───────────┼───────────┼───────────────────────┼───────────┼───────────┘
  //            │           │           │           │           │           │     │           │           │                       │           │
                  _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,          KBC_RST,    KBC_SAVE,   XXXXXXX,    XXXXXXX,    _______
  //            └───────────┴───────────┴───────────┴───────────┴───────────┘     └───────────┴───────────┘                       └───────────┘
  ),
};

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
    case CG_TOGG:
      // ctl と gui 入れ替え(win mac 切換え)
      if (record->event.pressed) {
        toggle_swap_ctl_gui();
      }
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
  keyball_oled_render_layerinfo();
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
}
#endif
