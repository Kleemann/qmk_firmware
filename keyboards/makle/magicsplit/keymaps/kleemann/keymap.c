#include QMK_KEYBOARD_H
#include "keymap_danish.h"
#include "sendstring_danish.h"
#include "color.h"

#define _BASE 0
#define _TAB 1
#define _ESC 2

enum custom_keycodes {
    ONEPASS = SAFE_RANGE,
    SPARK,
    FORK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_69(
        LT(_ESC,KC_ESC),  DK_1,    DK_2,     DK_3,    DK_4,    DK_5,    DK_6,        DK_7,    DK_8,     DK_9,    DK_0,     DK_PLUS,  DK_ACUT,   KC_BSPC,           KC_MPLY,
        LT(_TAB,KC_TAB),  DK_Q,    DK_W,     DK_E,    DK_R,    DK_T,                 DK_Y,    DK_U,     DK_I,    DK_O,     DK_P,     DK_ARNG,   DK_DIAE,           KC_PGUP,
        KC_CAPS,          DK_A,    DK_S,     DK_D,    DK_F,    DK_G,                 DK_H,    DK_J,     DK_K,    DK_L,     DK_AE,    DK_OSTR,   DK_QUOT,  KC_ENT,  KC_PGDN,
        KC_LSFT,          DK_LABK, DK_Z,     DK_X,    DK_C,    DK_V,    DK_B,        DK_N,    DK_M,     DK_COMM, DK_DOT,   DK_MINS,  KC_RSFT,             KC_UP,   
        KC_LCTL,          KC_LALT, KC_LGUI,           KC_SPC,                        KC_SPC,  KC_RGUI,  KC_RALT, KC_RCTL,                       KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    [_TAB] = LAYOUT_69(
        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,           KC_TRNS,
        KC_TRNS,         KC_BSPC, KC_DEL,  KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,           KC_MNXT,
        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_MPRV,
        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, 
        KC_TRNS,         KC_TRNS, KC_TRNS,          KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,   KC_TRNS, KC_TRNS
    ),

    [_ESC] = LAYOUT_69(
        KC_TRNS,         KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,           KC_TRNS,
        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,           FORK,
        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  SPARK,
        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS,           
        KC_TRNS,         KC_TRNS, KC_TRNS,          KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,    KC_TRNS, ONEPASS
    )   
};

void spotlight_search(char *query) {
    register_code(KC_LGUI);
    register_code(KC_SPC); 
    unregister_code(KC_LGUI);
    unregister_code(KC_SPC);
    send_string(query);
    register_code(KC_ENT);
    unregister_code(KC_ENT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ONEPASS:
        if (record->event.pressed) {
            spotlight_search("1Password");
        }
        break;
    case SPARK:
        if (record->event.pressed) {
            spotlight_search("Spark");
        }
        break;
    case FORK:
        if (record->event.pressed) {
            spotlight_search("Fork");
        }
        break;
    }
    return true;
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)) {
            case _BASE:
                if (clockwise) {
                    register_code(KC_AUDIO_VOL_UP);
                    unregister_code(KC_AUDIO_VOL_UP);
                } else {
                    register_code(KC_AUDIO_VOL_DOWN);
                    unregister_code(KC_AUDIO_VOL_DOWN);
                }
                break;

            case _TAB:
                if (clockwise) {
                    register_code(KC_PGDN);
                    unregister_code(KC_PGDN);
                } else {
                    register_code(KC_PGUP);
                    unregister_code(KC_PGUP);
                }
                break;

            default:
                if (clockwise) {
                    register_code(KC_AUDIO_VOL_UP);
                    unregister_code(KC_AUDIO_VOL_UP);
                } else {
                    register_code(KC_AUDIO_VOL_DOWN);
                    unregister_code(KC_AUDIO_VOL_DOWN);
                }
                break;
        }
    }   
    return true;
}
#endif