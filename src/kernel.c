#include "Modules/vga.h"
#include "Modules/keyboard.h"
#include "Modules/time.h"

void kmain(void) {
	clear();
	color(0x07);
	puts("Hello!");
	color(0x37);
	puts("BFUBUBUIbuif");
	return;
}
