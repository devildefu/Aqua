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
struct used_mem {
    char a:1; char b:1; char c:1;
    char d:1; char e:1; char f:1;
    char g:1; char h:1;

void* malloc(unsigned size); //<- Not now, maybe tomorrow
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
