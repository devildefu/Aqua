#include "Modules/vga.h"
#include "Modules/keyboard.h"

void kmain(void) {
	clear();
	char key = getScancode()+1;
	putchar(key, 2);
	return;
}
