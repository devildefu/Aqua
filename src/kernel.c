#include "Modules/vga.h"
#include "Modules/keyboard.h"
#include "Modules/string.h"
#include "Modules/time.h"


void kmain(void) {
	char str[10];
	getStringc(str,10,13);
	memset(str,'-',10);
	puts(str);
	return;
}
