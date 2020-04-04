#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define SPCFN LT(_FUNCTION, KC_SPC)
#define DSKL LCTL(LGUI(KC_LEFT))
#define DSKR LCTL(LGUI(KC_RIGHT))
#define FRWRD LALT(KC_RIGHT)
#define BK LALT(KC_LEFT)
#define ALTF4 LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   /  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  "   | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower | SpcFn| Space|Raise |  \   | Down |  Up  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC, 	 KC_A,   KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_SLSH,
  OSM(MOD_LSFT), KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_DQT,  OSM(MOD_RSFT),
  KC_LCTL,       KC_GRV, KC_LGUI, KC_LALT, LOWER, SPCFN , KC_SPC, RAISE, KC_BSLS, KC_DOWN, KC_UP,   KC_ENT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |  Up  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp | Ins  |Raise |      | Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_ENT,
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, KC_UP,   KC_PIPE,
  _______, _______,  _______, _______, _______, KC_BSPC, KC_INS,  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 |  F12 |ISO # |ISO / | Mute |  '   |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_1,    KC_2,  KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_4,    KC_5,  KC_6,   KC_PLUS, KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_ENT,
  KC_ENT,  KC_7,    KC_8,  KC_9,   KC_MINS, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_MUTE, KC_QUOT, KC_BSLS,
  _______, KC_COMM, KC_0,  KC_DOT, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|Hue Up|Hue Dn|      |      |      |      |      |Hue Dn|Hue Up|      |caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |RGB Tg|RGB Md|Aud on|Audoff|AGnorm|AGswap|      |RGB Tg|RGB Md|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |Sat Dn|Sat Up|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Sat Up|Sat Dn|Val Up|Val Dn|      |      |      |Val Dn|Val Up|      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  TSKMGR,  RGB_HUD, RGB_HUI, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, _______, CALTDEL,
  _______, RGB_TOG, RGB_MOD, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, RGB_TOG, RGB_MOD, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, RGB_SAD, RGB_SAI, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______, RESET
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |ALTF4 |      |      |      |      |      | Home | PgDn |  Up  | PgUp | Dsk<-| Dsk->|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | End  | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | BK   | FRWRD|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Del  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
  ALTF4,   _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_UP,   KC_PGUP, DSKL,    DSKR,
  _______, _______, _______, _______, _______, _______, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, BK,      FRWRD,   _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______
)

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        rgblight_sethsv_noeeprom(HSV_RED);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        rgblight_sethsv_noeeprom(HSV_BLUE);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        rgblight_sethsv_noeeprom(HSV_GREEN);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        rgblight_sethsv_noeeprom(HSV_BLUE);
      }
      return false;
      break;
  }
  return true;
}
