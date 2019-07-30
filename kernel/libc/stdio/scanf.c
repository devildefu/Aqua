#include <devices/keyboard.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <video/tty.h>

int scanf(const char* format, ...) {
	int done;
	va_list parameters;
	va_start(parameters, format);

	while(*format) {
		if(*format++ == '%') {
			if(*format == 's') {
				int i = 0, output = 0;
				char ch;
				char* buffer[512];

				while((ch = getch()) != '\n' && ch != '\ ') {
					tty_putch(ch);
					buffer[i++] = ch;
				}

				if(ch == '\n') {
					tty_putch('\n');
				}

				if(i == 0) {
					break;
				}

				//atoi(buffer, output);
				printf("%s\n", buffer);
				printf("%d\n", output);

				done++;
			} else {
				break;
			}
		}
	}

	va_end(parameters);
	return done;
}