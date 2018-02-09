#include "../Include/memory.h"
#include "../Include/definitions.h"

/*
//////////
///SYS////

///TO DO Operation on bits and malloc

inline int editBit(size_t pos, size_t)

inline void blockBit(size_t pos, size_t bit) {
    if(pos < memShortSize) {
        if(!mall_memory[pos]._1) return 1;
        if(!mall_memory[pos]._2) return 2;
        if(!mall_memory[pos]._3) return 3;
        if(!mall_memory[pos]._4) return 4;
        if(!mall_memory[pos]._5) return 5;
        if(!mall_memory[pos]._6) return 6;
        if(!mall_memory[pos]._7) return 7;
        if(!mall_memory[pos]._8) return 8;
    }
}

inline uint32_t findBit(size_t pos, char block) {
    if(pos < memShortSize) {
        if(!mall_memory[pos]._1) return 1;
        if(!mall_memory[pos]._2) return 2;
        if(!mall_memory[pos]._3) return 3;
        if(!mall_memory[pos]._4) return 4;
        if(!mall_memory[pos]._5) return 5;
        if(!mall_memory[pos]._6) return 6;
        if(!mall_memory[pos]._7) return 7;
        if(!mall_memory[pos]._8) return 8;
    }
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

*/

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

void* memset(void* ptr, char value, size_t num) {
    if(num>0) {
        for(int i = 0; i<num; i++) {
            ((char*)ptr)[i] = value;
        }
    }
    return ptr;
}
