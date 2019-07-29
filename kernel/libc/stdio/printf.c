#include <debug/debug.h>
#include <definitions.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <video/tty.h>

/// Print string with fixed length
static bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*)data;
	for(size_t i = 0; i < length; i++)
		if(bytes[i] == '\0') {
			return false;
		} else {
			tty_putch(bytes[i]);
		}
	return true;
}

int printf(const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while(*format != '\0') {
		size_t max_rem = INT_MAX - written;

		if(format[0] != '%' || format[1] == '%') {
			if(format[0] == '%')
				format++;

			size_t amount = 1;
			while(format[amount] && format[amount] != '%')
				amount++;

			for(size_t i = 0; i < amount; i++) {
				tty_putch(format[i]);
			}

			format += amount;
			written += amount;
			continue;
		}

		format++;

		if(*format == 'c') {
			format++;
			unsigned int ch = va_arg(parameters, int);

			tty_putch(ch);
			written++;
		}

		if(*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);

			tty_write(str);
			written += strlen(str);
		}

		if(*format == 'i' || *format == 'd') {
			format++;
			int number = va_arg(parameters, int);
			char str[sizeof(int)];

			itoa(number, str);
			tty_write(str);
			written += strlen(str);
		}

		if(*format == 'x' || *format == 'X') {
			format++;
			int hex = va_arg(parameters, int);
			char str[sizeof(int)];

			htoa(hex, str);
			tty_write(str);
		}

		if(*format == 'o') {
			format++;
			int number = va_arg(parameters, int);

			long int decimal = 0;
			int i = 0;
			while(number != 0) {
				decimal += (number % 10) * pow(8, i++);
				number /= 10;
			}

			char str[sizeof(int)];

			itoa(decimal, str);
			tty_write(str);
			written += strlen(str);
		}
	}

	va_end(parameters);
	return written;
}