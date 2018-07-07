#include <core/include/memory.h>

static alloc_table mall_table;

void init_ram_alloc_table(alloc_table* tab) {
    mall_table = *tab;
}

void init_ram(void* start, void* end, uint32_t limit) {
    mall_table.start = start;
    mall_table.end = end;
    mall_table.alloc_limit = limit;
    
}

void* m_alloc(size_t size) {
    
}


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
