#include <kernel/include/tty.h>

FILE systty[1] = {{
	.pr = ttyProcedure
}};

static char* vga_buffer = (char*)0xb8000;
struct cursor_position m = {
	.p = 0,
	.c = 0
};

uint16_t get_x_coordinate(struct cursor_position* cursor) {
	if(cursor != NULL) {
		return cursor->p % (80*2);
	}
	return 0;
}

uint16_t get_y_coordinate(struct cursor_position* cursor) {
	if(cursor != NULL) {
		return cursor->p / (80*2);
	}
	return 0;
}

void clear() {
	fill_buffer(0,0);
}

void putchar(char character) {
	switch(character) {
	case '\n':
		vga_buffer[m.p]='\n';
		m.p+=((80*2)-(m.p%(80*2)));
		break;
	case '\0':
		break;
	case 0x08:
		if(m.p > 0) {
			m.p -= 2;
			while(!vga_buffer[m.p] && m.p) {
				m.p -= 2;
			}
			vga_buffer[m.p] = 0;
			vga_buffer[m.p+1] = 0;
		}
		break;
	default:
		vga_buffer[m.p] = character;
		vga_buffer[m.p+1] = m.c;
		m.p+=2;
		break;
	}
	mgotoxy(m.p/2);
}

void puts(const char* string) {
	unsigned short i = 0;

	while(string[i] != '\0') {
		putchar(string[i]);
		i += 1;
 	}
}

void color(uint16_t color) {
	m.c = color;
}

void mgotoxy(uint16_t xy) { //<- Gotoxy xy
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t)(xy & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t)((xy >> 8) & 0xFF));
}

void sgotoxy(uint16_t x, uint16_t y) { //<- Gotoxy x,y
	mgotoxy(x+y*80);
}

void move(uint16_t x, uint16_t y) {
	m.p += (y*80+x*2);
	mgotoxy(m.p/2);
}

void setPosition(uint16_t x, uint16_t y) {
	m.p = (x*2+y*80);
	mgotoxy(m.p/2);
}

char getChar(uint16_t x, uint16_t y) {
	return(x*2+y*80);
}

uint16_t getColor(uint16_t x, uint16_t y) {
	return (x*2+y*80-1);
}

void setColor(uint16_t x, uint16_t y, uint16_t color) {
	vga_buffer[x*2+y*80-1] = color;
}

void setChar(uint16_t x, uint16_t y, char c) {
	vga_buffer[x*2+y*80] = c;
}

void newLine() {
	m.p+=((80*2)-(m.p%(80*2)));
	mgotoxy(m.p/2);
}

void fill_buffer(char c, uint16_t color) {
	for(uint16_t i = 0; i < screen_res*2; i+=2) {
		vga_buffer[i] = c;
		vga_buffer[i+1] = color;
	}
}

void* ttyProcedure(int procedure, void* data, uint32_t size, FILE* th) {
		switch(procedure) {
		case F_OPEN:
			return NULL;

		case F_CLOSE:
			th->data = 0;
			th->pr = 0;

			return 1;

		case F_READ:
			{
				char* p = *(char**)data;
				size_t size = *(size_t*)(data+4);
				size_t nitems = *(size_t*)(data+8);

				for(uint32_t i = 0; i < nitems*size; i+=size) {
					p[i] = _getch(def_keyboard, _SC_US, 1);
				}
			}
			return 1;

		case F_WRITE:
			{
				char* p = *(char**)data;
				size_t size = *(size_t*)(data+4);
				size_t nitems = *(size_t*)(data+8);

				for(uint32_t i = 0; i < nitems*size; i+=size) {
					putchar(p[i]);
				}
			}
			return 1;

		case F_SEEK:
			{
				int offset = *(int*)(data);
				int mode = *(int*)(data+4);

				switch(mode) {
				case SEEK_SET:
					setPosition(offset,0);
					break;	

				case SEEK_CUR:
					setPosition(m.p/2 + offset,0);
					break;

				case SEEK_END:
					setPosition(screen_res - offset,0);
				}
				

				return 1;
			}

		}
		
		return 0;
}
