
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


enum keyboard_layers {
  _QWERTY = 0, // Base Layer
  _AMONGUS,
  _UMLAUT,
  _LOWER,
  _RAISE,
  _ARROW,
  _GAME,
  // Function Layer
};


enum custom_keycodes {

    ALTTAB= SAFE_RANGE,
    TABCYCLE,
    

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
    TD_ESC_CAPS,
    SOME_OTHER_DANCE
};

void a_finished(qk_tap_dance_state_t *state, void *user_data);
void a_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

// Func macro definitions.
#define SFT_TAB  LT(_MULTIMEDIA, KC_TAB) // Tap for Enter, hold for Shift

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
  KC_GRAVE,  KC_Q,       KC_W,       KC_E,       KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB, KC_A,       KC_S,       KC_D,       KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,       KC_X,       KC_C,       KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LCTL, KC_LGUI,    KC_RALT,    KC_LALT,    MO(_LOWER),  KC_SPC, KC_SPC, MO(_RAISE),  KC_RCTL, KC_RGUI, KC_LALT,   MO(_ARROW)
),


[_AMONGUS] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_Q,       KC_W,       KC_E,       KC_R,   TG(_AMONGUS),   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB, KC_A,       KC_S,       KC_D,       KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_ESC, KC_Z,       KC_X,       KC_C,       KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LCTL, KC_LGUI,    KC_RALT,    KC_LALT,    KC_SPC,  KC_SPC, KC_SPC, MO(_RAISE),  KC_RCTL, KC_RGUI, KC_LALT,   MO(_ARROW)
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
  RESET, _______,  KC_WBAK,  KC_UP,  KC_WFWD,  TG(_AMONGUS),  _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,    _______,  _______,
  ALTTAB, TABCYCLE,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_ENT , _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,    _______,  _______,
  _______, _______, _______,  KC_LBRC,  KC_BSPC,  _______,  KC_VOLD,  KC_VOLU,  KC_RBRC,  _______,      _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  KC_PWR
),

[_UMLAUT] = LAYOUT_ortho_4x12(
  _______, _______,  _______,  _______,  _______,  _______,  _______,  TD(U_UMLAUT),  _______,  TD(O_UMLAUT),    _______,  _______,
  _______, TD(A_UMLAUT),  TD(S_UMLAUT),  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
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
  _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,         KC_0,RESET,
  _______, _______, _______, KC_LBRC, KC_MINUS, KC_BSLASH, _______, KC_EQUAL, KC_RBRC, _______, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),



[_ARROW] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, MU_MOD, MU_TOG, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______,
  _______, UC_M_LN, _______, _______, _______, _______, _______, TG(_UMLAUT), KC_MEDIA_PREV_TRACK, KC_UP, KC_MEDIA_NEXT_TRACK, TG(_GAME),
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______
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
    _______,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,         KC_0,_______,
KC_TAB,  KC_Q,       KC_W,       KC_E,       KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LSFT, KC_A,       KC_S,       KC_D,       KC_F,   KC_G,   KC_VOLD,   KC_VOLU,   KC_K,    KC_L,    _______, KC_QUOT,
  KC_LCTL, KC_Z,       KC_X,       KC_C,       KC_V,   KC_SPC,   KC_N,   KC_M,   KC_COMM, KC_DOT,  TG(_GAME), _______

)






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


}

return true;
}


void matrix_init_user(void) {
//enmpty
}
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}


uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;



    }
    //if (state->count ==0){return SINGLE_TAP;}
   if (state->count > 1){return DOUBLE_SINGLE_TAP;}
  else{return 8;}
    //else{return 8;}
    /*
     else if (state->count == 2) {
         if (state->interrupted) return DOUBLE_SINGLE_TAP;}
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses

    */
}


// Create an instance of 'tap' for the 'x' tap dance.
static tap atap_state = {
    .is_press_action = true,
    .state = 0
};

void a_finished(qk_tap_dance_state_t *state, void *user_data) {
    atap_state.state = cur_dance(state);
    switch (atap_state.state) {
        case SINGLE_TAP: register_code(KC_A); break;
        case SINGLE_HOLD:
        register_code(KC_RALT);
        register_code(KC_Q);
        break;

        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_A); register_code(KC_A); break;
    }
}

void a_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (atap_state.state) {
        case SINGLE_TAP: unregister_code(KC_A); break;
        case SINGLE_HOLD:
            unregister_code(KC_Q);
            unregister_code(KC_RALT);
            break;
        //case DOUBLE_TAP: unregister_code(KC_ESC); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_A);
    }
    atap_state.state = 0;
}


static tap stap_state = {
    .is_press_action = true,
    .state = 0
};

void s_finished(qk_tap_dance_state_t *state, void *user_data) {
    stap_state.state = cur_dance(state);
    switch (stap_state.state) {
        case SINGLE_TAP: register_code(KC_S); break;
        case SINGLE_HOLD:
        register_code(KC_RALT);
        register_code(KC_S);
        break;
       // case DOUBLE_TAP: register_code(KC_ESC); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_S); register_code(KC_S); break;
    }
}

void s_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (stap_state.state) {
        case SINGLE_TAP: unregister_code(KC_S); break;
        case SINGLE_HOLD:
            unregister_code(KC_S);
            unregister_code(KC_RALT);
            break;
        //case DOUBLE_TAP: unregister_code(KC_ESC); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_S);
    }
    stap_state.state = 0;
}

static tap utap_state = {
    .is_press_action = true,
    .state = 0
};

void u_finished(qk_tap_dance_state_t *state, void *user_data) {
    utap_state.state = cur_dance(state);
    switch (utap_state.state) {
        case SINGLE_TAP: register_code(KC_U); break;
        case SINGLE_HOLD:
        register_code(KC_RALT);
        register_code(KC_Y);
        break;
       // case DOUBLE_TAP: register_code(KC_ESC); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_U); register_code(KC_U); break;
    }
}

void u_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (utap_state.state) {
        case SINGLE_TAP: unregister_code(KC_U); break;
        case SINGLE_HOLD:
            unregister_code(KC_Y);
            unregister_code(KC_RALT);
            break;
        //case DOUBLE_TAP: unregister_code(KC_ESC); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_U);
    }
    utap_state.state = 0;
}

static tap otap_state = {
    .is_press_action = true,
    .state = 0
};

void o_finished(qk_tap_dance_state_t *state, void *user_data) {
    otap_state.state = cur_dance(state);
    switch (otap_state.state) {
        case SINGLE_TAP: register_code(KC_O); break;
        case SINGLE_HOLD:
        register_code(KC_RALT);
        register_code(KC_P);
        break;
       // case DOUBLE_TAP: register_code(KC_ESC); break;
        //case DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case DOUBLE_SINGLE_TAP: tap_code(KC_O); register_code(KC_O); break;
    }
}

void o_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (otap_state.state) {
        case SINGLE_TAP: unregister_code(KC_O); break;
        case SINGLE_HOLD:
            unregister_code(KC_P);
            unregister_code(KC_RALT);
            break;
       // case DOUBLE_TAP: unregister_code(KC_ESC); break;
        //case DOUBLE_HOLD: unregister_code(KC_LALT);
        case DOUBLE_SINGLE_TAP: unregister_code(KC_O);
    }
    otap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [A_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, a_finished, a_reset),
    [U_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_finished, u_reset),
    [O_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, o_finished, o_reset),
    [S_UMLAUT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s_finished, s_reset)
};




