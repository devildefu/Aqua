#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

#include <kernel/include/definitions.h>
#include <drivers/device.h>
#include <drivers/mechanisms.h>
#include <drivers/ps2/ps2.h>
#include <drivers/procedures.h>
#include <kernel/include/maths.h>

static _dev_keyboard_ def_keyboard[1];

enum _key_leds_ {
    _KLED_CAPSLOCK = 1,
    _KLED_SCRLOCK = 2,
    _KLED_NUMLOCK = 4
};

enum _scancode_langs_ {
    _SC_US
};

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

    _K_R_BIGLETTERS,
    _K_R_SCRLCK,
    _K_R_NUMLOCK,
    _K_R_SHIFT,
    _K_R_CONTROL

};

int _key_clck(char key, _dev_keyboard_* k);
void _set_key(char key, _dev_keyboard_* k);

#define key_clck(key) _key_clck(key, def_keyboard)
#define set_key(key) _set_key(key, def_keyboard)

uint8_t translate_keycode(uint8_t s, int lang, _dev_keyboard_* d);
uint8_t access_keyboard_settings(uint8_t s, _dev_keyboard_* d);

uint8_t _kbhit(_dev_keyboard_* d);
#define khbit() _kbhit(def_keyboard)

uint8_t _keycode(_dev_keyboard_* d, char wait);
#define keycode() _keycode(def_keyboard, 1)

uint8_t _getch(_dev_keyboard_* d, int lang, char wait);
#define _getch_(LANG) _getch(def_keyboard,LANG,1)
#define getch() _getch_(_SC_US)

#define set_leds(leds, k) d->led_states ^= leds

#define init_keyboard() \
    init_device(devCast(def_keyboard), __dev_keyboard, _ps2)

void _update_led_states(_dev_keyboard_* d);

#endif
