#include "string.h"

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

