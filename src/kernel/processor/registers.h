#ifndef __REGS_H_
#define __REGS_H_

#include <kernel/utils/definitions.h>

typedef struct regs {

    uint32_t eax, ebx, ecx,
             edx, eip, esp,
             ebp;

} _regs;

/* Throws all registers to a structure */
int throw_regs(_regs* regs_p);

/* Sets all registers from structure and jumps to code pointed by eip
 * ebx register will not be setted because it is used as a temponary register*/
void set_regs(_regs* regs_p);

/* segment:offset memory data functions */
void pokeb(uint16_t segment, uint32_t offset, uint8_t byte);
uint8_t peekb(uint16_t segment, uint32_t ofsset);

void pokew(uint16_t segment, uint32_t offset, uint16_t word);
uint16_t peekw(uint16_t segment, uint32_t offset);

uint16_t getseg();

#endif