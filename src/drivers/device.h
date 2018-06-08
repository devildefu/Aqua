#ifndef __DEVICE_H_
#define __DEVICE_H_

#include <kernel/utils/definitions.h>

struct _device_;

typedef void*(*dev_mode__procedure)(int signal, void* data, size_t size, struct _device_* d_ptr);

enum _dev_mode_device_ {
    __dev_keyboard,
    __dev_mouse
} dev_mode_device;

typedef struct _dev_mode_ {
    dev_mode__procedure proc;
} dev_mode;

typedef struct _device_ {
    
    int device_s;
    dev_mode* devmode;

} _packed_ device;

#define devProc(signal, data, size, dev) \
    dev->devmode->proc(signal, data, size, dev)

#define devCast(dev) ((device*)dev)

#define platformCmp(devm0, devm1) \
    devm0->proc == devm1->proc

#define checkPlatform(dev, plat) \
    platformCmp(dev->devmode,plat)

#define setPlatform(dev, plat) \
    dev->devmode = plat

#define checkIndex(dev, ind) \
    dev->device_s == ind

#define init_device(dv,tp,dm) \
    dv->devmode = dm; \
    dv->device_s = tp

#define init_devmode(d,pr) \
    d->proc = pr

#endif

