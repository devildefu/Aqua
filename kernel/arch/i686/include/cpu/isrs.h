#ifndef ISRS_H
#define ISRS_H

#include <cpu/idt.h>
#include <video/tty.h>
#include <stdint.h>

#include <debug/debug.h>

enum ExceptionType {
	Fault,
	Trap,
	Abort,
	Unknown
};

void isrs_init();

#endif