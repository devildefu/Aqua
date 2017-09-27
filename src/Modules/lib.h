#ifndef __LIB_H_
#define __LIB_H_
#include "definitions.h"

void atoi(char *str, int* a);

///SYS////
extern char memory_allocated[memShortSize];

int check_bit(char* _byte_);
void set_bit(char* _byte_, unsigned char bit);

void* malloc(unsigned size); //<- Not now, maybe tomorrow
void free(void* ptr); //<- Not now, maybe tomorrow

int memcmp(const void* a, const void* b, unsigned int size);
void* memcpy(void* destination, const void* from, unsigned int block_size);

void sleep(int ms); //<- Waits until time
int clock(); //<- Returns processor clock
void timer(int ms, void(*func)()); //<- Waits some time and calls function


#endif
