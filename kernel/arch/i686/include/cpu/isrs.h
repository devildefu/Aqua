#ifndef ISRS_H
#define ISRS_H

#include <cpu/idt.h>
#include <video/tty.h>
#include <stdint.h>

#include <debug/debug.h>

enum _ExceptionType {
	Fault,
	Trap,
	Abort,
	Unknown
};

typedef enum _ExceptionType ExceptionType;

/**
 * Setups all exceptions
 */
void isrs_init();

#endif