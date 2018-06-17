#ifndef __ARG_H_
#define __ARH_H_

#include <kernel/include/definitions.h>

typedef void* va_list;

#define va_start(va, last) va = sizeof(last)+(va_list)&last
#define va_arg(va, type) *(type*)((va+=sizeof(type))-sizeof(type))

#define va_end(va) va = (va_list)0


#endif
