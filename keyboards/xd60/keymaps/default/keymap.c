

#include QMK_KEYBOARD_H
#include "quantum.h"
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


enum keyboard_layers {

  _QWERTY=0, // Base Layer
  _UMLAUT,
  _ADJUST,
  // Function Layer
};


enum custom_keycodes {

    ALTTAB= SAFE_RANGE,
    TABCYCLE,
    MEM,




};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Tap dance enums
enum {
    A_UMLAUT,
    S_UMLAUT,
    U_UMLAUT,
    O_UMLAUT,
    ESC_GRAVE,
};
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),                // 💩
    UCIS_SYM("rofl", 0x1F923),                // 🤣
    UCIS_SYM("cuba", 0x1F1E8, 0x1F1FA),       // 🇨🇺
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0), // ಠ_ಠ
    UCIS_SYM("fire",0x1F525), //🔥
    UCIS_SYM("table",0x0028, 0x0256f, 0x00b0, 0x25a1, 0x00b0, 0xff09, 0x256f, 0xfe35, 0x0020, 0x253b, 0x2501, 0x253b),///(╯°□°）╯︵ ┻━┻
    UCIS_SYM("peace",0x262E),
    UCIS_SYM("chess",0x265A),//chessking
    UCIS_SYM("face",0x0028,0x0020,0x00361,0x00b0,0x0020,0x0035c,0x00296,0x0020,0x00361,0x00b0,0x0029), //( ͡° ͜ʖ ͡°)
    UCIS_SYM("shrug",0x00af,0x005c,0x005f,0x0028,0x0030c4,0x0029,0x005f,0x002f,0x00af), //¯\_(ツ)_/¯
    UCIS_SYM("rifle",0x2584,0xfe3b,0x337,0x33f,0x253b,0x33f,0x2550,0x2501,0x4e00),  //rifle
     UCIS_SYM("vomit",0x1F92E),


);



// For the x tap dance. Put it here so it can be used in any keymap2328


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//flashces layout muesste layout ansi 60 sein hier oben rechter KC nicht verdrahtet:
    //siehe xd60.h
  // 0: Base Layer
  [_QWERTY]=LAYOUT_all(
      TD(ESC_GRAVE),  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      MO(_ADJUST), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_NO,             KC_ENT,    \
      KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_RSFT,    KC_RSFT,      \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                          KC_RGUI, MO(_ADJUST),     TG(_UMLAUT),  TG(_UMLAUT),  KC_RIGHT),

  // 1: Function Layer
  [_UMLAUT]=LAYOUT_all(
      _______, _______,   _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,   _______,  _______,   _______,    \
      _______,   _______, _______,   _______, _______,_______,_______,TD(O_UMLAUT),  _______, TD(U_UMLAUT),   _______, _______,  _______,           _______,    \
      _______,   TD(A_UMLAUT), TD(A_UMLAUT), _______,_______, _______, _______,_______,  _______,  _______,   _______, _______,  _______,             _______,    \
      _______, _______,   _______,   _______,  _______,_______,  _______,  _______,_______,_______, _______,  _______,  _______, _______,  _______,      \
      _______, _______, _______,                          _______,                          _______, _______,    _______,_______,_______),

  //fn
  [_ADJUST]=LAYOUT_all(
      _______,   KC_FN1,   KC_FN2,   KC_FN3,   KC_FN4,  KC_FN5,  KC_FN6,  KC_FN7,  KC_FN8,  KC_FN9,   KC_FN10,  KC_FN11,   KC_FN12,  _______,   _______,    \
      RESET,   _______, KC_WBAK,   KC_UP, KC_WFWD,KC_VOLD,KC_VOLU,KC_BTN1,  KC_MS_U, KC_BTN2,   RGB_MOD, RGB_TOG,  VLK_TOG,           _______,    \
      _______,   TG(_UMLAUT), KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,KC_MS_L,  KC_MS_D,  KC_MS_R,   RGB_HUI, RGB_VAI,  _______,             _______,    \
      _______, _______,   _______,   _______,  _______,_______,  _______,  ALTTAB,TABCYCLE,_______, _______,  _______,  _______, _______,  _______,      \
      _______, _______, _______,                          _______,                          _______, _______,    _______,KC_PWR,_______)
};




void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);

}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch(keycode) {

        case ALTTAB:
          if (record->event.pressed) {


            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_TAB));
          }
          else{SEND_STRING(SS_UP(X_LALT));}



            break;
        case TABCYCLE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RCTL)SS_TAP(X_TAB));

            }else{

                SEND_STRING(SS_UP(X_RCTL));


            }

            break;
        case MEM:
        if (record->event.pressed) {

            }else{qk_ucis_start();
            }


            break;

    }
return true;
}




void matrix_init_user(void) {
//enmpty

}

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 2, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 2, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,
    my_layer4_layer,
    my_layer5_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}







void DanceS(qk_tap_dance_state_t *state, void *user_data) {
      if (state->count == 1) {

        if (state->interrupted || !state->pressed) //singel tapreturn SINGLE_TAP;
            SEND_STRING("s");

        else{

           SEND_STRING(SS_RALT("s"));

            //_UMLAUT
        }


    }

    if (state->count > 1){
    SEND_STRING("ss");
       //return DOUBLE_SINGLE_TAP;
    }
        reset_tap_dance(state);
}


void DanceU(qk_tap_dance_state_t *state, void *user_data) {
      if (state->count == 1) {

        if (state->interrupted || !state->pressed) //singel tapreturn SINGLE_TAP;
            SEND_STRING("u");

        else{

           SEND_STRING(SS_RALT("y"));

            //_UMLAUT
        }


    }

    if (state->count > 1){
    SEND_STRING("uu");
       //return DOUBLE_SINGLE_TAP;
    }
        reset_tap_dance(state);
}


void DanceO(qk_tap_dance_state_t *state, void *user_data) {
      if (state->count == 1) {

        if (state->interrupted || !state->pressed) //singel tapreturn SINGLE_TAP;
            SEND_STRING("o");

        else{

           SEND_STRING(SS_RALT("p"));

            //_UMLAUT
        }


    }

    if (state->count > 1){
    SEND_STRING("oo");
       //return DOUBLE_SINGLE_TAP;
    }
        reset_tap_dance(state);
}





void DanceA(qk_tap_dance_state_t *state, void *user_data) {
      if (state->count == 1) {

        if (state->interrupted || !state->pressed) //singel tapreturn SINGLE_TAP;
            SEND_STRING("a");

        else{

           SEND_STRING(SS_RALT("q"));

            //_UMLAUT
        }


    }

   if (state->count > 1){
SEND_STRING("aa");
       //return DOUBLE_SINGLE_TAP;
}

        reset_tap_dance(state);

}

void dance_grave_finished(qk_tap_dance_state_t *state, void *user_data) {

    if (state->count == 1) {
        if (state->interrupted || !state->pressed) register_code16(KC_ESC);
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else register_code(KC_GRAVE);
        unregister_code(KC_GRAVE);
    }
    //weiter wird nicht benoetigt da man ja esc nie mehrmals tippt
    //else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap

}

void dance_grave_reset(qk_tap_dance_state_t *state, void *user_data) {

}


qk_tap_dance_action_t tap_dance_actions[] = {
//ACTION_TAP_DANCE_FN spart speicher
    [A_UMLAUT] = ACTION_TAP_DANCE_FN(DanceA),
    [U_UMLAUT] = ACTION_TAP_DANCE_FN(DanceU),
    [O_UMLAUT] = ACTION_TAP_DANCE_FN(DanceO),
    [S_UMLAUT] = ACTION_TAP_DANCE_FN(DanceS),
[ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_grave_finished, dance_grave_reset),


};


