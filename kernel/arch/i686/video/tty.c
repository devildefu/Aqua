#include <video/tty.h>

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

void set_position(uint16_t x, uint16_t y) {
	m.p = (x*2+y*80);
	mgotoxy(m.p/2);
}

char get_char(uint16_t x, uint16_t y) {
	return(x*2+y*80);
}

uint16_t get_color(uint16_t x, uint16_t y) {
	return (x*2+y*80-1);
}

void set_color(uint16_t x, uint16_t y, uint16_t color) {
	vga_buffer[x*2+y*80-1] = color;
}

void set_char(uint16_t x, uint16_t y, char c) {
	vga_buffer[x*2+y*80] = c;
}

void new_line() {
	m.p+=((80*2)-(m.p%(80*2)));
	mgotoxy(m.p/2);
}

void fill_buffer(char c, uint16_t color) {
	for(uint16_t i = 0; i < SCREEN_RES*2; i+=2) {
		vga_buffer[i] = c;
		vga_buffer[i+1] = color;
	}
}

static bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (bytes[i] == "\0") {
			return false;
        } else {
            putchar(bytes[i]);
        }
	return true;
}

int printf(const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);
 
	int written = 0;
 
	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;
 
		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}
 
		const char* format_begun_at = format++;
 
		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
        } else if (*format == 'i') {
			format++;
			int numstr = va_arg(parameters, int);
            char str[sizeof(int)];
            itoa(numstr, str);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}
 
	va_end(parameters);
	return written;
}