#include <stdlib.h>

__attribute__((noreturn))
void abort(void) {
	while(1) { }
	__builtin_unreachable();
}