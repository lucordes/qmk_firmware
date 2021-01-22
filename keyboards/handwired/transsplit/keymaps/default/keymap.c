
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum keyboard_layers {
  _COLM=0,
  _QWERTY,
  _HOMEROW,
  _AMONGUS,
  _UMLAUT,
  _LOWER,
  _RAISE,
  _ARROW,
  _AUDIO,
  _GAME,

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


uint8_t cur_dance(qk_tap_dance_state_t *state);

void esc_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_reset(qk_tap_dance_state_t *state, void *user_data);
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | AltGr| Alt  | Lower|    Space    | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *


 */

[_COLM] = LAYOUT_ortho_4x12(
     TD(ESC_GRAVE),  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT) ,
    KC_LCTL, KC_LGUI,    KC_RALT,    KC_LALT,    MO(_LOWER),  KC_SPC, KC_SPC, MO(_RAISE),  KC_RCTL, KC_RGUI, MO(_ARROW), KC_RCTL
),

[_QWERTY] = LAYOUT_ortho_4x12(
  TD(ESC_GRAVE),  KC_Q,       KC_W,       KC_E,       KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB, KC_A,       KC_S,       KC_D,       KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, LT(_ARROW,KC_QUOT),
  KC_LSFT, KC_Z,       KC_X,       KC_C,       KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______
),




[_HOMEROW] = LAYOUT_ortho_4x12(
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, LCTL_T(KC_A),  LGUI_T(KC_R),  ALT_T(KC_S),  SFT_T(KC_T),  _______,  _______,  SFT_T(KC_N),  ALT_T(KC_E),  LGUI_T(KC_I),    LCTL_T(KC_O),  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,_______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______
),


[_AMONGUS] = LAYOUT_ortho_4x12(
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  KC_ESC, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  TG(_AMONGUS),  KC_SPC,  MO(_LOWER),  _______,  _______,  _______,  _______,    _______,  _______
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |RESET |      |      |      |      |      |      |      |      |      |   (  |   )  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|      |      |      |      |      |      |      |      |      |   {  |   }  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  RESET, KC_F14,  KC_WBAK,  KC_UP,  KC_WFWD,  TG(_AMONGUS),  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,    _______,  KC_DEL,
  ALTTAB, TABCYCLE,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_ENT , _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,    _______,  _______,
  _______, KC_VOLD, KC_VOLU,  KC_LBRC,  KC_BSPC,  _______,  _______,  _______,  KC_RBRC,  _______,      TG(_QWERTY),  _______,
  _______, _______,  _______,  _______,  _______,  KC_F13,  _______,  _______,  _______,  _______,    _______,  KC_PWR
),

[_UMLAUT] = LAYOUT_ortho_4x12(
  _______, _______,  _______,  TD(S_UMLAUT),  TD(A_UMLAUT),  _______,  _______,  TD(O_UMLAUT),  TD(U_UMLAUT),  _______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______
),

[_AUDIO] = LAYOUT_ortho_4x12(
  _______, _______,  KC_VOLU,  KC_F15,  KC_F16,  KC_WWW_SEARCH,  KC_F13,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  KC_VOLD,  KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  KC_MEDIA_PLAY_PAUSE,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
  _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,         KC_0,_______,
  _______, RESET, _______, KC_LBRC, KC_MINUS, KC_BSLASH, _______, KC_EQUAL, KC_RBRC, _______, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PWR
),



[_ARROW] = LAYOUT_ortho_4x12(
  _______, _______, _______, KC_F13, _______, RGB_MOD, RGB_TOG, _______, KC_UP, NK_TOGG, UC_MOD, CMB_TOG,
  _______, _______, _______, _______, _______, RGB_HUI, RGB_VAI, KC_LEFT, KC_DOWN, KC_RIGHT, TG(_HOMEROW), _______,
  MO(_LOWER), _______, _______, _______, _______, RGB_SPD, RGB_SAI, _______, KC_UP, _______, TG(_GAME),_______,
  _______, _______, _______, _______, _______, _______, TG(_UMLAUT), KC_LEFT, KC_DOWN, KC_RIGHT, _______,_______
),



/* _MULTIMEDIA
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Psc |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Mute | Vol+ | Vol- |      |      |      |Insert|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Play | Next |  Del |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_ortho_4x12(
    _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    _______,    _______,    _______,         _______,_______,
_______,  KC_Q,       KC_W,       KC_E,       KC_R,   KC_T,   _______,   _______,   _______,    _______,    _______,    _______,
  _______, KC_A,       KC_S,       KC_D,       KC_F,   KC_G,   KC_VOLU,   _______,   _______,    _______,    _______, _______,
  _______, KC_Z,       KC_X,       KC_C,       KC_V,   KC_SPC,   KC_VOLD,   _______,   _______, _______,  TG(_GAME), _______

)







};



void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);

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


    }
return true;
}



void matrix_init_user(void) {
//enmpty

}







void DanceS(qk_tap_dance_state_t *state, void *user_data) {
      if (state->count == 1) {

        if (state->interrupted || !state->pressed) //singel tapreturn SINGLE_TAP;
            SEND_STRING("f");

        else{

           SEND_STRING(SS_RALT("s"));

            //_UMLAUT
        }


    }

    if (state->count > 1){
    SEND_STRING("ff");
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
            SEND_STRING("l");

        else{

           SEND_STRING(SS_RALT("p"));

            //_UMLAUT
        }


    }

    if (state->count > 1){
    SEND_STRING("ll");
       //return DOUBLE_SINGLE_TAP;
    }
        reset_tap_dance(state);
}





void DanceA(qk_tap_dance_state_t *state, void *user_data) {
        if (state->count == 1) {

            if (state->interrupted || !state->pressed) //singel tapreturn SINGLE_TAP;
                SEND_STRING("p");

            else{

            SEND_STRING(SS_RALT("q"));

                //_UMLAUT
            }


        }

    if (state->count > 1){
    SEND_STRING("pp");
        //return DOUBLE_SINGLE_TAP;
    }

            reset_tap_dance(state);

}



uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
         if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    }else
//if (state->count >= 2)
{
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        //if (state->interrupted)
            return DOUBLE_TAP;
      // else if (state->pressed) return DOUBLE_HOLD;
        //else return DOUBLE_TAP;
    }
return 8;
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
   //if (state->count == 3) {
     // if (state->interrupted || !state->pressed) return TRIPLE_TAP;
       //else return TRIPLE_HOLD;
    //} else return 8; // Magic number. At some point this method will expand to work for more presses
}








static tap esctap_state = {
    .is_press_action = true,
    .state = 0
};

void esc_finished(qk_tap_dance_state_t *state, void *user_data) {
    esctap_state.state = cur_dance(state);
    switch (esctap_state.state) {
        case SINGLE_TAP: register_code(KC_ESC); break;
        case SINGLE_HOLD: register_code(KC_GRAVE); break;
       // case DOUBLE_TAP: register_code(KC_ESC); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void esc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (esctap_state.state) {
        case SINGLE_TAP: unregister_code(KC_ESC); break;
        case SINGLE_HOLD: unregister_code(KC_GRAVE); break;
        //case DOUBLE_TAP: unregister_code(KC_ESC); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    esctap_state.state = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [A_UMLAUT]=ACTION_TAP_DANCE_FN(DanceA),
    [U_UMLAUT]=ACTION_TAP_DANCE_FN(DanceU),
    [O_UMLAUT]=ACTION_TAP_DANCE_FN(DanceO),
    [S_UMLAUT]=ACTION_TAP_DANCE_FN(DanceS),




    //spart circa 400 byte :D ohne advanced
    //[A_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset),
    //[U_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_finished, u_reset),
    //[O_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_finished, o_reset),
    //[S_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_finished, s_reset),
    [ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),

};

