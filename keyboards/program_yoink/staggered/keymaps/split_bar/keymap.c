/* Copyright 2020 melonbred
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LAYER1,
    _LAYER2
};

// Defines Combos for use in the keymap
enum combo_events {
  COMBO_SLSH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_bar(
        KC_ESC,        KC_Q,                   KC_W,    KC_E,                KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,                 KC_P,    KC_BSPC, KC_MPLY,
        CTL_T(KC_TAB), KC_A,                   KC_S,    KC_D,                KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,                 KC_ENT,           KC_PGUP,
        KC_LSFT,       KC_Z,                   KC_X,    KC_C,                KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, MT(MOD_RSFT, KC_DOT), KC_UP,            KC_PGDN,
        MO(_LAYER2),   KC_LGUI,                KC_LALT, LT(_LAYER1, KC_SPC),         KC_SPC,          KC_RALT, KC_RCTL, KC_LEFT,              KC_DOWN,          KC_RGHT
    ),

    [_LAYER1] = LAYOUT_split_bar(
        KC_GRV,  KC_1,    KC_2,   KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, _______,
        KC_CAPS, KC_MINS, KC_EQL, KC_LBRC,   KC_RBRC, KC_BSLS, _______, _______, KC_SCLN, KC_QUOT, _______,         _______,
        _______, _______, _______,  _______, _______, _______, _______,  _______, _______, _______, _______,         _______,
        _______, KC_LGUI, _______,  _______,          _______,          _______, _______, _______, _______,         _______
    ),

    [_LAYER2] = LAYOUT_split_bar(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_K, RGB_M_G, RGB_M_R, RGB_M_SW,         UG_HUEU,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, UG_VALU, UG_VALD,          UG_HUED,
        _______, UG_TOGG, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, KC_DEL,  KC_RALT,          KC_RCTL
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_slsh[] = {MT(MOD_RSFT, KC_DOT), KC_COMM, COMBO_END};


combo_t key_combos[] = {
  [COMBO_SLSH] = COMBO(combo_slsh,KC_SLSH),

};
#endif
