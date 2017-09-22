#include "keyboard.h"
#include "io.h"

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

char getchar() {
	//return scancode[getScancode()+1];	
}
