#include "Modules/vga.h"
#include "Modules/keyboard.h"
#include "Modules/string.h"
#include "Modules/time.h"

void kmain(void) {
	initTimer();
	
	clear();
	char str[10];
	
	d2s(rdtsc(),str,10,'.');
	puts("rdtsc: ");
	puts(str);
	
	d2s(clock(),str,10,'.');
	puts("  || clock: ");
	puts(str);
	return;
}
