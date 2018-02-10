#include "../Include/string.h"
#include "../Include/definitions.h"
#include "../Include/vga.h"
#include "../Include/keyboard.h"

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

#define DRAW_STRING
char* getStringn(char* ptr, unsigned int ptr_size) {
    if(ptr_size > 0) {
        for(int i = 0; i<ptr_size-1; i++) {
            ptr[i] = getchar(GET_WAIT);
            #ifdef DRAW_STRING
                putchar(ptr[i]);
            #endif
        }
        #ifdef DRAW_STRING
            putchar('\n');
        #endif
        ptr[ptr_size-1] = '\0';
    }
    return ptr;
}
char* getStringc(char* ptr, unsigned int ptr_size, char CHAR) {
    if(ptr_size > 0) {
        for(int i = 0; i<ptr_size-1; i++) {
            char ch = getchar(GET_WAIT);
            if(ch != CHAR) {
                ptr[i] = ch;
                #ifdef DRAW_STRING
                    putchar(ptr[i]);
                #endif
            }
            else {
                ptr_size = i+1;
                break;
            }
        }
        #ifdef DRAW_STRING
            putchar('\n');
        #endif
        ptr[ptr_size-1] = '\0';
    }
    return ptr;
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
_Bool reverse(void* _ptr, size_t size) {
    if(size==0) return 0;
    for(size_t i = 0; i < size/2; i++) {

        char* c_1 = (char*)(_ptr + i);
        char* c_2 = (char*)(_ptr + size - i - 1);

        char D = *c_1;
        char C = *c_2;

        *c_1 = C;
        *c_2 = D;
    }
    return 1;
}

_Bool integerToString(int32_t integer, char* _ptr) {
    if(integer < 0) {
        integer = -integer;
        *_ptr = '-';
        _ptr++;
    }
    int iter = -1;
    do {
        iter++;
        _ptr[iter] = (integer % 10) + 48;
        integer/=10;
    } while(integer > 0);
    reverse(_ptr,iter+1);
    _ptr[iter+1] = '\0';
    return 1;

}
