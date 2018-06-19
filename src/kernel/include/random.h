#ifndef __RANDOM_H_
#define __RANDOM_H_

#include <kernel/include/definitions.h>

static unsigned long int next = 1;

int rand(void);
void srand(uint32_t seed);

#endif
