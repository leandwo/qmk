#include "technik_o.h"
#include QMK_KEYBOARD_H

// TODO get MBK legend glows

// TODO QMK Features to try
// - LEADER

// readability keycodes
#define XXXXXXX   KC_NO
#define _______   KC_TRNS

// LT, layer toggles
#define NAV_SPC   LT(_NAV,KC_SPACE)
#define MOUSE_ENT   LT(_MOUSE, KC_ENT)

// OSL, one shot layers
#define OSL_NUM   OSL(_NUMBER)
#define OSL_SYM   OSL(_SYMBOL)

// OSM, one shot modifiers
#define OSM_HYPER OSM(MOD_HYPR)
#define OSM_MEH   OSM(MOD_MEH)
#define OSM_SHIFT OSM(MOD_LSFT)
/* #define YA_MOD    OSM(MOD_LSFT|MOD_LALT|MOD_LGUI) */
#define KI_GCA    OSM(MOD_LCTL|MOD_LALT|MOD_LGUI)
#define KI_GCS    OSM(MOD_LCTL|MOD_LSFT|MOD_LGUI)
#define NEO_CA    OSM(MOD_LALT|MOD_LCTL)
#define NEO_CS    OSM(MOD_LSFT|MOD_LCTL)

// mod-taps
#define MT_A LSFT_T(KC_A)
#define MT_R LGUI_T(KC_R)
#define MT_S LALT_T(KC_S)
#define MT_T LCTL_T(KC_T)
#define MT_O RSFT_T(KC_O)
#define MT_I RGUI_T(KC_I)
#define MT_E RALT_T(KC_E)
#define MT_N RCTL_T(KC_N)

#define MT_TAB RSFT_T(KC_TAB)
#define MEH_ESC MEH_T(KC_ESC)

/**********/
/* COMBOS */
/**********/

// TODO move to combo file
enum combos {
  COMBO_TAB,
  COMBO_STAB,
};

/* // left hand */
/* const uint16_t PROGMEM qw_combo[]     = {KC_Q,    KC_W,    COMBO_END}; */
const uint16_t PROGMEM wf_combo[]     = {KC_W,    KC_F,    COMBO_END};
/* const uint16_t PROGMEM fp_combo[]     = {KC_F,    KC_P,    COMBO_END}; */

/* const uint16_t PROGMEM ar_combo[]     = {MT_A,    MT_R,    COMBO_END}; */
/* const uint16_t PROGMEM rs_combo[]     = {MT_R,    MT_S,    COMBO_END}; */
/* const uint16_t PROGMEM st_combo[]     = {MT_S,    MT_T,    COMBO_END}; */

/* const uint16_t PROGMEM xc_combo[]     = {KC_X,    KC_C,    COMBO_END}; */

/* // right hand */
/* const uint16_t PROGMEM lu_combo[]     = {KC_L,    KC_U,    COMBO_END}; */
const uint16_t PROGMEM uy_combo[]     = {KC_U,    KC_Y,    COMBO_END};
/* const uint16_t PROGMEM ycol_combo[]   = {KC_Y,    KC_SCLN, COMBO_END}; */

/* const uint16_t PROGMEM ei_combo[]     = {MT_E,    MT_I,    COMBO_END}; */

/* const uint16_t PROGMEM comdot_combo[] = {KC_COMM, KC_DOT,  COMBO_END}; */

combo_t key_combos[COMBO_COUNT] = {

  /* [COMBO_ESC]  = COMBO(wf_combo,     KC_ESC), */
  /* [COMBO_BSPC] = COMBO(rs_combo,     KC_BSPC), */
  [COMBO_STAB]  = COMBO(wf_combo,     LSFT(KC_TAB)),
  [COMBO_TAB]  = COMBO(uy_combo,     KC_TAB),
  /* [COMBO_ENT]  = COMBO(ei_combo,     KC_ENT), */
  /* [COMBO_COLN] = COMBO(xc_combo,     KC_COLN), */

};



/*************/
/* tap dance */
/*************/

// Tap Dance declarations
/* enum { */
/*     TD_QT_DQT, */
/*     CT_CLN */
/* }; */

/* void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         register_code16(KC_COLN); */
/*     } else { */
/*         register_code(KC_SCLN); */
/*     } */
/* } */

/* void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*     if (state->count == 1) { */
/*         unregister_code16(KC_COLN); */
/*     } else { */
/*         unregister_code(KC_SCLN); */
/*     } */
/* } */

/* // All tap dance functions would go here. Only showing this one. */
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     [TD_QT_DQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT), */
/*     [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset), */
/* }; */


/**********/
/* layers */
/**********/

enum layers {
  _BASE,
  _NAV,
  _NUMBER,
  _SYMBOL,
  _MOUSE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
      KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,    _______,   _______,   KC_J,    KC_L,         KC_U,         KC_Y,         KC_BSPC,
      MT_A,         MT_R,         MT_S,         MT_T,         KC_G,    _______,   _______,   KC_M,    MT_N,         MT_E,         MT_I,         MT_O,
      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,    _______,   _______,   KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
      _______,      _______,      _______,      MEH_ESC,       NAV_SPC, MOUSE_ENT, OSL_SYM, OSL_NUM, OSM_SHIFT,      _______,      _______,      _______
      ),
  [_NAV] = LAYOUT_ortho_4x12(
      KC_MPRV,      KC_MNXT,      KC_VOLD,      KC_VOLU,      KC_MPLY, _______,   _______,   KC_PGDN, KC_END,       KC_UP,        _______,      _______,
      KC_LSFT,      KC_LGUI,      KC_LALT,      KC_LCTL,      _______, _______,   _______,   KC_DEL,  KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_INS,
      RGB_RMOD,     RGB_MOD,      RGB_VAD,      RGB_VAI,      RGB_TOG, _______,   _______,   KC_PGUP, KC_HOME,      _______,      _______,      _______,
      _______,      _______,      _______,      _______,      KC_TRNS, _______,   _______,   KC_TAB,  _______,      _______,      _______,      _______
      ),
  [_NUMBER] = LAYOUT_ortho_4x12(
      KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, _______,   _______,   KC_CIRC, KC_AMPR,      KC_ASTR,      KC_DOT,       KC_COMM,
      LSFT_T(KC_1), LGUI_T(KC_2), LALT_T(KC_3), LCTL_T(KC_4), KC_5,    _______,   _______,   KC_6,    RCTL_T(KC_7), RALT_T(KC_8), RGUI_T(KC_9), RSFT_T(KC_0),
      KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,   _______,   _______,   KC_F6,   KC_F7,        KC_F8,        KC_F9,        KC_F10,
      _______,      KC_F11,       KC_F12,       KC_K,         KC_J,    _______,   _______,   KC_TRNS, _______,      _______,      _______,      KC_J
      ),
  [_SYMBOL] = LAYOUT_ortho_4x12(
      KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, _______,   _______,   KC_CIRC, KC_AMPR,      KC_ASTR,      KC_COLN,      KC_SCLN,
      KC_LBRC,      KC_LCBR,      KC_LPRN,      KC_DQT,       KC_QUOT, _______,   _______,   KC_QUOT, KC_DQT,       KC_RPRN,      KC_RCBR,      KC_RBRC,
      KC_MINUS,     KC_UNDS,      KC_TILDE,     KC_GRAVE,     _______, _______,   _______,   _______, KC_BSLS,      KC_PIPE,      KC_PLUS,      KC_EQUAL,
      _______,      _______,      _______,      _______,      KC_SPC,  _______,   _______,   _______, _______,      _______,      _______,      _______
      ),
  [_MOUSE] = LAYOUT_ortho_4x12(
      RESET,        _______,      _______,      _______,      _______, _______,   _______,   _______, _______,      KC_MS_U,      _______,      _______,
      _______,      KC_BTN2,      KC_BTN3,      KC_BTN1,      _______, _______,   _______,   _______, KC_MS_L,      KC_MS_D,      KC_MS_R,      _______,
      _______,      _______,      _______,      _______,      _______, _______,   _______,   _______, _______,      _______,      _______,      _______,
      _______,      _______,      _______,      _______,      _______, _______,   _______,   _______, _______,      _______,      _______,      _______
      ),
};


/*******/
/* RGB */
/*******/

void rgb_matrix_indicators_kb(void) {
  rgb_matrix_set_color_all(0, 0, 0);
  switch (biton32(layer_state)) {
    case _MOUSE:
      rgb_matrix_set_color(46, 64, 128, 0);
      rgb_matrix_set_color(24, 64, 128, 0);
      rgb_matrix_set_color(25, 64, 128, 0);
      rgb_matrix_set_color(26, 64, 128, 0);
      rgb_matrix_set_color(18, 64, 128, 0);
      rgb_matrix_set_color(29, 64, 128, 0);
      rgb_matrix_set_color(30, 64, 128, 0);
      rgb_matrix_set_color(31, 64, 128, 0);
      for (uint8_t i = 0; i <= 9; i++) {
        rgb_matrix_set_color(i, 64, 128, 0);
      }
      break;
    case _NUMBER:
      rgb_matrix_set_color(52, 64, 0, 128);
      for (uint8_t i = 0; i <= 9; i++) {
        rgb_matrix_set_color(i, 64, 0, 128);
      }
      break;
    case _SYMBOL:
      rgb_matrix_set_color(53, 0, 128, 64);
      for (uint8_t i = 0; i <= 9; i++) {
        rgb_matrix_set_color(i, 0, 128, 64);
      }
      break;
    case _NAV:
      rgb_matrix_set_color(51, 0, 64, 128);
      rgb_matrix_set_color(18, 0, 64, 128);
      rgb_matrix_set_color(29, 0, 64, 128);
      rgb_matrix_set_color(30, 0, 64, 128);
      rgb_matrix_set_color(31, 0, 64, 128);
      for (uint8_t i = 0; i <= 9; i++) {
        rgb_matrix_set_color(i, 0, 64, 128);
      }
      break;
    default:
      break;
  }

    uint8_t mods = get_mods() | get_oneshot_locked_mods() | get_oneshot_mods();
    uint8_t shift_on = mods & MOD_MASK_SHIFT;
    uint8_t gui_on   = mods & MOD_MASK_GUI;
    uint8_t alt_on   = mods & MOD_MASK_ALT;
    uint8_t ctrl_on  = mods & MOD_MASK_CTRL;

    if (shift_on) {
      rgb_matrix_set_color(23, 128, 64, 0);
      rgb_matrix_set_color(32, 128, 64, 0);
      rgb_matrix_set_color(50, 128, 64, 0);
      rgb_matrix_set_color(9, 128, 64, 0);
      rgb_matrix_set_color(4, 128, 64, 0);
    }
    if (gui_on) { 
      rgb_matrix_set_color(24, 64, 128, 0);
      rgb_matrix_set_color(31, 64, 128, 0);
      rgb_matrix_set_color(8, 64, 128, 0);
      rgb_matrix_set_color(3, 64, 128, 0);
    }  
    if (alt_on) { 
      rgb_matrix_set_color(25, 0, 128, 64);
      rgb_matrix_set_color(30, 0, 128, 64);
      rgb_matrix_set_color(7, 0, 128, 64);
      rgb_matrix_set_color(2, 0, 128, 64);
    }  
    if (ctrl_on) { 
      rgb_matrix_set_color(26, 0, 64, 128);
      rgb_matrix_set_color(29, 0, 64, 128);
      rgb_matrix_set_color(6, 0, 64, 128);
      rgb_matrix_set_color(1, 0, 64, 128);
    }  
}
