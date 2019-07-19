#include <devices/serial.h>

void com_init(uint16_t port) {
	outb(port + 1, 0x00);
	outb(port + 3, 0x80);
	outb(port + 0, 0x03);
	outb(port + 1, 0x00);
	outb(port + 3, 0x03);
	outb(port + 2, 0xC7);
	outb(port + 4, 0x0B);
}

int com_received(uint16_t port) {
	return inb(port + 5) & 1;
}

char com_read(uint16_t port) {
	while(com_received(port) == 0)
		;
	return inb(port);
}

int com_is_transmit_empty(uint16_t port) {
	return inb(port + 5) & 0x20;
}

void com_putchar(uint16_t port, char letter) {
	while(com_is_transmit_empty(port) == 0)
		;
	outb(port, letter);
}

void com_print(uint16_t port, char* string) {
	for(size_t i = 0; i < strlen(string); i++) {
		com_putchar(port, string[i]);
	}
}

static bool com_print2(uint16_t port, const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*)data;
	for(size_t i = 0; i < length; i++)
		if(bytes[i] == '\0') {
			return false;
		} else {
			com_putchar(port, bytes[i]);
		}
	return true;
}

int com_printf(uint16_t port, const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while(*format != '\0') {
		size_t maxrem = INT_MAX - written;

		if(format[0] != '%' || format[1] == '%') {
			if(format[0] == '%')
				format++;
			size_t amount = 1;
			while(format[amount] && format[amount] != '%')
				amount++;
			if(maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if(!com_print2(port, format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		const char* format_begun_at = format++;

		if(*format == 'c') {
			format++;
			char c = (char)va_arg(parameters, int /* char promotes to int */);
			if(!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if(!com_print2(port, &c, sizeof(c)))
				return -1;
			written++;
		} else if(*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if(!com_print2(port, str, len))
				return -1;
			written += len;
		} else if(*format == 'i') {
			format++;
			int numstr = va_arg(parameters, int);
			char str[sizeof(int)];
			itoa(numstr, str);
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if(!com_print2(port, str, len))
				return -1;
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if(!com_print2(port, format, len))
				return -1;
			written += len;
			format += len;
		}
	}

	va_end(parameters);
	return written;
}