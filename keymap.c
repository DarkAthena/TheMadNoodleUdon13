/* Copyright 2022 @ DarkAthena
	~~~Amazing, patient, and generous help was provided by elpekeñin in the QMK Discord. He was so patient and walked me through so much that this wouldnt' have happened without him. I'd also like to 
	thank Dasky from the same Discord, who hopped in when elpekeñin and I got stuck on the RGB code formatting. Thank you!~~~
	
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

//Layer Names below
enum layer_names {
  _QWERTY = 0,
  _RESET,
};

//defining colors, in HSV. Find RGB colors then do math: H * 255/360 gives the value in 0-255. White does not require a definition. Red is 0.
//Indexes are the keymap numbers of the keys you want to assign certain colors to. See keyvalue map at bottom of file.
#define PINK 239
uint8_t indexes_pink[] = {1, 2, 3, 4, 7, 8, 9, 10, 13, 14, 15, 16, 19, 20, 21, 22, 24, 25, 26, 27, 29, 30, 31, 32, 35, 36, 37, 38, 40, 41, 42, 43, 45, 46, 47, 48, 51, 52, 53, 54, 57, 58, 59, 60, 62, 63, 64, 67, 68, 70, 71, 73, 74, 76, 77, 78, 80, 81, 83, 84, 85, 87, 88, 89, 90, 91, 92, 93, 96}; // replace with your indexes


#define BLUE 147
uint8_t indexes_blue[] = {5, 6, 11, 12, 17, 18, 23, 28, 33, 34, 39, 44, 49, 50, 55, 56, 61, 65, 66, 72, 75, 79, 86, 82, 94, 95, 97}; // replace with your indexes


uint8_t indexes_white[] = {69}; // replace with your indexes

#define RED 0
uint8_t indexes_red[] = {0}; // replace with your indexes


//Below is the list of layers that you have on your keyboard. Use the layer names above to refer to each layer. The names must be defined above. For a full list of 
//keys you can use, visit https://docs.qmk.fm/#/keycodes
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     F13           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 Layer
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             F14
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       F15
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
	  
  [_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          TG(1),
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_F14,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_F15,
        KC_LGUI, KC_LALT, KC_LCTL,                          KC_SPC,                             KC_RCTL, KC_APP,   KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	
    [_RESET] = LAYOUT(
        EE_CLR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_SLEP,            KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,          KC_MPLY,
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, RESET,            KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,          KC_NO,          GUI_OFF,
        KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    NK_TOGG,    KC_NO,    KC_NO, KC_NO, KC_NO,          KC_NO, RGB_M_P,   GUI_ON,
        KC_NO, KC_NO, KC_NO,                            KC_NO,                             KC_NO, KC_NO,   KC_NO, RGB_VAD, RGB_TOG, RGB_VAI
    ),
};
// clang-format on

//Enables the rotary encoder. Messing with this can change what it does, but I don't know how to do that so I leave it alone.
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
  return true;
}
#endif // ENCODER_ENABLE

//Setting up the RGB using HSV colorspace. Honestly, I have no idea what any of this means, but I can tell you what the code sections do. 
void rgb_matrix_indicators_user(void) {

  uint8_t val = rgb_matrix_get_val();
  uint8_t sat = rgb_matrix_get_sat();
//these lines below reference the HSV colors defined at the top of the document. I think they translate the HSV colors to RGB, but I'm not sure. Anyway, you need 'em.
  HSV hsv = {.h = PINK, .s = sat, .v = val};
  RGB rgb_pink = hsv_to_rgb(hsv);
  hsv.h = BLUE;
  RGB rgb_blue = hsv_to_rgb(hsv);
  hsv.h = RED;
  RGB rgb_red = hsv_to_rgb(hsv);
  hsv.s = 0;
  RGB rgb_white = hsv_to_rgb(hsv);
//Okay, these lines below define which keys are what color based on the indexes above. Apparently you need an index and then this loop to make sure the LEDs get colored correctly.
  for (uint8_t i = 0; i < sizeof(indexes_pink); i++) {
    rgb_matrix_set_color(indexes_pink[i], rgb_pink.r, rgb_pink.g, rgb_pink.b);
  }
  for (uint8_t i = 0; i < sizeof(indexes_blue); i++) {
    rgb_matrix_set_color(indexes_blue[i], rgb_blue.r, rgb_blue.g, rgb_blue.b);
  }
  for (uint8_t i = 0; i < sizeof(indexes_white); i++) {
    rgb_matrix_set_color(indexes_white[i], rgb_white.r, rgb_white.g, rgb_white.b);
  }
  for (uint8_t i = 0; i < sizeof(indexes_red); i++) {
    rgb_matrix_set_color(indexes_red[i], rgb_red.r, rgb_red.g, rgb_red.b);
  }
//The two blocks below are for the Caps Lock key and my Layer Toggle Key. They change the color and brightness of the keys' LEDs when they're active. The GMMK Pro blinks the side lights by default
//when Caps Lock is on, but I can't see that. Who sees that? Like I'm gonna look at the side of my board. Anyway, this changes the color when the keys are active. Change the .h = [value] to change
//the color and the .v = [value] to change the brightness of the LED. The .s = [value] changes the vibrancy of the color. I like my colors as vibrant as possible, so I leave it alone. If you change
//the colors (hue), change the [rgb_deep_blue] bits to reflect the actual human-readable color. Example: RGB rgb_deep_blue = hsv_to_rgb(hsv);rgb_matrix_set_color(3, rgb_deep_blue.r, rgb_deep_blue.g, rgb_deep_blue.b); would become
 //RGB rgb_yello = hsv_to_rgb(hsv);rgb_matrix_set_color(3, rgb_yellow.r, rgb_yellow.g, rgb_yellow.b). Get it? It took me forever to get it.
 
 // capslock key code
  if (host_keyboard_led_state().caps_lock) {
    HSV hsv = {.h = 169, .s = sat, .v = 255};
    RGB rgb_deep_blue = hsv_to_rgb(hsv);
    rgb_matrix_set_color(3, rgb_deep_blue.r, rgb_deep_blue.g, rgb_deep_blue.b);
  }
  // layer key code
  if (get_highest_layer(layer_state | default_layer_state) == _RESET) {
    HSV hsv = {.h = 21, .s = sat, .v = 255};
    RGB rgb_orange = hsv_to_rgb(hsv);
    rgb_matrix_set_color(75, rgb_orange.r, rgb_orange.g, rgb_orange.b);
  }
}
//Uhhh, I'm not really sure what this does other than makes sure all this stuff doesn't get written to the eeprom, which is apparently a bad thing to do. According to Dasky. 
void keyboard_post_init_user(void) {

  rgb_matrix_mode_noeeprom(1);
}

// RGB LED layout - keyvalue map. The numbers to the left of the keys are the numbers that you put in the color indexes. 
// FORMAT: led number, function of the key

//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt      Rotary(Mute)   68, Side led 12
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, layer       74, Side led 14
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, F13       77, Side led 15
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, F14        81, Side led 16
//  83, Side led 06    5, L_GUI     11,Alt_L   17, Ctrl_L                              33, SPACE                              49, CTRL_R    55, FN                    65, Alt_R     95, Left     97, Down      79, Right      84, Side led 17
//  87, Side led 07                                                                                                                                                                                                        88, Side led 18
//  91, Side led 08    