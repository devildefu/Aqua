#ifndef __MECHANISMS_H_
#define __MECHANISMS_H_
#include "device.h"

typedef struct __dev_k_keybuffer__ {
    char ch[96/8];
} _dev_k_keybuffer_;

/*Keyboard device struct. Inherits from device*/
typedef struct __dev_keyboard__ {

    struct _device_ dev[1];
    struct __dev_k_keybuffer__ buf[1];
    char led_states;


} _packed_ _dev_keyboard_;

#endif