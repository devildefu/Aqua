#ifndef __PS2_KEY_H_
#define __PS2_KEY_H_

#include <drivers/PS2/ps2.h>
#include <drivers/device.h>
#include <drivers/mechanisms.h>

void* __ps2_keyboard_entry(int signal, void* data, size_t size, _dev_keyboard_* k_ptr);

char __ps2__key__khbit();
char __ps2__key__keycode();
void __ps2__key__led(_dev_keyboard_* k_ptr);

#endif