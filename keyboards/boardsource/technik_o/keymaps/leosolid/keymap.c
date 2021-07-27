#include "technik_o.h"
#include QMK_KEYBOARD_H

// TODO RBG highlight OSM and LEADER key pending
// TODO get MBK legend glows
// QMK Features to try
// - COMBOS
// - TAP DANCE
// - LEADER

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
#define OSM_SHIFT OSM(MOD_LSFT)
/* #define YA_MOD    OSM(MOD_LSFT|MOD_LALT|MOD_LGUI) */
#define KI_GCA    OSM(MOD_LCTL|MOD_LALT|MOD_LGUI)
#define KI_GCS    OSM(MOD_LCTL|MOD_LSFT|MOD_LGUI)
#define NEO_CA    OSM(MOD_LALT|MOD_LCTL)
#define NEO_CS    OSM(MOD_LSFT|MOD_LCTL)

// mod-taps
#define MT_A LSFT_T(KC_A)
#define MT_R LGUI_T(KC_R)
#define MT_S LSFT_T(KC_S)
#define MT_T LCTL_T(KC_T)

#define MT_O RSFT_T(KC_O)
#define MT_I RGUI_T(KC_I)
#define MT_E RSFT_T(KC_E)
#define MT_N RCTL_T(KC_N)

// COMBOS
enum combos {
  ZX_BSPC,
  IO_ENTR,
  DOTSLASH_TAB,

  FP_LCBR,
  LU_RCBR,

  ST_LPRN,
  NE_RPRN,

  CD_LBRC,
  HCOM_RBRC,
};

const uint16_t PROGMEM zx_combo[]       = {KC_Z,   KC_X,    COMBO_END};
const uint16_t PROGMEM io_combo[]       = {MT_I,   MT_O,    COMBO_END};
const uint16_t PROGMEM dotslash_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

const uint16_t PROGMEM fp_combo[]       = {KC_F,   KC_P,    COMBO_END};
const uint16_t PROGMEM lu_combo[]       = {KC_L,   KC_U,    COMBO_END};

const uint16_t PROGMEM st_combo[]       = {KC_S,   KC_T,    COMBO_END};
const uint16_t PROGMEM ne_combo[]       = {KC_N,   KC_E,    COMBO_END};

const uint16_t PROGMEM cd_combo[]       = {KC_C,   KC_D,    COMBO_END};
const uint16_t PROGMEM hcom_combo[]     = {KC_H,   KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZX_BSPC]      = COMBO(zx_combo,       KC_BSPC),
  [IO_ENTR]      = COMBO(io_combo,       KC_ENT),
  [DOTSLASH_TAB] = COMBO(dotslash_combo, KC_TAB),

  [FP_LCBR]      = COMBO(fp_combo,       KC_LCBR),
  [LU_RCBR]      = COMBO(lu_combo,       KC_RCBR),

  [ST_LPRN]      = COMBO(st_combo,       KC_LPRN),
  [NE_RPRN]      = COMBO(ne_combo,       KC_RPRN),

  [CD_LBRC]      = COMBO(cd_combo,       KC_LBRC),
  [HCOM_RBRC]    = COMBO(hcom_combo,     KC_RBRC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_GRAVE, KC_Q,   KC_W,   KC_F,    KC_P,    KC_B,   /**/ KC_J,    KC_L,      KC_U,      KC_Y,   KC_SCOLON, KC_BSLS,
    KC_BSPC,  MT_A,   MT_R,   MT_S,    MT_T,    KC_G,   /**/ KC_M,    MT_N,      MT_E,      MT_I,   MT_O,      KC_QUOT,
    KC_MINUS, KC_Z,   KC_X,   KC_C,    KC_D,    KC_V,   /**/ KC_K,    KC_H,      KC_COMM,   KC_DOT, KC_SLSH,   KC_EQUAL,
    KC_ESC,   NEO_CS, NEO_CA, OSM_MEH, NAV_SPC, KC_TAB, /**/ OSL_NUM, OSM_SHIFT, OSM_HYPER, KI_GCA, KI_GCS,    KC_ENT
  ),
  [_NAV] = LAYOUT_ortho_4x12(
    KC_MPLY, KC_MPRV,  KC_MNXT, KC_VOLD, KC_VOLU, _______, /**/ KC_PGDN, KC_END,  KC_UP,   _______, _______, RESET,
    _______, KC_LSFT,  KC_LGUI, KC_LALT, KC_LCTL, _______, /**/ KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  _______,
    RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, _______, /**/ KC_PGUP, KC_HOME, _______, _______, _______, _______,
    _______, XXXXXXX,  XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, /**/ _______, _______, _______, _______, _______, _______

  ),
  [_NUMBER] = LAYOUT_ortho_4x12(
    _______, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC, /**/ KC_CIRC, KC_AMPR,      KC_ASTR,      KC_DOT,       KC_COMM,      _______,
    _______, LSFT_T(KC_1), LGUI_T(KC_2), LALT_T(KC_3), LCTL_T(KC_4), KC_5,    /**/ KC_6,    RCTL_T(KC_7), RALT_T(KC_8), RGUI_T(KC_9), RSFT_T(KC_0), _______,
    _______, KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,   /**/ KC_F6,   KC_F7,        KC_F8,        KC_F9,        KC_F10,       _______,
    _______, KC_F11,       KC_F12,       _______,      _______,      _______, /**/ KC_TRNS, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______
  )
  /* [_RGB] = LAYOUT_ortho_4x12( */
  /*   /1* _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, *1/ */
  /*   /1* _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, *1/ */
  /*   /1* _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, *1/ */
  /*   /1* _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  *1/ */
  /* ) */
};

