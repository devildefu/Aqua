#include "lib.h"
#include "definitions.h"

void atoi(char *str, int* a)
{
    #include "vga.h"
    int k = 0;
    while(*str)
    {
        k = (k<<3)+(k<<1)+(*str)-'0';
        str++;
    }
    *a = k;
}

//////////
///SYS////
inline uint32_t findBit(size_t pos) {
    if(!mall_memory[]._1) return 1;
    if(!mall_memory[]._2) return 2;
    if(!mall_memory[]._3) return 3;
    if(!mall_memory[]._4) return 4;
    if(!mall_memory[]._5) return 5;
    if(!mall_memory[]._6) return 6;
    if(!mall_memory[]._7) return 7;
    if(!mall_memory[]._8) return 8;
    return 0;
}

void* malloc(size_t size) {
    if(size > 0) {
        for(uint32_t i = 0; i<memShortSize; i++) {
            uint32_t counter = findBit(i);
            //TODO Make it workable
        }
    }
    return NULL;
}
void free(void* ptr); //<- Not now, maybe tomorrow

int memcmp(const void* a, const void* b, unsigned int size) {
    if(size>0) {
        unsigned int goodbytes = 0;
        for(int i = 0; i<size; i++) {
            if(((const char*)a)[i] == ((const char*)b)[i]) goodbytes++;
        }
        if(goodbytes>=size) return 0;
        if(((const char*)a)[0] > ((const char*)b)[0]) return 1;
        if(((const char*)a)[0] < ((const char*)b)[0]) return -1;
    }
    return 1;
}

void* memcpy(void* destination, const void* from, unsigned int block_size) {
    if(block_size>0) {
        for(int i = 0; i<block_size; i++) {
            ((char*)destination)[i] = ((const char*)from)[i];
        }
    }
    return destination;
}

void tsleep(int ms) {
     ms *= 1000; 
     for(int i = 0; i<ms; i++) {}
 }
