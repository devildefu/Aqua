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


////DARK////
char* getStringn(unsigned int size) {
    if(size>0) {
        char* string;
        for(int i = 1; i<=size+1; i++) {
            char* temp = string;
            string = (char*)malloc(sizeof(char)*i);
            for(int j = 0; j<i-1; j++) string[j] = temp[j];
            if(i<size+1) string[i-1] = getchar();
            else string[i-1] = '\0';
            free(temp);
        }
        return string;
    }
    return NULL;
}
char* getStringc(char CHAR) {
    char* string = NULL;
    unsigned int size = 0;
    char ch = getchar();
    while(1) {
        char* temp = string;
        string = (char*)malloc(sizeof(char)*size+1);
        for(int j = 0; j<size; j++) string[j] = temp[j];
        if((ch = getchar()) != CHAR) {
            string[size] = ch;
        }
        else {
            string[size] = '\0';
            break;
        }
        free(temp);
    }
    return string;
}
int getStringnp(char* ptr, unsigned int ptr_size) {
    if(ptr_size > 0) {
        for(int i = 0; i<ptr_size-1; i++) {
            ptr[i] = getchar();
        }
        ptr[ptr_size-1] = '\0';
        return 0;
    }
    return 1;
}
int getStringcp(char* ptr, unsigned int ptr_size, char CHAR) {
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

