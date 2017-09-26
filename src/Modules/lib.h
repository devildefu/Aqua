#ifndef __LIB_H_
#define __LIB_H_
#include "definitions.h"

void atoi(char *str, int* a);

///SYS////
extern struct _byte_ {
  char _1:1, _2:1, _3:1, _4:1,
       _5:1, _6:1, _7:1, _8:1;
} mall_memory[memShortSize]; 

inline void blockBit(size_t pos, size_t bit);
inline uint32_t findBit(size_t pos, char block);

void* malloc(unsigned size); //<- Not now, maybe tomorrow
void free(void* ptr); //<- Not now, maybe tomorrow

int memcmp(const void* a, const void* b, unsigned int size);
void* memcpy(void* destination, const void* from, unsigned int block_size);

void tsleep(int ms); //<- waits some time


#endif
