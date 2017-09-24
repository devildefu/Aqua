#ifndef __LIB_H_
#define __LIB_H_

void atoi(char *str, int* a);

///SYS////
void* malloc(unsigned size); //<- Not now, maybe tomorrow
void free(void* ptr); //<- Not now, maybe tomorrow

int memcmp(const void* a, const void* b, unsigned int size);
void* memcpy(void* destination, const void* from, unsigned int block_size);


#endif
