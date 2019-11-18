#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// clang-format off
enum layers { _QWERTY, _ADJUST, _LOWER, _RAISE };

enum custom_keycodes { JP = SAFE_RANGE, US, SHIFT, LOWER, RAISE, ADJUST,
    CSTM_0, CSTM_1, CSTM_2, CSTM_3, CSTM_4, CSTM_5, CSTM_6, CSTM_7, CSTM_8, CSTM_9,
    CIRC, AT, LBRC, RBRC, BSLS, AMPR, QUOT, LPRN, RPRN, EQL, TILD, PIPE, GRV, LCBR,
    PLUS, ASTR, RCBR, UNDS, MINS, SCLN, COMM, DOT, SLSH, EXLM, HASH, DLR, PERC, DEL, HYPHEN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
     * ,----------------------------------------------------------------------------------------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |   ^  |                    |  \&| |   6  |   7  |   8  |   9  |   0  |  -&= |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |zenhan|                    |insert|   Y  |   U  |   I  |   O  |   P  |  @   |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * | CAPS |   A  |   S  |   D  |   F  |   G  | DEL  l                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  :   |
     * |------+------+------+------+------+------+------l--------------------+------+------+------+------+------+------+------|
     * | SHIFT|   Z  |   X  |   C  |   V  |   B  |   [  |                    |   ]  |   N  |   M  |   ,  |   .  |   /  |  \&_ |
     * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
     * | CTRL |  WIN |  ALT | LOWER||||||||ADJUST| Space|XXXXXXX|||||||| ENTER|XXXXXXX|ADJUST|||||||| RAISE|  ALT |  RCLK| CTRL |
     * ,----------------------------------------------------------------------------------------------------------------------.
     */
    [_QWERTY] = LAYOUT(
      KC_ESC,  CSTM_1,  CSTM_2,  CSTM_3,  CSTM_4,  CSTM_5,  KC_EQL  ,                         KC_JYEN ,CSTM_6,  CSTM_7,  CSTM_8,  CSTM_9,  CSTM_0,  KC_MINS, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ZKHK ,                         KC_INS  ,KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_DEL  ,                         KC_BSPC ,KC_H,    KC_J,    KC_K,    KC_L,    SCLN,    KC_COLN, \
      SHIFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_RBRC ,                         KC_BSLS ,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RO  , \
      KC_LCTL, KC_LGUI, KC_LALT, LOWER,            ADJUST,  KC_SPC  ,KC_ENT ,        KC_ENT , XXXXXXX ,ADJUST,           RAISE  , KC_LALT, KC_APP , KC_LCTL  \
    ),

    /* Adjuste(movekey)
     * ,----------------------------------------------------------------------------------------------------------------------.
     * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      | HOME |PAGEUP|      | END  |      |      |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |      | HOME |      |PAGEDN|  END |      |      |                    |      | LEFT | DOWN |  UP  | RIGHT|      |      |
     * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
     * --------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
     * |      |      |      |      |      |      |      |      ||||||||      |      |      |      |      |      |      |      |
     * ,----------------------------------------------------------------------------------------------------------------------.
     */
    [_ADJUST] = LAYOUT(
      KC_F11 , KC_F1 ,  KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,                        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F12 , \
      _______, _______, _______, _______, _______, _______, _______,                        _______, KC_HOME, KC_PGUP, _______, KC_END , _______, _______, \
      _______, KC_HOME, _______, KC_PGDN, KC_END,  _______, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______,_______,        _______,_______, _______,          _______, _______, _______, _______  \
    ),
    
	/* Lower(ten key)
     * ,----------------------------------------------------------------------------------------------------------------------.
     * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |  7   |  8   |  9   |      |      |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |  4   |  5   |  6   |      |      |
     * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |  1   |  2   |  3   |      |      |
     * --------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
     * |      |      |      |      |      |      |      |      ||||||||      | Enter|  0   |  0   |      |      |      |      |
     * ,----------------------------------------------------------------------------------------------------------------------.
     */
    [_LOWER] = LAYOUT(
      KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12 , \
      _______, _______, _______, _______, _______, _______, _______,                        _______, XXXXXXX, CSTM_7 , CSTM_8 , CSTM_9 , XXXXXXX, _______, \
      _______, _______, _______, _______, _______, _______, _______,                        _______, XXXXXXX, CSTM_4 , CSTM_5 , CSTM_6 , XXXXXXX, _______, \
      _______, _______, _______, _______, _______, _______, _______,                        _______, XXXXXXX, CSTM_1 , CSTM_2 , CSTM_3 , XXXXXXX, _______, \
      _______, _______, _______, _______,          _______, _______,_______,        _______,CSTM_0 , CSTM_0 ,          _______, _______, _______ ,_______  \
    ),

    /* Raise (RGB control)
     * ,----------------------------------------------------------------------------------------------------------------------.
     * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
     * --------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
     * |      |      |      |      |      |      |      |      ||||||||      |      |      |      |      |      |      |      |
     * ,----------------------------------------------------------------------------------------------------------------------.
     */
    [_RAISE] = LAYOUT(
      KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   RGB_MODE_KNIGHT,                RGB_MODE_XMAS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12 , \
      _______, _______, _______, _______, _______, _______, RGB_MODE_REVERSE,               RGB_MODE_FORWARD, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, RGB_VAD,                        RGB_VAI, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, RGB_SAD,                        RGB_SAI, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, RGB_SPD,RGB_MODE_RAINBOW,       RGB_TOG,RGB_SPI, _______,          _______, _______, _______ ,_______  \
    )};

// clang-format on

#ifdef AUDIO_ENABLE
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
#endif

#define JP_LAYOUT true
#define US_LAYOUT false

#ifdef MASTER_LEFT
bool LAYOUT_STATUS = US_LAYOUT;
#else
bool LAYOUT_STATUS = JP_LAYOUT;
#endif

bool SHIFT_PRESSED = false;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

#define SEND_STRING_RESTORE(STR) (SHIFT_PRESSED ? SEND_STRING(STR SS_DOWN(X_LSHIFT)) : SEND_STRING(STR SS_UP(X_LSHIFT)))

#define KEY(CODE) (record->event.pressed ? SEND_STRING(SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define KEY_SHIFT(CODE) (record->event.pressed ? SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define KEY_UPSHIFT(CODE) (record->event.pressed ? SEND_STRING(SS_UP(X_LSHIFT) SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define SHIFT_DU(CODE_DOWN, CODE_UP) (SHIFT_PRESSED ? CODE_DOWN : CODE_UP)
#define CASE_US(CODE, US, JP)                   \
    case CODE:                                  \
        (LAYOUT_STATUS == JP_LAYOUT ? JP : US); \
        return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        CASE_US(CSTM_0, KEY(0), SHIFT_DU(KEY_SHIFT(9), KEY(0)));
        CASE_US(CSTM_1, KEY(1), KEY(1));
        CASE_US(CSTM_2, KEY(2), SHIFT_DU(KEY_UPSHIFT(LBRACKET), KEY(2)));
        CASE_US(CSTM_3, KEY(3), KEY(3));
        CASE_US(CSTM_4, KEY(4), KEY(4));
        CASE_US(CSTM_5, KEY(5), KEY(5));
        CASE_US(CSTM_6, KEY(6), SHIFT_DU(KEY_UPSHIFT(EQUAL), KEY(6)));
        CASE_US(CSTM_7, KEY(7), SHIFT_DU(KEY_SHIFT(6), KEY(7)));
        CASE_US(CSTM_8, KEY(8), SHIFT_DU(KEY_SHIFT(QUOTE), KEY(8)));
        CASE_US(CSTM_9, KEY(9), SHIFT_DU(KEY_SHIFT(8), KEY(9)));
        CASE_US(DEL, KEY(DELETE), KEY_UPSHIFT(BSPACE));
        CASE_US(TILD, KEY_SHIFT(GRAVE), KEY_SHIFT(EQUAL));
        CASE_US(EXLM, KEY_SHIFT(1), KEY_SHIFT(1));
        CASE_US(AT, KEY_SHIFT(2), KEY(LBRACKET));
        CASE_US(HASH, KEY_SHIFT(3), KEY_SHIFT(3));
        CASE_US(DLR, KEY_SHIFT(4), KEY_SHIFT(4));
        CASE_US(PERC, KEY_SHIFT(5), KEY_SHIFT(5));
        CASE_US(CIRC, KEY_SHIFT(6), KEY(EQUAL));
        CASE_US(AMPR, KEY_SHIFT(7), KEY_SHIFT(6));
        CASE_US(ASTR, KEY_SHIFT(8), KEY_SHIFT(QUOTE));
        CASE_US(LPRN, KEY_SHIFT(9), KEY_SHIFT(8));
        CASE_US(RPRN, KEY_SHIFT(0), KEY_SHIFT(9));
        CASE_US(LBRC, KEY(LBRACKET), SHIFT_DU(KEY_SHIFT(RBRACKET), KEY(RBRACKET)));
        CASE_US(RBRC, KEY(RBRACKET), SHIFT_DU(KEY_SHIFT(NONUS_HASH), KEY(NONUS_HASH)));
        CASE_US(LCBR, KEY_SHIFT(LBRACKET), KEY_SHIFT(RBRACKET));
        CASE_US(RCBR, KEY_SHIFT(RBRACKET), KEY_SHIFT(NONUS_HASH));
        CASE_US(GRV, KEY(GRAVE), SHIFT_DU(KEY_SHIFT(EQUAL), KEY_SHIFT(LBRACKET)));
        CASE_US(BSLS, KEY(BSLASH), SHIFT_DU(KEY_SHIFT(INT3), KEY(INT3)));
        CASE_US(PIPE, KEY_SHIFT(BSLASH), KEY_SHIFT(INT3));
        CASE_US(MINS, KEY(MINUS), SHIFT_DU(KEY_SHIFT(INT1), KEY(MINUS)));
        CASE_US(UNDS, KEY_SHIFT(MINUS), KEY_SHIFT(INT1));
        CASE_US(EQL, KEY(EQUAL), SHIFT_DU(KEY_SHIFT(SCOLON), KEY_SHIFT(MINUS)));
        CASE_US(PLUS, KEY_SHIFT(EQUAL), KEY_SHIFT(SCOLON));
        CASE_US(SCLN, KEY(SCOLON), SHIFT_DU(KEY_UPSHIFT(QUOTE), KEY(SCOLON)));
        CASE_US(QUOT, KEY(QUOTE), SHIFT_DU(KEY_SHIFT(2), KEY_SHIFT(7)));
        case JP:
            if (record->event.pressed) {
                LAYOUT_STATUS = JP_LAYOUT;
            }
            return false;
            break;
        case US:
            if (record->event.pressed) {
                LAYOUT_STATUS = US_LAYOUT;
            }
            return false;
            break;
        case SHIFT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSHIFT));
                SHIFT_PRESSED = true;
            } else {
                SEND_STRING(SS_UP(X_LSHIFT));
                SHIFT_PRESSED = false;
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}
