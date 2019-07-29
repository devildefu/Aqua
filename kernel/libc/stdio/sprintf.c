#include <stdio.h>

int sprintf (char * str, const char * format, ...) {
	int done;

	va_list parameters;
	va_start(parameters, format);

	done = vsprintf(str, format, parameters);

	va_end(parameters);
	return done;
}