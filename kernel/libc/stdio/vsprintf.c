#include <debug/debug.h>
#include <definitions.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <video/tty.h>

void add_char(char src, char* dst) {
	size_t len = strlen(dst);
	dst[len] = src;
	dst[len+1] = '\0';
}

void add_string(char* src, char* dst) {
	for (size_t i = 0; i < strlen(src); i++) {
		add_char(src[i], dst);
	}
}

int vsprintf(char * s, const char * format, va_list arg) {
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
				add_char(format[i], s);
			}

			format += amount;
			written += amount;
			continue;
		}

		format++;

		if(*format == 'c') {
			format++;
			unsigned int ch = va_arg(arg, int);

			add_char(ch, s);
			written++;
		}

		if(*format == 's') {
			format++;
			const char* str = va_arg(arg, const char*);

			add_string(str, s);
			written += strlen(str);
		}

		if(*format == 'i' || *format == 'd') {
			format++;
			int number = va_arg(arg, int);
			char str[sizeof(int)];

			itoa(number, str);
			add_string(str, s);
			written += strlen(str);
		}

		if(*format == 'x' || *format == 'X') {
			format++;
			int hex = va_arg(arg, int);
			char str[sizeof(int)];

			htoa(hex, str);
			add_string(str, s);
		}

		if(*format == 'o') {
			format++;
			int number = va_arg(arg, int);

			long int decimal = 0;
			int i = 0;
			while(number != 0) {
				decimal += (number % 10) * pow(8, i++);
				number /= 10;
			}

			char str[sizeof(int)];

			itoa(decimal, str);
			add_string(str, s);
			written += strlen(str);
		}
	}
	return written;
}