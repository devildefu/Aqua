#ifndef __SETJMP_H_
#define __SETJMP_H_

#include "registers.h"

typedef _regs _jmp_buf;
typedef _jmp_buf jmp_buf[1];

/* Saves all registers to *env */

int setjmp(_jmp_buf* env);

/* Restores registers from *env
 * and jumps to code pointed by eip*/

void longjmp(_jmp_buf* env, int signal);

/*Jumps to eip*/

void _jmp(int eip);

/*Gets eip*/

int geteip();

#endif