#include "vga.h"
char* vga_buffer = (char*)0xb8000;
 
 void clear() {
 	unsigned short j = 0;
 
 	while(j < 80 * 25 * 2) {
 		vga_buffer[j] = ' ';
 		vga_buffer[j+1] = 0x07;
 		j += 2;
 	}
 }
 
 void puts(const char* string) {
 	unsigned short i = 0;
 	unsigned short j = 0;
 
 	while(string[i] != '\0') {
 		vga_buffer[j] = string[i];
 		vga_buffer[j+1] = 0x07;
 		j += 2;
 		i += 1;
 	}
 }
