
// TODO RBG highlight OSM and LEADER key pending
// TODO get MBK legend glows

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _NUMBER,
    _FUNCTION,
    _RGB
};

// readability keycodes
#define XXXXXXX   KC_NO
#define _______   KC_TRNS
// LT, layer toggles
#define NAV_SPC   LT(_NAV,KC_SPACE)
#define MOUSE_ESC LT(_MOUSE,KC_ESC)
#define RGB_ESC   LT(_RGB,KC_ESC)
// OSL, one shot layers
#define OSL_NUM   OSL(_NUMBER)
// OSM, one shot modifiers
#define OSM_HYPER OSM(MOD_HYPR)
#define OSM_MEH   OSM(MOD_MEH)
#define OSM_SHIFT OSM(SHIFT)
/* #define YA_MOD    OSM(MOD_LSFT|MOD_LALT|MOD_GUI) */
#define KI_GAC    OSM(MOD_LCTL|MOD_LALT|MOD_GUI)
#define KI_SCG    OSM(MOD_LCTL|MOD_LSFT|MOD_GUI)
#define NEO_CA    OSM(MOD_LALT|MOD_LCTL)
#define NEO_CS    OSM(MOD_LSFT|MOD_LCTL)
/* #define SUPER   */
/* #define DUPER   */
/* #define POOPER  */
/* #define SCOOPER */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_GRAVE, KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,    /**/ KC_J,    KC_L,        KC_U,         KC_Y,         KC_SCOLON,    KC_BSLS,
    KC_BSPC,  LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_G,    /**/ KC_M,    RCT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RSFT_T(KC_O), KC_QUOT,
    KC_MINUS, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,    /**/ KC_K,    KC_H,        KC_COMM,      KC_DOT,       KC_SLSH,      KC_EQUAL,
    KC_ESC,   NEO_CS,       NEO_CA,       KI_GAC/*KM*/, NAV_SPC,      KC_LEAD, /**/ OSL_NUM, OSM_MEH,     OSM_SHIFT,    OSM_HYPER,    KI_SCG,       KC_ENT
  ),
  [_NAV] = LAYOUT_ortho_4x12(
    KC_MPLY, KC_MPRV,  KC_MNXT, KC_VOLD, KC_VOLU, _______, /**/ KC_PGDN, KC_END,  KC_UP,   _______, _______, _______,
    _______, KC_LSFT,  KC_LGUI, KC_LALT, KC_LCTL, _______, /**/ KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
    RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, _______, /**/ KC_PGUP, KC_HOME, _______, _______, _______, _______,
    _______, XXXXXXX,  XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, /**/ _______, _______, _______, _______, _______, _______

  ),
  [_NUMBER] = LAYOUT_ortho_4x12(
    _______, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, /**/ KC_CIRC, KC_AMPR,     KC_ASTR,      KC_DOT,       KC_COMM,      _______,
    _______, LSFT_T(KC_1), LGUI_T(KC_2), LALT_T(KC_3), LCTL_T(KC_4), KC_5,    /**/ KC_6,    RCT_T(KC_7), RALT_T(KC_8), RGUI_T(KC_9), RSFT_T(KC_0), _______,
    _______, KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,   /**/ KC_F6,   KC_F7,       KC_F8,        KC_F9,        KC_F10,       _______,
    _______, KC_F11,       KC_F12,       _______,      _______,      _______, /**/ KC_TRNS, XXXXXXX,     XXXXXXX,      XXXXXXX,      XXXXXXX,      _______
  ),
  [_RGB] = LAYOUT_ortho_4x12(
    /* _______, _______, _______, _______, _______, _______, KC_CIRC, KC_AMPR,     KC_ASTR,      KC_DOT,       KC_COMM,      _______, */
    /* _______, _______, _______, _______, _______, _______, _______, RCT_T(KC_7), RALT_T(KC_8), RGUI_T(KC_9), RSFT_T(KC_0), _______, */
    /* _______, _______, _______, _______, _______, _______, KC_F6,   KC_F7,       KC_F8,        KC_F9,        KC_F10,       _______, */
    /* _______, _______, _______, _______, _______, _______, KC_TRNS, XXXXXXX,     XXXXXXX,      XXXXXXX,      XXXXXXX,      _______  */
  )
};

