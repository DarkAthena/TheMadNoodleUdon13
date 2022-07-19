# TheMadNoodleUdon13
My keymap for the Udon 13 by TheMadNoodle

-- The keymap.c file contains the keymap and is ready for your edits. You'll need to setup QMK prior to compiling.

-- The .hex file is the compiled firmware. Flash away.

The Udon13 is perfectly usable out of the box with VIAL compatibility. My issue was the the layer names displayed on the OLED didn't match what I had my keymaps
set to once I'd edited them. There's no way to change layer names in VIAL so yeah. I needed a different solution. QMK to the rescue.

If your OLED names display funky and the logo gets glitchy, fiddle around with this part of the keymap towards the bottom of the file:


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
      
specifically the spaces after "Numpad", "DDraft", "Empty", and "RGB". The trailing spaces seem to hose up the next line somehow. I don't know how because I'm
not a programmer. 

Change the "k8 Noodle" bit if you want to change the name on your pad. The default is "The Mad Noodle".

render_logo();
    oled_set_cursor(7,0);
    oled_write_P(PSTR("k8 Noodle"), false);

That's all. Have fun!
