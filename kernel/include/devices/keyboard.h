#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

#include <definitions.h>
#include <stdint.h>
#include <maths.h>
#include <devices/keyboard.h>
#include "device.h"

/* Enum of keyboard leds */
enum _key_leds_ {
    _KLED_CAPSLOCK = 1,
    _KLED_SCRLOCK = 2,
    _KLED_NUMLOCK = 4
};

/* Enum of supported langs */
enum _scancode_langs_ {
    _KB_LAYOUT_QWERTY
};

/* Enum of all keyboard keycodes */
enum _keys_ {
    _K_ESC = 0x01,
    _K_1,
    _K_2,
    _K_3,
    _K_4,
    _K_5,
    _K_6,
    _K_7,
    _K_8,
    _K_9,
    _K_0,
    _K_DASH,
    _K_EQUAL,
    _K_BACKSPACE,
    _K_TAB,
    _K_Q,
    _K_W,
    _K_E,
    _K_R,
    _K_T,
    _K_Y,
    _K_U,
    _K_I,
    _K_O,
    _K_P,
    _K_SQUARE_BRACKET_OP,
    _K_SQUARE_BRACKET_EN,
    _K_ENTER,
    _K_LCTRL,
    _K_A,
    _K_S,
    _K_D,
    _K_F,
    _K_G,
    _K_H,
    _K_J,
    _K_K,
    _K_L,
    _K_SEMICOLON,
    _K_SINGLE_QUOTE,
    _K_BACK_TICK,
    _K_LSHIFT,
    _K_BACKSLASH,
    _K_Z,
    _K_X,
    _K_C,
    _K_V,
    _K_B,
    _K_N,
    _K_M,
    _K_COMMA,
    _K_DOT,
    _K_SLASH,
    _K_RSHIFT,
    _K_MULTI,
    _K_LALT,
    _K_SPACE,
    _K_CAPS_LOCK,
    _K_F1,
    _K_F2,
    _K_F3,
    _K_F4,
    _K_F5,
    _K_F6,
    _K_F7,
    _K_F8,
    _K_F9,
    _K_F10,
    _K_NUMLOCK,
    _K_SCRLOCK,
    _K_NUM7,
    _K_NUM8,
    _K_NUM9,
    _K_NUMMINUS,
    _K_NUM4,
    _K_NUM5,
    _K_NUM6,
    _K_NUMPLUS,
    _K_NUM1,
    _K_NUM2,
    _K_NUM3,
    _K_NUM0,
    _K_NUMDOT,

    _K_F11 = 0x57,
    _K_F12,

    /* Additional keycodes meaning if switch key is set for */
    _K_R_CAPSLOCK,
    _K_R_SCRLCK,
    _K_R_NUMLOCK,
    _K_R_SHIFT,
    _K_R_CONTROL,

    /* Count of keycodes in enum */
    _K_COUNT = _K_R_CONTROL

};


enum _dev_keyboard_proc_signals_ {
    __dev_keyboard_kbhit,
    __dev_keyboard_keycode,
    __dev_keyboard_led
};

typedef struct __dev_k_keybuffer__ {
    char ch[_K_COUNT/8];
} _dev_k_keybuffer_;

/*Keyboard device struct. Inherits from device*/
typedef struct __dev_keyboard__ {

    struct _device_ dev[1];
    struct __dev_k_keybuffer__ buf[1];
    char led_states;


} _packed_ _dev_keyboard_;

/* Extern default PS/2 keyboard
 * Defined in keyboard.c */
extern _dev_keyboard_ def_keyboard[1];

/* Check if key is clicked */
int _key_clck(char key, _dev_keyboard_* k);

/* Switch key status */
void _set_key(char key, _dev_keyboard_* k);

/* Translate keycode 's' into an ascii character appropriate to 'lang' for keyboard 'd'.
 * Keyboard argument is required, because of special switches like SHIFT or CAPS LOCK.
 * Translating function must know when to replace 'a' to 'A' or '9' to '('.
 * If 'd' argument is NULL, then keyboard switches are ignored and characters are always lower-case. */
uint8_t translate_keycode(uint8_t s, int layout, _dev_keyboard_* d);

/* Update keyboard settings from a key 's'. */
uint8_t access_keyboard_settings(uint8_t s, _dev_keyboard_* d);

/* Get last hit key for keyboard 'd'. */
uint8_t _kbhit(_dev_keyboard_* d);

/* Do _kbhit, but additionally wait for a hit if required. */
uint8_t _keycode(_dev_keyboard_* d, char wait);

/* Get keycode and translate it into an ascii char. Wait if required. */
char _getch(_dev_keyboard_* d, int layout, char wait);

/* Update leds for a keyboard 'd'. */
void _update_led_states(_dev_keyboard_* d);

/* Pragmas shortening invocations to use default keyboard 'def_keyboard'. */
#define key_clck(key) _key_clck(key, def_keyboard)
#define set_key(key) _set_key(key, def_keyboard)
#define kbhit() _kbhit(def_keyboard)
#define keycode() _keycode(def_keyboard, 1)
#define _getch_(LAYOUT) _getch(def_keyboard,LAYOUT,1)
#define getch() _getch_(_KB_LAYOUT_QWERTY)

/* Set leds in keyboard 'k' */
#define set_leds(leds, k) k->led_states ^= leds

/* Set and update leds in keyboard 'k' */
#define set_and_update_leds(leds, k) \
	{ set_leds(leds, k); _update_led_states(k); }

/* Init in default PS/2 keyboard */
#define init_keyboard() \
    init_device(devCast(def_keyboard), __dev_keyboard, _ps2)

#endif
