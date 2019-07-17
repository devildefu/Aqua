#include <devices/keyboard.h>
#include <devices/platform-defaults.h>

/* Define default keyboard only if _DEFAULT_KEYBOARD_MODE is defined */
#ifdef _DEFAULT_KEYBOARD_PROC
	define_device_tb(def_keyboard, _dev_keyboard_, __dev_keyboard, _DEFAULT_KEYBOARD_PROC);
#endif

int _key_clck(char key, _dev_keyboard_* k) {
	return k->buf->ch[key/8] & (1 << (key%8));
}

void _set_key(char key, _dev_keyboard_* k) {
	k->buf->ch[key/8] ^= (1 << (key%8));
}

uint8_t _kbhit(_dev_keyboard_* d) {
	return (uint8_t)devCall(__dev_keyboard_kbhit, NULL, 0, devCast(d));
}

uint8_t _keycode(_dev_keyboard_* d, char wait) {
	if(wait) while(!_kbhit(d));

	return (uint8_t)devCall(__dev_keyboard_keycode, NULL, 0, devCast(d));
}

char _getch(_dev_keyboard_* d, int layout, char wait) {
	return translate_keycode(access_keyboard_settings(_keycode(d,wait),d),layout,d);
}

void _update_led_states(_dev_keyboard_* d) {
	devCall(__dev_keyboard_led, NULL, 0, devCast(d));
}

uint8_t access_keyboard_settings(uint8_t s, _dev_keyboard_* d) {
	char clck = 1;

	if(s >= 0x80) {
		s -= 0x80;
		clck = 0;
	}

	_set_key(s,d);

	#define __set_and_goto_leds(_leds,k) \
		set_leds(_leds, k); goto leds

	if(clck) {
		switch(s) {
			case _K_LSHIFT:
			case _K_RSHIFT:
				if(!_key_clck(_K_R_SHIFT,d)) _set_key(_K_R_SHIFT,d);
				break;

			case _K_R_CONTROL:
				_set_key(_K_R_CONTROL, d);
				break;

			case _K_CAPS_LOCK:
				_set_key(_K_R_CAPSLOCK, d); 
				__set_and_goto_leds(_KLED_CAPSLOCK, d);

			case _K_NUMLOCK:
				_set_key(_K_R_NUMLOCK, d);
				__set_and_goto_leds(_KLED_NUMLOCK, d);

			case _K_SCRLOCK:
				_set_key(_K_R_SCRLCK, d);
				__set_and_goto_leds(_KLED_SCRLOCK, d);
		}
		goto end;
		leds:
		_update_led_states(d);
	} else {
		switch(s) {
			case _K_LSHIFT:
			case _K_RSHIFT:
				if(!_key_clck(_K_LSHIFT,d) && !_key_clck(_K_RSHIFT,d))
					_set_key(_K_R_SHIFT,d);
				break;
		}
	}

	end:
	return clck ? s : 0;
}

uint8_t translate_keycode(uint8_t s, int layout, _dev_keyboard_* d) {

	char shift_clck = 0, capslock_clck = 0, numlock_clck = 0;

	if(d) {
	shift_clck    = _key_clck(_K_R_SHIFT,d);
	capslock_clck = _key_clck(_K_R_CAPSLOCK,d);
	numlock_clck  = _key_clck(_K_R_NUMLOCK,d);
	}

	switch(layout) {
	case _KB_LAYOUT_QWERTY:
	{
		char b;
		if(numlock_clck) {

			switch(s) {

				case _K_NUM0: return '0';
				case _K_NUM1: return '1';
				case _K_NUM2: return '2';
				case _K_NUM3: return '3';
				case _K_NUM4: return '4';
				case _K_NUM5: return '5';
				case _K_NUM6: return '6';
				case _K_NUM7: return '7';
				case _K_NUM8: return '8';
				case _K_NUM9: return '9';

			}
		}

		b = (capslock_clck ^ shift_clck) ? 0x20 : 0x00;

		switch(s) {

			case _K_A: return 'a' - b;
			case _K_B: return 'b' - b;
			case _K_C: return 'c' - b;
			case _K_D: return 'd' - b;
			case _K_E: return 'e' - b;
			case _K_F: return 'f' - b;
			case _K_G: return 'g' - b;
			case _K_H: return 'h' - b;
			case _K_I: return 'i' - b;
			case _K_J: return 'j' - b;
			case _K_K: return 'k' - b;
			case _K_L: return 'l' - b;
			case _K_M: return 'm' - b;
			case _K_N: return 'n' - b;
			case _K_O: return 'o' - b;
			case _K_P: return 'p' - b;
			case _K_Q: return 'q' - b;
			case _K_R: return 'r' - b;
			case _K_S: return 's' - b;
			case _K_T: return 't' - b;
			case _K_U: return 'u' - b;
			case _K_V: return 'v' - b;
			case _K_W: return 'w' - b;
			case _K_X: return 'x' - b;
			case _K_Y: return 'y' - b;
			case _K_Z: return 'z' - b;

		}

		b = shift_clck ? 0x10 : 0x00;

		switch(s) {

			case _K_1: return '1' - b;
			case _K_2: return '2' - b;
			case _K_3: return '3' - b;
			case _K_4: return '4' - b;
			case _K_5: return '5' - b;
			case _K_6: return '6' - b;
			case _K_7: return '7' - b;
			case _K_8: return '8' - b;
			case _K_9: return '9' - b;
			case _K_0: return shift_clck ? ')' : '0';

			case _K_ENTER: return '\n';
			case _K_SPACE: return ' ';
			case _K_ESC: return 0x1B;
			case _K_BACKSPACE: return 0x08;

			case _K_DASH: case _K_NUMMINUS: return '-';

			case _K_BACK_TICK:          return   shift_clck ? '~' : '`';
			case _K_BACKSLASH:          return   shift_clck ? '|' : '\\';
			case _K_SLASH:              return   shift_clck ? '?' : '/';
			case _K_EQUAL:              return   shift_clck ? '+' : '=';
			case _K_COMMA:              return   shift_clck ? '<' : ',';
			case _K_DOT:                return   shift_clck ? '>' : '.';
			case _K_SEMICOLON:          return   shift_clck ? ':' : ';';
			case _K_SINGLE_QUOTE:       return   shift_clck ? '\"' : '\'';
			case _K_SQUARE_BRACKET_OP:  return   shift_clck ? '{' : '[';
			case _K_SQUARE_BRACKET_EN:  return   shift_clck ? '}' : ']';

	   		case _K_NUMPLUS: return '+';
			case _K_MULTI: return '*';

			default: return 0;

		}

	}

	}
	
	return 0;
}
