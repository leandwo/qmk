#include "zygote.h"
#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

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

const uint16_t PROGMEM wf_combo[]     = {KC_W,    KC_F,    COMBO_END};
const uint16_t PROGMEM uy_combo[]     = {KC_U,    KC_Y,    COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [COMBO_STAB]  = COMBO(wf_combo,     LSFT(KC_TAB)),
  [COMBO_TAB]  = COMBO(uy_combo,     KC_TAB),
};


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
  [_BASE] = LAYOUT(
      KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,    _______,   _______,   KC_J,    KC_L,         KC_U,         KC_Y,         KC_BSPC,
      MT_A,         MT_R,         MT_S,         MT_T,         KC_G,    _______,   _______,   KC_M,    MT_N,         MT_E,         MT_I,         MT_O,
      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,    _______,   _______,   KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
      _______,      _______,      _______,      MEH_ESC,       NAV_SPC, MOUSE_ENT, OSL_SYM, OSL_NUM, OSM_SHIFT,      _______,      _______,      _______
      ),
  [_NAV] = LAYOUT(
      KC_MPRV,      KC_MNXT,      KC_VOLD,      KC_VOLU,      KC_MPLY, _______,   _______,   KC_PGDN, KC_END,       KC_UP,        _______,      _______,
      KC_LSFT,      KC_LGUI,      KC_LALT,      KC_LCTL,      _______, _______,   _______,   KC_DEL,  KC_LEFT,      KC_DOWN,      KC_RGHT,      KC_INS,
      RGB_RMOD,     RGB_MOD,      RGB_VAD,      RGB_VAI,      RGB_TOG, _______,   _______,   KC_PGUP, KC_HOME,      _______,      _______,      _______,
      _______,      _______,      _______,      _______,      KC_TRNS, _______,   _______,   KC_TAB,  _______,      _______,      _______,      _______
      ),
  [_NUMBER] = LAYOUT(
      KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, _______,   _______,   KC_CIRC, KC_AMPR,      KC_ASTR,      KC_DOT,       KC_COMM,
      LSFT_T(KC_1), LGUI_T(KC_2), LALT_T(KC_3), LCTL_T(KC_4), KC_5,    _______,   _______,   KC_6,    RCTL_T(KC_7), RALT_T(KC_8), RGUI_T(KC_9), RSFT_T(KC_0),
      KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,   _______,   _______,   KC_F6,   KC_F7,        KC_F8,        KC_F9,        KC_F10,
      _______,      KC_F11,       KC_F12,       KC_K,         KC_J,    _______,   _______,   KC_TRNS, _______,      _______,      _______,      KC_J
      ),
  [_SYMBOL] = LAYOUT(
      KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, _______,   _______,   KC_CIRC, KC_AMPR,      KC_ASTR,      KC_COLN,      KC_SCLN,
      KC_LBRC,      KC_LCBR,      KC_LPRN,      KC_DQT,       KC_QUOT, _______,   _______,   KC_QUOT, KC_DQT,       KC_RPRN,      KC_RCBR,      KC_RBRC,
      KC_MINUS,     KC_UNDS,      KC_TILDE,     KC_GRAVE,     _______, _______,   _______,   _______, KC_BSLS,      KC_PIPE,      KC_PLUS,      KC_EQUAL,
      _______,      _______,      _______,      _______,      KC_SPC,  _______,   _______,   _______, _______,      _______,      _______,      _______
      ),
  [_MOUSE] = LAYOUT(
      RESET,        _______,      _______,      _______,      _______, _______,   _______,   _______, _______,      KC_MS_U,      _______,      _______,
      _______,      KC_BTN2,      KC_BTN3,      KC_BTN1,      _______, _______,   _______,   _______, KC_MS_L,      KC_MS_D,      KC_MS_R,      _______,
      _______,      _______,      _______,      _______,      _______, _______,   _______,   _______, _______,      _______,      _______,      _______,
      _______,      _______,      _______,      _______,      _______, _______,   _______,   _______, _______,      _______,      _______,      _______
      ),
};

void matrix_scan_user(void) {
  return;
};
