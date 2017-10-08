#include "string.h"
#include "definitions.h"
#include "vga.h"

void atoi(char *str, int* a)
{
    int k = 0;
    while(*str)
    {
        k = (k<<3)+(k<<1)+(*str)-'0';
        str++;
    }
    *a = k;
}
/*
void d2s(double d, char* string, size_t size, char dot) {
    if(size < 0) return;
    char isMinus = 0; if(d < 0) isMinus = 1;
    char isFloat = 0; if(d-(int64_t)d>0) isFloat = 1;
    size_t tab_n = 0; string[tab_n] = '\0';
    if(isMinus) {string[tab_n] = '-'; tab_n++; d=-d;}
    int64_t dot_pos = d;
    do {
        d/=10;
    }
    while(d>0);
    int64_t temp = 0;
    char dotSet = 0;
    while(d != (int64_t)d) {
        if(tab_n >= size) return;
        else if(tab_n < size-1) {string[tab_n] = '\0'; return;}
        if((int64_t)d == dot_pos && !dotSet) {
            string[tab_n] = dot;
            ++tab_n;
            dotSet = 1;
        }
        d*=10;
        string[tab_n] = '0' + ( (int64_t)d - temp*10 );
        ++tab_n;
    }
}
*/

int getStringn(char* ptr, unsigned int ptr_size) {
    if(ptr_size > 0) {
        for(int i = 0; i<ptr_size-1; i++) {
            ptr[i] = getchar();
        }
        ptr[ptr_size-1] = '\0';
        return 0;
    }
    return 1;
}
int getStringc(char* ptr, unsigned int ptr_size, char CHAR) {
    if(ptr_size > 0) {
        for(int i = 0; i<ptr_size-1; i++) {
            char ch = getchar();
            if(ch != CHAR) {
                ptr[i] = ch;
            }
            else {
                ptr_size = i+1;
                break;
            }
        }
        ptr[ptr_size-1] = '\0';
    }
    return 1;
}
int strcmp(const char* a, const char* b) {
    unsigned int size_a = 0;
    unsigned int size_b = 0;
    for(int i = 0;;i++) {
        if(a[i]!='\n') size_a++;
        else break;
    }
    for(int i = 0;;i++) {
        if(b[i]!='\n') size_b++;
        else break;
    }
    if(size_a > size_b) return 1;
    size_b = 0;
    for(int i = 0; i<size_a; i++) {
        if(a[i] == b[i]) size_b++;
    }
    if(size_b >= size_a) return 0;
    return -1;
    
}


