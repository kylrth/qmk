#include QMK_KEYBOARD_H

enum unicode_names {
  ACC_ACUT,
  ACC_GRAV,
  ACC_CIRC,
  ACC_DIER,
  ced,
  CED,
  ene,
  ENE,
  GUIL_OPEN,
  GUIL_CLOSE,
  LIG_oe,
  LIG_OE,
};

// Note that these are the combining diacritic marks, which some programs have a hard time with. If
// I run into issues over time I'll look at creating a keymap that works with an international
// layout.
const uint32_t PROGMEM unicode_map[] = {
  [ACC_ACUT] = 0x0301,
  [ACC_GRAV] = 0x0300,
  [ACC_CIRC] = 0x0302,
  [ACC_DIER] = 0x0308,
  [ced] = 0x00E7,
  [CED] = 0x00C7,
  [ene] = 0x00F1,
  [ENE] = 0x00D1,
  [GUIL_OPEN] = 0x00AB,
  [GUIL_CLOSE] = 0x00BB,
  [LIG_oe] = 0x0153,
  [LIG_OE] = 0x0152,
};

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BkSpc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Enter |    |  Del  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BkSpc \  |RAISE | Home | End  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_ENT,  KC_DEL,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_BSPC, MO(_RAISE), KC_HOME, KC_END
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | Mute |VolDn |VolUp |BriDn |BriUp |                    |      |      |      |      |      |Print |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   [  |   ]  | MsUp |   (  |   )  |                    |   -  |   =  |  Up  |   {  |   }  |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PgUp | MsLt | MsDn | MsRt | WhUp |-------.    ,-------| Home | Left | Down |Right | End  |      |
 * |------+------+------+------+------+------| Enter |    |  Del  |------+------+------+------+------+------|
 * |      | PgDn |      |      |      | WhDn |-------|    |-------|      |LtClk |RtClk | WhLt | WhRt |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BkSpc \  |RAISE | Home | End  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_MUTE, KC_VOLD,    KC_VOLU,    KC_BRID,    KC_BRIU,                    _______, _______, _______, _______, _______, KC_PSCR,
   KC_GRV, KC_LBRC, KC_RBRC,   KC_MS_UP,    KC_LPRN,    KC_RPRN,                    KC_MINS, KC_EQL,  KC_UP,   KC_LCBR, KC_RCBR, KC_BSLS,
  _______,KC_PGUP,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_MS_WH_UP,                    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, _______,
  _______, KC_PGDN, _______,  _______,   _______,  KC_MS_WH_DOWN, _______, _______, XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |   ö  |      |                    |      |      |      |   Œ  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   ò  |   ô  |   ó  |      |-------.    ,-------|      |      |      |      |   «  |   »  |
 * |------+------+------+------+------+------| Enter |    |  Del  |------+------+------+------+------+------|
 * |      |      |      |   Ç  |      |      |-------|    |-------|   Ñ  |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BkSpc \  |RAISE | Home | End  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
   KC_F1,   KC_F2,       KC_F3,        KC_F4,       KC_F5,   KC_F6,                    KC_F7,          KC_F8,   KC_F9,             KC_F10,       KC_F11,  KC_F12,
 _______, _______,     _______,      _______, X(ACC_DIER), _______,                    _______,      _______, _______, XP(LIG_oe, LIG_OE),      _______, _______,
 _______, _______, X(ACC_GRAV),  X(ACC_CIRC), X(ACC_ACUT), _______,                    _______,      _______, _______,            _______, X(GUIL_OPEN), X(GUIL_CLOSE),
 _______, _______,     _______, XP(ced, CED),     _______, _______,  _______, _______, XP(ene, ENE), _______, _______,            _______,      _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
