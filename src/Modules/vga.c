#include "vga.h"
#include "definitions.h"
#include "io.h"

char* vga_buffer = (char*)0xb8000;
 
void clear() {
	unsigned short j = 0;
 
	while(j < 80 * 25 * 2) {
		vga_buffer[j] = ' ';
		vga_buffer[j+1] = 0x07;
		j += 2;
	}
}
 
void putchar(char character) {
	switch(character) {
	case '\n':
		m.p+=((80*2)-(m.p%(80*2)));
		gotoxy(0,m.p/(80*2));
		break;
	case 32:
		m.p+=2;
		gotoxy(m.p%(80*2), m.p/(80*2));
		break;
	default:
		vga_buffer[i] = character;
		break;
	}
	uint16_t* color = (uint16_t*)0x1001;
	vga_buffer[i+1] = *color;
}

void puts(const char* string) {
	unsigned short i = 0;
 
	while(string[i] != '\0') {
		putchar(string[i]);
		i += 1;
 	}
}

void color(uint16_t color) {
	uint16_t* colptr = (uint16_t*)0x1001;
	*colptr = color;
}

void gotoxy(int x, int y) {
	m.p = x+y*80*2;
	
	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char)((m.p/2)&0xFF));
}
