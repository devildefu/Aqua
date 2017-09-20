#include "vga.h"
char* vga_buffer = (char*)0xb8000;
 
void clear() {
 unsigned short j = 0;
 
 while(j < 80 * 25 * 2) {
 	putchar(' ', j);
  j += 2;
 }
}
 
void putchar(char character, int pos) {
 vga_buffer[pos] = character;
 vga_buffer[pos+1] = 0x07;
}

void puts(const char* string) {
 unsigned short i = 0;
 unsigned short j = 0;
 
 while(string[i] != '\0') {
 	putchar(string[i], j);
 	j += 2;
 	i += 1;
 }
}
