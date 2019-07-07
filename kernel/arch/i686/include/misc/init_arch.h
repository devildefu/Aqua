#ifndef INITARCH_H
#define INITARCH_H

#include <cpu/gdt.h>
#include <cpu/idt.h>
#include <cpu/isrs.h>
#include <devices/serial.h>

/**
 *  Initiates architecture-specific devices
 */
void init_arch();

#endif