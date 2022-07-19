#include QMK_KEYBOARD_H

uint8_t current_layer;

enum layers {
    _BASE,
    _DDRAFT,
    _EMPTY,
    _RGB
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_BASE] = LAYOUT_ortho_3x4(
	KC_NUM,  
		KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, 
		KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, 
		KC_KP_9, KC_KP_0, KC_NO, KC_NUM
        ),
    

    [_DDRAFT] = LAYOUT_ortho_3x4(
		KC_NO, 
		KC_SPACE, KC_LEFT_CTRL, KC_LEFT_SHIFT, KC_LEFT_ALT, 
		KC_A, KC_BACKSPACE, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, LCMD(KC_S)
        ),


    [_EMPTY] = LAYOUT_ortho_3x4(
		KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_NO, KC_NO, KC_NO, KC_NO
        ),
  
  
    [_RGB] = LAYOUT_ortho_3x4(
		RGB_TOG, 
		RGB_M_P, RGB_HUI, RGB_HUD, KC_NO, 
		KC_NO, KC_NO, RGB_VAI, RGB_VAD, 
		RGB_SAI, RGB_SAD, KC_NO, KC_NO
        ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    
  switch (get_highest_layer(layer_state)) {
      default:
          if (clockwise) {
              layer_move(_DDRAFT);
          } else {
              layer_on(_BASE);
          }
          break;
      case 1:
          if (clockwise) {
              layer_move(_EMPTY);
          } else {
              layer_move(_BASE);
          }
          break;
      case 2:
          if (clockwise) {
              layer_move(_RGB);
          } else {
              layer_move(_DDRAFT);
          }
          break;

      case 3:
          if (clockwise) {
              layer_on(_RGB);
          } else {
              layer_move(_EMPTY);
          }
          break;
          
  }
    return false;
}




#ifdef OLED_ENABLE

//------------------------------------------------------------------------------------------------

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;  // flips the display 180 degrees if offhand
}
 

static void render_logo(void) {     // Render MechWild "MW" Logo
    static const char PROGMEM logo_1[] = {0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x04, 0x06, 0x82, 0xc3, 0x43, 0x61, 0xa1, 0xa1,0xa1, 0xa1, 0x61, 0x43, 0xc3, 0x82, 0x06, 0x04, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00};
    static const char PROGMEM logo_2[] = {0xf8, 0x1e, 0xc3, 0xf8, 0x5c, 0x76, 0x7b, 0x6d, 0x75, 0x55, 0x55, 0x75, 0x6d, 0x7b, 0x76, 0x5e,0x7e, 0x77, 0x5b, 0x6d, 0x75, 0x55, 0x55, 0x75, 0x4d, 0x7b, 0x66, 0x5c, 0xf0, 0xc3, 0x3e, 0xf0};
    static const char PROGMEM logo_3[] = {0x1f, 0x78, 0xc1, 0x0f, 0x38, 0xe0, 0xc0, 0x00, 0x00, 0x02, 0x0e, 0x0e, 0x8e, 0xc6, 0xc0, 0x40,0x40, 0xc0, 0xc6, 0x8e, 0x0e, 0x0e, 0x02, 0x00, 0x80, 0xc0, 0x60, 0x38, 0x0f, 0xc0, 0x7c, 0x0f};
    static const char PROGMEM logo_4[] = {0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x31, 0x23, 0x66, 0x44, 0x44, 0xc4, 0xc4, 0x84, 0x84,0x84, 0x84, 0xc4, 0xc4, 0x44, 0x46, 0x66, 0x23, 0x11, 0x18, 0x0c, 0x06, 0x03, 0x00, 0x00, 0x00};
    oled_set_cursor(0,0);
    oled_write_raw_P(logo_1, sizeof(logo_1));
    oled_set_cursor(0,1);
    oled_write_raw_P(logo_2, sizeof(logo_2));
    oled_set_cursor(0,2);
    oled_write_raw_P(logo_3, sizeof(logo_3));
    oled_set_cursor(0,3);
    oled_write_raw_P(logo_4, sizeof(logo_4));
}
//-----------



bool oled_task_user(void) {

    
    render_logo();
    oled_set_cursor(7,0);
    oled_write_P(PSTR("k8 Noodle"), false);

    oled_set_cursor(7,1);
    oled_write_P(PSTR("Layer: "), false);

   switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("Numpad "), false);
      break;
    case _DDRAFT:
      oled_write_P(PSTR("DDraft "), false);
      break;
    case _EMPTY:
      oled_write_P(PSTR("Empty "), false);
      break;      
    case _RGB:
      oled_write_P(PSTR("RGB  "), false);
      break; 
    
    
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_P(PSTR("N/A "), false);
  }
  	oled_set_cursor(7,2);
    oled_write_P(PSTR("Status: "), false);
    oled_set_cursor(7,3);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("   "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("   "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("   "), false);

return false;
}

#endif

