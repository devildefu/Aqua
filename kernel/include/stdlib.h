#ifndef __STDLIB_H_
#define __STDLIB_H_

#include <stdint.h>
#include <video/tty.h>
static unsigned long int next = 1;

__attribute__((noreturn)) void abort(void);

int rand(void);
void srand(uint32_t seed);

#endif