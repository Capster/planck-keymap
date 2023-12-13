/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// http://ciantic.github.io/keymapceditor/

#include QMK_KEYBOARD_H
// #include "keymap_steno.h"

// https://getreuer.info/posts/keyboards/achordion/index.html
#include "features/achordion.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  // _COLEMAK,
  // _DVORAK,
  _LOWER,
  _RAISE,
  // _PLOVER,
  _GAMING,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  // COLEMAK,
  // DVORAK,
  // PLOVER,
  GAMING,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

// #define ST_BOLT QK_STENO_BOLT
// #define ST_GEM  QK_STENO_GEMINI

#define I XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,               I,I, KC_Y,  KC_U,         KC_I,         KC_O,         KC_P,
  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,               I,I, KC_H,  RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,               I,I, KC_N,  KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
  KC_HYPR,      XXXXXXX,      XXXXXXX,      KC_SPC,       LT(_LOWER, KC_ENT), I,I, RAISE, KC_BSPC,      XXXXXXX,      XXXXXXX,      XXXXXXX
),

[_LOWER] = LAYOUT_planck_grid(
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, I,I, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, I,I, KC_BSLS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  _______, _______, _______, _______, _______, I,I, _______, _______, KC_INS,  KC_HOME, KC_END,
  _______, _______, _______, KC_BTN3, _______, I,I, _______, KC_ESC,  _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    I,I, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TILD, KC_GRV,  CW_TOGG, KC_QUOT, KC_DEL,  I,I, KC_PIPE, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
  _______, _______, _______, _______, _______, I,I, _______, _______, _______, KC_PGUP, KC_PGDN,
  _______, _______, _______, KC_TAB,  _______, I,I, _______, _______, _______, _______, _______
),

[_GAMING] = LAYOUT_planck_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_HYPR,
  KC_LCTL, KC_Z,    KC_X,    KC_SPC,  KC_C,    KC_B,    LOWER,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_ADJUST] = LAYOUT_planck_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   I,I, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_F11,  KC_F12,  _______, _______, _______, I,I, _______, _______, _______, _______, _______,
  QK_BOOT, DB_TOGG, _______, _______, _______, I,I, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, I,I, _______, _______, _______, QWERTY,  GAMING
)

};

// [_COLEMAK] = LAYOUT_planck_grid(
//   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
//   KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
//   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
//   BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

// [_DVORAK] = LAYOUT_planck_grid(
//   KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
//   KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
//   KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
//   BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
// ),

/*[_PLOVER] = LAYOUT_planck_grid(*/
  /*STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  EXT_PLV , // STN_NC*/
  /*STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,*/
  /*XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,*/
  /*XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2*/
/*),*/

// [_PLOVER] = LAYOUT_planck_grid(
//   STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR ,
//   XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR ,
//   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC ,
//   EXT_PLV, XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
// ),

// void matrix_init_user() {
//   steno_set_mode(STENO_MODE_BOLT);
//   /*steno_set_mode(STENO_MODE_GEMINI);*/
// }

void matrix_scan_user(void) {
  achordion_task();
}

// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
// #endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
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
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //   }
    //   return false;
    //   break;
    // case PLOVER:
    //   if (!record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       stop_all_notes();
    //       PLAY_SONG(plover_song);
    //     #endif
    //     layer_on(_PLOVER);
    //   }
    //   return false;
    //   break;
    // case EXT_PLV:
    //   if (record->event.pressed) {
    //     #ifdef AUDIO_ENABLE
    //       PLAY_SONG(plover_gb_song);
    //     #endif
    //     layer_off(_PLOVER);
    //   }
    //   return false;
    //   break;
    if (!process_achordion(keycode, record)) { return false; }
  }
  return true;
}
