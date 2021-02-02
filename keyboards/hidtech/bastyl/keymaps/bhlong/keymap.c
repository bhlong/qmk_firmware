/* 
 * Copyright 2020 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2020 Anthony MARIN <anthony@hidtech.ca>
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

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LGUI_T(KC_T)
#define HOME_W LCA_T(KC_W)
#define HOME_F RCS_T(KC_F)
#define HOME_P SGUI_T(KC_P)

// Right-hand home row mods
#define HOME_N RGUI_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RCTL_T(KC_I)
#define HOME_O LALT_T(KC_O)
#define HOME_L SGUI_T(KC_L)
#define HOME_U RCS_T(KC_U)
#define HOME_Y LCA_T(KC_Y)

// Left thumb keys
#define THMB_L1 LT(_NAV,KC_ESC)
#define THMB_L2 LT(_SYMBOLS,KC_SPC)
#define THMB_L3 LT(_NUMPAD,KC_TAB)

// Right thumb keys
#define THMB_R1 LT(_NUMPAD,KC_ENT)

// Clipboard
#define REDO SGUI(KC_Z)
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define PASTE2 SCMD(LALT(KC_V))

// Rectangle window manager
#define RCTNG_L LCA(KC_LEFT)
#define RCTNG_R LCA(KC_RGHT)

// MacOS
#define SCRNS LSFT(LCMD(KC_3))
#define SCRNS_2 LSFT(LCMD(KC_4))
#define WRKSP_L LCTL(KC_LEFT)
#define WRKSP_R LCTL(KC_RGHT)

// Gaming
#define GAME DF(_GAMING)
#define MAIN DF(_COLEMAK_DH)

enum layers {
    _COLEMAK_DH = 0,
    _SYMBOLS,
    _NAV,
    _NUMPAD,
    _GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
      _______,    KC_5,    KC_3,    KC_1,    KC_7,    KC_9,       KC_8,    KC_6,    KC_0,    KC_2,    KC_4, _______,
      KC_MINS,    KC_Q,  HOME_W,  HOME_F,  HOME_P,    KC_B,       KC_J,  HOME_L,  HOME_U,  HOME_Y, KC_SCLN,  KC_EQL,
      KC_UNDS,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,       KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O, KC_QUOT,
       KC_GRV,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
                                 THMB_L1, THMB_L2, THMB_L3,       KC_DEL, KC_BSPC, THMB_R1,
                                          _______,    GAME,       _______, _______),

    [_SYMBOLS] = LAYOUT(
        RESET, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_AMPR, KC_LBRC, KC_RBRC, KC_EXLM, KC_CIRC, _______,
         REDO,    UNDO,     CUT,    COPY,   PASTE,  PASTE2,                                      KC_DLR, KC_LPRN, KC_RPRN, KC_ASTR, KC_PERC, _______,
      _______, _______, _______,   SCRNS, SCRNS_2, _______,                                     KC_HASH, KC_LCBR, KC_RCBR,   KC_AT, KC_TILD, _______,
                                 _______, _______, _______,                                     _______, _______, _______, 
                                          _______, _______,                                     _______, _______),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, WRKSP_L,   KC_UP, WRKSP_R, _______, _______,
      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, _______, _______, KC_BRID, KC_BRIU, _______,                                     _______, RCTNG_L,  RCTNG_R, KC_CAPS, _______, _______,
                                 _______, _______, _______,                                     _______, _______, _______,
                                          _______, _______,                                     _______, _______),

    [_NUMPAD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,                                     _______,   KC_6,   KC_7,   KC_8, _______, _______,
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,                                     _______,   KC_0,   KC_1,   KC_2,   KC_9, _______,
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______,   KC_3,   KC_4,   KC_5, _______, _______,
                                 _______, _______, _______,                                     _______, _______, _______,
                                          _______, _______,                                     _______, _______),

    [_GAMING] = LAYOUT(
      _______,    KC_5,    KC_3,    KC_1,    KC_7,    KC_9,                                        KC_8,    KC_6,    KC_0,    KC_2,    KC_4, _______,
      KC_MINS,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_EQL,
      KC_UNDS,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
       KC_GRV,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                        KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_BSLS,
                                  KC_ESC,  KC_SPC,  KC_TAB,                                        KC_DEL, KC_BSPC,  KC_ENT,
                                          _______,    MAIN,                                        _______, _______),
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_MAGENTA);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif