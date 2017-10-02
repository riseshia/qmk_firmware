/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _SLOWER,
  _SRAISE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  LOWER,
  RAISE,
  BCK_ESC
};

#define KC_LFT_TAB LGUI(LSFT(KC_LBRC))
#define KC_RGT_TAB LGUI(LSFT(KC_RBRC))
#define KC_LOW_D LT(_SLOWER, KC_D)
#define KC_RAI_F LT(_SRAISE, KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |  L D |  R F |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  | Lower|    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    BCK_ESC},
  {KC_LCTL, KC_A,    KC_S,    KC_LOW_D, KC_RAI_F, KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT },
  {KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_ESC,  KC_LCTL, KC_LALT,  KC_LGUI, LOWER,    KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Special Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   (  |   )  |   -  |   =  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   `  |   [  |   ]  |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SLOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, KC_GRV,  KC_LBRC, KC_RBRC, KC_QUOT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Special Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |   _  |   +  |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   ~  |   {  |   }  |   "  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   -  |   =  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   |  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SRAISE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_PIPE},
  {_______, _______, _______, _______, _______, _______, KC_TILD, KC_PIPE, KC_LCBR, KC_RCBR, KC_DQUO, _______},
  {_______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LABK, KC_RABK, KC_QUES, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_PIPE, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Esc  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Lft-Tb|Rgt-Tb|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_ESC },
  {_______, _______, _______, _______, _______, _______, _______, KC_LFT_TAB, KC_RGT_TAB, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint8_t pressed_kc = KC_BSPC;

  switch (keycode) {
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
    case BCK_ESC:
      if (record->event.pressed) {
        if (keyboard_report->mods & MOD_BIT(KC_LCTL)) {
          pressed_kc = KC_ESC;
        } else {
          pressed_kc = KC_BSPC;
        }
        register_code(pressed_kc);
      } else {
        unregister_code(pressed_kc);
      }
      return false;
      break;
  }
  return true;
}
