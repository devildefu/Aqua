#include "config.h"

#include <display/tty.h>
#include <processor/setjmp.h>

uint64_t rdtsc() {
	uint64_t ret;
	asm volatile("rdtsc" : "=A"(ret));
	return ret;
}

void kmain(void) {
	clear();
	color(6);

	jmp_buf b;

	if(!setjmp(b)) {
		puts("abc");
	}

	puts("dce");

	longjmp(b,1);

	while(1);
}
