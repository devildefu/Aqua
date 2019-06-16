#include <string.h>

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

int strcmp(const char* a, const char* b) {
    for(int i = 0;;i++) {
        if(a[i]=='\0' && b[i]!='\0') return -1;
        if(a[i]!='\0' && b[i]=='\0') return 1;
        if(a[i]!=b[i]) return 1;
        if(a[i]=='\0' && b[i]=='\0') break;
    }
    return 0;

}
bool reverse(void* _ptr, size_t size) {
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

bool itos(int32_t integer, char* _ptr) {
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

void htoa(uint32_t h, char* t) {
    t[0] = '0';
    t[1] = 'x';
    t+=2;

    uint32_t i = 0;

    do {
        char d = h % 0x10;
        if(d < 10) d += 0x30;
        else d += 0x41-0x0A;
        t[i] = d;
        i++;
    } while(h /= 0x10);

    t[i] = '\0';

    reverse(t,i);
}

void itoa(int32_t h, char* t) {
  if(h < 0) {
    *t = '-';
    h = -h;
    t++;
  }

  uint32_t i = 0;
  do {
    t[i] = h % 0xA + 0x30;
    i++;
  } while(h /= 0xA);

  t[i] = '\0';
  
  reverse(t,i);
}

size_t strlen(char* str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

char *strcpy(char *src, char *dest)
{
   char *save = dest;
   while(*dest++ = *src++);
   return save;
}
