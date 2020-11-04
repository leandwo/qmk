#include "zygote.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers
{
	_BASE,
	_NAV,
	_MOUSE,
  _SYMBOL,
  _FUNCTION,
  _GAMING,
  _QWERTY
};

enum custom_keycodes
{
  BASE = SAFE_RANGE,
	NAV,
	MOUSE,
  SYMBOL,
  FUNCTION,
  GAMING,
  QWERTY
};

// Fillers to make layering more clear
#define XXXXXXX KC_NO
#define _______ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT( \
KC_Q,KC_W,KC_F,KC_P,KC_B,KC_NO,KC_NO,KC_J,KC_L,KC_U,KC_Y,KC_SCOLON, \
LSFT_T(KC_A),LGUI_T(KC_R),LALT_T(KC_S),LCTL_T(KC_T),KC_G,KC_NO,KC_NO,KC_M,RCTL_T(KC_N),RALT_T(KC_E),RGUI_T(KC_I),RSFT_T(KC_O), \
KC_Z,KC_X,KC_C,KC_D,KC_V,KC_MINUS,KC_EQUAL,KC_K,KC_H,KC_COMM,KC_DOT,KC_SLSH, \
KC_ESC,LCA(KC_1),LCA(KC_2),KC_BSPC,LT(1, KC_SPC),LT(2,KC_TAB),OSL(3), LT(4, KC_ENT),OSM(MOD_RSFT),KC_VOLD,KC_VOLU,KC_QUOTE \
),

[1] = LAYOUT( \
_______,_______,_______,_______,_______,KC_NO,KC_NO,_______,_______,KC_UP,_______,_______, \
KC_LSFT,KC_LGUI,KC_LALT,KC_LCTL,_______,KC_NO,KC_NO,KC_BSPC,KC_LEFT,KC_DOWN,KC_RGHT,_______, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_K,_______, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_H,KC_J,KC_L \
),

[2] = LAYOUT( \
_______,_______,_______,_______,_______,KC_NO,KC_NO,_______,_______,KC_MS_U,_______,_______, \
_______,KC_BTN2,KC_BTN3,KC_BTN1,_______,KC_NO,KC_NO,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______ \
),

[3] = LAYOUT( \
KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_NO,KC_NO,KC_CIRC,KC_AMPR,KC_ASTR,_______,KC_DOUBLE_QUOTE, \
KC_1,KC_2,KC_3,KC_4,KC_5,KC_NO,KC_NO,KC_6,KC_7,KC_8,KC_9,KC_0, \
KC_GRAVE,KC_LCBR,KC_LBRC,KC_LPRN,KC_TILDE,_______,_______,KC_PIPE,KC_RPRN,KC_RBRC,KC_RCBR,KC_BSLS, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______ \
),

[4] = LAYOUT( \
KC_F11,KC_F12,KC_F13,KC_F14,KC_F15,KC_NO,KC_NO,KC_F16,KC_F17,KC_F18,KC_F19,KC_NO, \
KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_NO,KC_NO,KC_F6,KC_F7,KC_8,KC_F9,KC_F10, \
_______,_______,_______,_______,_______,_______,_______,KC_MPLY,KC_MPRV,KC_MNXT,KC_VOLD,KC_VOLU, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_BRID,KC_BRIU,MO(7) \
),

[5] = LAYOUT( \
KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_NO,KC_NO,_______,_______,_______,_______,_______, \
KC_LCTL,KC_A,KC_S,KC_D, KC_F,KC_NO,KC_NO,_______,_______,_______,_______,_______, \
KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_5,_______,_______,_______,_______,_______,_______, \
_______,KC_1,KC_2,KC_3,_______,KC_4,_______,_______,_______,_______,_______,_______ \
),

[6] = LAYOUT( \
KC_Q,KC_W,KC_E,KC_R,KC_T,KC_NO,KC_NO,KC_Y,KC_U,KC_I,KC_O,KC_P, \
KC_A,KC_S,KC_D,KC_F,KC_G,KC_NO,KC_NO,KC_H,KC_J,KC_K,KC_L,KC_SCOLON, \
KC_Z,KC_X,KC_C,KC_V,KC_B,_______,_______,KC_N,KC_M,_______,_______,_______, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______ \
),

[7] = LAYOUT( \
TO(6),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
_______,_______,_______,_______,TO(5),_______,_______,_______,_______,_______,_______,_______, \
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
TO(0),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______ \
)


};
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case LOWER: */
/*       if (record->event.pressed) { */
/*         layer_on(_LOWER); */
/*       } else { */
/*         layer_off(_LOWER); */
/*       } */
/*       return false; */
/*       break; */

/*     case RAISE: */
/*       if (record->event.pressed) { */
/*         layer_on(_RAISE); */
/*       } else { */
/*         layer_off(_RAISE); */
/*       } */
/*       return false; */
/*       break; */


/*   } */
/*   return true; */
/* } */

void matrix_scan_user(void) {
		return;
};
