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
// #include "keymap_jp.h"

#define JS_YEN 0x89
#define JS_BSLSH 0x87

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_Q        , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A        , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , RSFT_T(KC_SCLN),
    LGUI_T(KC_Z), KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , RGUI_T(KC_SLSH),
    KC_TAB      , KC_LALT  , KC_LCTL  ,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),XXXXXXX , XXXXXXX  , XXXXXXX  , LT(3,KC_ESC)
  ),

  [1] = LAYOUT_universal(
    XXXXXXX     , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_8)    ,                            S(KC_9)    , S(KC_SCLN), KC_MINS    , KC_EQL   , JS_YEN    ,
    KC_LSFT     , S(KC_4)  , S(KC_5)  , S(KC_6)  , KC_RBRC    ,                            KC_BSLS    , S(KC_SLSH), S(KC_QUOT) , KC_LBRC  , RSFT_T(S(KC_QUOT)),
    KC_LEFT_GUI , S(KC_1)  , S(KC_2)  , S(KC_3)  , S(KC_COMM) ,                            S(KC_DOT)  , JS_BSLSH  , S(KC_COMM) , S(KC_DOT), RGUI_T(S(KC_SLSH))  ,
    _______     , _______  , _______  , XXXXXXX  , XXXXXXX    , XXXXXXX  ,        KC_DEL ,  _______   , XXXXXXX   , XXXXXXX    , XXXXXXX  , _______
  ),

  [2] = LAYOUT_universal(
    XXXXXXX     , KC_7     , KC_8     , KC_9     , KC_0     ,                            KC_HOME  , KC_LEFT  , KC_UP    , KC_RGHT  , KC_END   ,
    KC_LSFT     , KC_4     , KC_5     , KC_6     , XXXXXXX  ,                            KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_RSFT  ,
    KC_LEFT_GUI , KC_1     , KC_2     , KC_3     , XXXXXXX  ,                            KC_PGDN  , KC_BTN4  , KC_BTN3  , KC_BTN5  , KC_RIGHT_GUI ,
    _______     , _______  , _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,      KC_DEL  ,  _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , _______
  ),

  [3] = LAYOUT_universal(
    XXXXXXX     , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,                            XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX , XXXXXXX ,
    KC_LSFT     , KC_F4    , KC_F5    , KC_F6    , KC_F11   ,                            SCRL_DVD , CPI_I100 , XXXXXXX  , XXXXXXX , KC_RSFT ,
    KC_LEFT_GUI , KC_F1    , KC_F2    , KC_F3    , KC_F12   ,                            SCRL_DVI , CPI_D100 , XXXXXXX  , XXXXXXX , KC_RIGHT_GUI ,
    _______     , _______  , _______  , KBC_RST  , KBC_SAVE , XXXXXXX  ,      XXXXXXX ,  XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
