#include "keyboard.h"
#include "io.h"

#define NULL 0

char scancodes[] = 
{0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0F,0x10,
0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1E,0x1F,0x20,
0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2B,0x2C,0x2D,0x2E,0x2F,
0x30,0x31,0x32,0x33,0x34,0x35,0x37,0x39,0x47,0x48,0x49,0x4A,0x4B,0x4C,
0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53};
char codestrans[] = 
{'1','2','3','4','5','6','7','8','9','0','-','=','	','q','w','e','r','t'
,'y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'',
'`','\\','z','x','c','v','b','n','m',',','.','/','*',' ','7','8','9','-',
'4','5','6','+','1','2','3','0','.'};

char getScancode() {
	char c=0;
	do {
		if(inb(0x60)!=c) {
			c=inb(0x60);
			if(c>0) {
				return c;
			}
		}
	} while(1);
}

char getch() {
	char the_scancode = getScancode();
	int n = sizeof(scancodes)/sizeof(scancodes[0]);
	for(int i=0; i < n+1; i++) {
		if(scancodes[i]==the_scancode) {
			return codestrans[i];
			break;
		}
	}
	return ';';
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
