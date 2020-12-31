
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum keyboard_layers {
  _QWERTY = 0, // Base Layer
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


    A,
    S,
    D,
    F,
    J,
    K,
    L,
    SEMIC,

};


uint8_t cur_dance(qk_tap_dance_state_t *state);

void esc_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_reset(qk_tap_dance_state_t *state, void *user_data);

void a_finished(qk_tap_dance_state_t *state, void *user_data);
void a_reset(qk_tap_dance_state_t *state, void *user_data);

void s_finished(qk_tap_dance_state_t *state, void *user_data);
void s_reset(qk_tap_dance_state_t *state, void *user_data);

void d_finished(qk_tap_dance_state_t *state, void *user_data);
void d_reset(qk_tap_dance_state_t *state, void *user_data);

void f_finished(qk_tap_dance_state_t *state, void *user_data);
void f_reset(qk_tap_dance_state_t *state, void *user_data);

void j_finished(qk_tap_dance_state_t *state, void *user_data);
void j_reset(qk_tap_dance_state_t *state, void *user_data);

void k_finished(qk_tap_dance_state_t *state, void *user_data);
void k_reset(qk_tap_dance_state_t *state, void *user_data);

void l_finished(qk_tap_dance_state_t *state, void *user_data);
void l_reset(qk_tap_dance_state_t *state, void *user_data);

void semic_finished(qk_tap_dance_state_t *state, void *user_data);
void semic_reset(qk_tap_dance_state_t *state, void *user_data);

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),                // 💩a
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
    UCIS_SYM("bot",0x1F916),


);


*/
// For the x tap dance. Put it here so it can be used in any keymap2328


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


[_QWERTY] = LAYOUT_ortho_4x12(
  TD(ESC_GRAVE),  KC_Q,       KC_W,       KC_E,       KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB, KC_A,       KC_S,       KC_D,       KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    LT(_ARROW, KC_SCLN), KC_QUOT,
  KC_LSFT, KC_Z,       KC_X,       KC_C,       KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LCTL, KC_LGUI,    KC_RALT,    KC_LALT,    MO(_LOWER),  LT(_AUDIO, KC_SPC), KC_SPC, MO(_RAISE),  KC_RCTL, KC_RGUI, MO(_ARROW), KC_RCTL
),


[_HOMEROW] = LAYOUT_ortho_4x12(
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, TD(A),  TD(S),  TD(D),  TD(F),  _______,  _______,  TD(J),  TD(K),  TD(L),    TD(SEMIC),  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
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
  _______, _______, _______,  KC_LBRC,  KC_BSPC,  _______,  _______,  _______,  KC_RBRC,  _______,      _______,  _______,
  _______, _______,  _______,  _______,  _______,  KC_F13,  _______,  _______,  _______,  _______,    _______,  KC_PWR
),

[_UMLAUT] = LAYOUT_ortho_4x12(
  _______, TD(A_UMLAUT),  _______,  TD(S_UMLAUT),  _______,  _______,  _______,  TD(U_UMLAUT),  _______,  TD(O_UMLAUT),    _______,  _______,
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
            SEND_STRING("e");

        else{

           SEND_STRING(SS_RALT("s"));

            //_UMLAUT
        }


    }

    if (state->count > 1){
    SEND_STRING("ee");
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
                SEND_STRING("q");

            else{

            SEND_STRING(SS_RALT("q"));

                //_UMLAUT
            }


        }

    if (state->count > 1){
    SEND_STRING("qq");
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



//====================================================================================

static tap atap_state = {
    .is_press_action = true,
    .state = 0
};

void a_finished(qk_tap_dance_state_t *state, void *user_data) {
    atap_state.state = cur_dance(state);
    switch (atap_state.state) {
        case SINGLE_TAP: register_code(KC_A); break;
        case SINGLE_HOLD: register_code(KC_LCTL); break;
        case DOUBLE_TAP: tap_code(KC_A);
            register_code(KC_A); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void a_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (atap_state.state) {
        case SINGLE_TAP: unregister_code(KC_A); break;
        case SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code(KC_A); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    atap_state.state = 0;
}

//====================================================================================a






static tap stap_state = {
    .is_press_action = true,
    .state = 0
};

void s_finished(qk_tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_S); break;
        case SINGLE_HOLD: register_code(KC_LGUI); break;
       case DOUBLE_TAP: tap_code(KC_S);
       register_code(KC_S);break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void s_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_S); break;
        case SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code(KC_S); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    stap_state.state = 0;
}

//====================================================================================s



static tap dtap_state = {
    .is_press_action = true,
    .state = 0
};


void d_finished(qk_tap_dance_state_t *state, void *user_data) {
    dtap_state.state = cur_dance(state);
    switch (dtap_state.state) {
        case SINGLE_TAP: register_code(KC_D); break;
        case SINGLE_HOLD: register_code(KC_LALT); break;
        case DOUBLE_TAP: tap_code(KC_D);
        register_code(KC_D); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void d_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (dtap_state.state) {
        case SINGLE_TAP: unregister_code(KC_D); break;
        case SINGLE_HOLD: unregister_code(KC_LALT); break;
        case DOUBLE_TAP: unregister_code(KC_D); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    dtap_state.state = 0;
}

//====================================================================================d



static tap ftap_state = {
    .is_press_action = true,
    .state = 0
};


void f_finished(qk_tap_dance_state_t *state, void *user_data) {
    ftap_state.state = cur_dance(state);
    switch (ftap_state.state) {
        case SINGLE_TAP: register_code(KC_F); break;
        case SINGLE_HOLD: register_code(KC_LSFT); break;
        case DOUBLE_TAP: tap_code(KC_F);
            register_code(KC_F); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void f_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ftap_state.state) {
        case SINGLE_TAP: unregister_code(KC_F); break;
        case SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code(KC_F); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    ftap_state.state = 0;
}

//====================================================================================f


static tap jtap_state = {
    .is_press_action = true,
    .state = 0
};

void j_finished(qk_tap_dance_state_t *state, void *user_data) {
    jtap_state.state = cur_dance(state);
    switch (jtap_state.state) {
        case SINGLE_TAP: register_code(KC_J); break;
        case SINGLE_HOLD: register_code(KC_LSFT); break;
        case DOUBLE_TAP: tap_code(KC_J);
            register_code(KC_J); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void j_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (jtap_state.state) {
        case SINGLE_TAP: unregister_code(KC_J); break;
        case SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code(KC_J); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    jtap_state.state = 0;
}

//====================================================================================j


static tap ktap_state = {
    .is_press_action = true,
    .state = 0
};


void k_finished(qk_tap_dance_state_t *state, void *user_data) {
    ktap_state.state = cur_dance(state);
    switch (ktap_state.state) {
        case SINGLE_TAP: register_code(KC_K); break;
        case SINGLE_HOLD: register_code(KC_LALT); break;
        case DOUBLE_TAP: tap_code(KC_K);
            register_code(KC_K); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void k_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ktap_state.state) {
        case SINGLE_TAP: unregister_code(KC_K); break;
        case SINGLE_HOLD: unregister_code(KC_LALT); break;
        case DOUBLE_TAP: unregister_code(KC_K); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    ktap_state.state = 0;
}

//====================================================================================k

static tap ltap_state = {
    .is_press_action = true,
    .state = 0
};


void l_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltap_state.state = cur_dance(state);
    switch (ltap_state.state) {
        case SINGLE_TAP: register_code(KC_L); break;
        case SINGLE_HOLD: register_code(KC_LGUI); break;
        case DOUBLE_TAP: tap_code(KC_L);
            register_code(KC_L); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void l_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltap_state.state) {
        case SINGLE_TAP: unregister_code(KC_L); break;
        case SINGLE_HOLD: unregister_code(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code(KC_L); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    ltap_state.state = 0;
}

//====================================================================================l

static tap semictap_state = {
    .is_press_action = true,
    .state = 0
};

void semic_finished(qk_tap_dance_state_t *state, void *user_data) {
    semictap_state.state = cur_dance(state);
    switch (semictap_state.state) {
        case SINGLE_TAP: register_code(KC_SCLN); break;
        case SINGLE_HOLD: register_code(KC_RCTL); break;
       case DOUBLE_TAP: tap_code(KC_SCLN);
       register_code(KC_SCLN); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        //case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void semic_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (semictap_state.state) {
        case SINGLE_TAP: unregister_code(KC_SCLN); break;
        case SINGLE_HOLD: unregister_code(KC_RCTL); break;
        case DOUBLE_TAP: unregister_code(KC_SCLN); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    semictap_state.state = 0;
}

//====================================================================================semic

qk_tap_dance_action_t tap_dance_actions[] = {
    [A_UMLAUT]=ACTION_TAP_DANCE_FN(DanceA),
    [U_UMLAUT]=ACTION_TAP_DANCE_FN(DanceU),
    [O_UMLAUT]=ACTION_TAP_DANCE_FN(DanceO),
    [S_UMLAUT]=ACTION_TAP_DANCE_FN(DanceS),


     [A]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset),
    [S]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_finished, s_reset),
    [D]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, d_finished, d_reset),
    [F]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, f_finished, f_reset),
     [J]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, j_finished, j_reset),
    [K]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, k_finished, k_reset),
    [L]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, l_finished, l_reset),
    [SEMIC]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, semic_finished, semic_reset),





    //spart circa 400 byte :D ohne advanced
    //[A_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset),
    //[U_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_finished, u_reset),
    //[O_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_finished, o_reset),
    //[S_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_finished, s_reset),
    [ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_finished, esc_reset),

};

