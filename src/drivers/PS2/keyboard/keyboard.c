#include "keyboard.h"

#include <drivers/procedures.h>
#include <kernel/io/ports.h>

void* __ps2_keyboard_entry(int signal, void* data, size_t size, _dev_keyboard_* k_ptr) {
    switch(signal) {
    case __dev_keyboard_keycode:
        return __ps2__key__keycode();
    case __dev_keyboard_khbit:
        return __ps2__key__khbit();
    case __dev_keyboard_led:
        __ps2__key__led(k_ptr);
        return 0x01;
    return 0;
    }
}

char __ps2__key__khbit() {
    return inb(0x64) & 0x01;
}

char __ps2__key__keycode() {
    return inb(0x60);
}

void __ps2__key__led(_dev_keyboard_* k_ptr) {
    outb(0x60, 0xED);
    outb(0x60, k_ptr->led_states);
}