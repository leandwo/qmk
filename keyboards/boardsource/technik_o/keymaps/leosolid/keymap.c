// TODO RBG highlight OSM and LEADER key pending
// TODO get MBK legend glows


#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _NUMBER,
    _FUNCTION
};

// Readability keycodes
#define XXXXXXX KC_NO
#define _______ KC_TRNS

// LT, Layer Toggles
#define NAV_SPC   LT(_NAV,KC_SPACE)
#define MOUSE_ESC LT(_MOUSE,KC_ESC)

// OSL, One Shot Layers
#define OSL_NUM   OSL(_NUMBER)

// OSM, One Shot Modifier
#define OSM_SHIFT OSM(SHIFT)
#define OSM_HYPER OSM(MOD_HYPR)
#define OSM_MEH   OSM(MOD_MEH)
#define OSM_CAG   OSM(MOD_LCTL|MOD_LALT|MOD_GUI)
#define OSM_SAG   OSM(MOD_LSFT|MOD_LALT|MOD_GUI)
#define OSM_SUPER OSM(MOD_LCTL|MOD_LSFT|MOD_GUI) // CSG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(

    KC_GRAVE, KC_Q,         KC_W,        KC_F,         KC_P,         KC_B,    KC_J,    KC_L,        KC_U,         KC_Y,         KC_SCOLON,    KC_BSLS,
    KC_BSPC,  LSFT_T(KC_A), LGUI_T(KC_R, LALT_T(KC_S), LCTL_T(KC_T), KC_G,    KC_M,    RCT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RSFT_T(KC_O), KC_QUOT,
    KC_MINUS, KC_Z,         KC_X,        KC_C,         KC_D,         KC_V,    KC_K,    KC_H,        KC_COMM,      KC_DOT,       KC_SLSH,      KC_EQUAL,
    KC_ESC,   _______,      _______,     KC_LEAD,      NAV,          _______, OSL_NUM, KC_ENT,      OSM_SHIFT,    _______,      _______,      ______
    //MOUSE   ?             ?            ?             ?             ?        ?        ?            ?             ?             ?             ?

  ),
  [_NAV] = LAYOUT_ortho_4x12(

    _______, _______, _______, _______, _______, _______, KC_PGDN, KC_END,  KC_UP,   _______, _______, _______, \
    _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______, \
    _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \

  ),
  [_NUMBER] = LAYOUT_ortho_4x12(

     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
     RGB_MOD, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

  )

};

