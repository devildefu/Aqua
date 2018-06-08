#ifndef __DEVICE_PS2_H_
#define __DEVICE_PS2_H_

#include <drivers/device.h>

static dev_mode _ps2[1];

void* ps2_procedure(int signal, void* data, size_t size, struct _device_* d);

enum _ps2_devs {
    PS2_AncientAT,
    PS2_Mouse,
    PS2_ScrollMouse = 0x03,
    PS2_5ButtonMouse,
    PS2_MF2Keyboard = 0xAB
};

uint8_t ps2_detect_device();

#define init_ps2() \
    init_devmode(_ps2,ps2_procedure)

#endif