#include "ps2.h"

#include "keyboard/keyboard.h"
#include <kernel/io/ports.h>

void* ps2_procedure(int signal, void* data, size_t size, struct _device_* d_ptr) {
    switch(d_ptr->device_s) {
    case __dev_keyboard:
        return __ps2_keyboard_entry(signal,data,size,(_dev_keyboard_*)d_ptr);
    }
    return 0;
}

uint8_t ps2_detect_device() {
    outb(0x60, 0xF5);
    while(inb(0x60) != 0xFA);
    outb(0x60, 0xF2);
    while(inb(0x60) != 0xFA);
    uint8_t r = inb(0x60);

    outb(0x60, 0xF4);
    return r;
}