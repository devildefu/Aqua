#ifndef __PS2_KEY_H_
#define __PS2_KEY_H_

#include <devices/device.h>
#include <devices/keyboard.h>
#include <ports.h>
#include <stddef.h>
#include <stdint.h>

ulong_t __ps2_keyboard_entry(int signal, void* data, size_t size, _dev_keyboard_* k_ptr);

char __ps2__key__kbhit();
char __ps2__key__keycode();
void __ps2__key__led(_dev_keyboard_* k_ptr);

#endif
