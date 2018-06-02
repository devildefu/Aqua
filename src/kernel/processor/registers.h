#ifndef __REGS_H_
#define __REGS_H_

#include <utils/definitions.h>

typedef struct regs {

    uint32_t eax, ebx, ecx,
             edx, eip, esp,
             ebp;

} _regs;

/* Throws all registers to structure */
int throw_regs(_regs* regs_p);
/* Sets all registers from structure and jumps to code pointed by eip
 * ebx register will not be setted because it is used as a temponary register*/
void set_regs(_regs* regs_p);

#endif