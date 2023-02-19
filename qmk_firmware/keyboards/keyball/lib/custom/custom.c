#include "./custom.h"
#include "./keymap_jp.h"

//////////////////////////////////////////////
// Custom Keys
//////////////////////////////////////////////
uint16_t hold_timers[MATRIX_ROWS][MATRIX_COLS];
uint16_t mem_keycode;
static bool lower_pressed = false;
static bool raise_pressed = false;

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
    case HT_CTL_QUES: ;{// hold: CTRL, tap: question
      uint16_t k = keyball_get_swap_win_mac() ? JS_RIGHT_GUI : JS_RCTL;
      mod_tap_action(record, is_same_prev, k, tap_question);
      return false;
    }
    case TOGG_WIN_MAC: {// ctl と gui 入れ替え(win mac 切換え)
      if (record->event.pressed) {
        toggle_swap_win_mac();
      }
      return false;
    }
    case WM_CTL_ALT: ; {// Win: CTL, Mac: Alt(Option)
      uint16_t k = keyball_get_swap_win_mac() ? JS_RALT : JS_RCTL;
      record->event.pressed ? register_code(k) : unregister_code(k);
      return false;
    }

    /////////////////
    // layter
    case LOWER: {
      if (record->event.pressed) {
        lower_pressed = true;

        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed) {
          tap_code(JS_LNG2);
        }
        lower_pressed = false;
      }
      return false;
    }

    case RAISE: {
      if (record->event.pressed) {
        raise_pressed = true;

        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed) {
          tap_code(JS_LNG1);
        }
        raise_pressed = false;
      }
      return false;
    }

    default:
      if (record->event.pressed) {
        lower_pressed = false;
        raise_pressed = false;
      }
      return true;
  }
}

//////////////////////////////////////////////
// Tap Dance Declarations
//////////////////////////////////////////////
//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(JS_ESC, JS_CAPS),
  [TD_YEN_PIPE]  = ACTION_TAP_DANCE_DOUBLE(JS_YEN, S(JS_YEN)),
  [TD_HIHN_EQL]  = ACTION_TAP_DANCE_DOUBLE(JS_HIHU, S(JS_HIHU)),
  [TD_LBRC_LBRC] = ACTION_TAP_DANCE_DOUBLE(JS_LBRC, S(JS_LBRC)),
  [TD_RBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(JS_RBRC, S(JS_RBRC)),
  [TD_BSLSH_UDSCR] = ACTION_TAP_DANCE_DOUBLE(JS_BSLSH, S(JS_BSLSH))
};

//////////////////////////////////////////////
// Layer
//////////////////////////////////////////////
layer_state_t layer_state_set_user(layer_state_t state) {
#    ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE

  switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
    case SYMBOL_LAYER ... FUNCTION_LAYER:
      // remove_auto_mouse_target must be called to adjust state *before* setting enable
      state = remove_auto_mouse_layer(state, false);
      set_auto_mouse_enable(false);
      break;
    default:
      set_auto_mouse_enable(true);
      break;
  }

#    else

#       ifdef LAYER_TO_LOWER_RAISE
  // Auto enable scroll mode when the highest layer is FUNCTION_LAYER
  keyball_set_scroll_mode(get_highest_layer(state) == _LOWER);
#       else
  // Auto enable scroll mode when the highest layer is FUNCTION_LAYER
  keyball_set_scroll_mode(get_highest_layer(state) == FUNCTION_LAYER);
#       endif

#    endif
  return state;
}


#    ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE

// トラックボールの初期設定
void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE_LAYER); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case SCRL_MO:
            return true;
        default:
            return false;
    }
    return  is_mouse_record_user(keycode, record);
}

#    endif


//////////////////////////////////////////////
// Tapping
//////////////////////////////////////////////
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
    case LT(2,JS_LNG1):
    case LT(3,JS_LNG1):
    case LT(3,JS_ESC):
      return false;
    default:
      return true;
  }
}

//////////////////////////////////////////////
// OLED
//////////////////////////////////////////////
#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_layerinfo();
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
}
#endif
