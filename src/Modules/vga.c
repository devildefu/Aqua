#include "vga.h"
#include "definitions.h"
#include "io.h"

char* vga_buffer = (char*)0xb8000;

uint16_t get_x_coordinate(struct mouse_position* cursor) {
	if(cursor != NULL) {
		return cursor->p % (80*2);
	}
	return 0;
}

uint16_t get_y_coordinate(struct mouse_position* cursor) {
	if(cursor != NULL) {
		return cursor->p / (80*2);
	}
	return 0;
}
 
void clear() {
	unsigned short j = 0;
 
	while(j < 80 * 25 * 2) {
		vga_buffer[j] = ' ';
		vga_buffer[j+1] = 0x07;
		j += 2;
	}
}
 
void putchar(char character) {
	vga_buffer[m.p] = character;
	m.p+=2;
	switch(character) {
	case '\n':
		m.p+=((80*2)-(m.p%(80*2)));
		break;
	case 32:
		m.p+=2;
		break;
	}
	sgotoxy(m.p/2);
	uint16_t* color = (uint16_t*)0x1001;
	vga_buffer[m.p+1] = *color;
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

void mgotoxy(uint16_t xy) { //<- Gotoxy xy
	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char)(xy&0xFF));
}

void sgotoxy(uint16_t x, uint16_t y) { //<- Gotoxy x,y
	mgotoxy(x+y*80));
}
