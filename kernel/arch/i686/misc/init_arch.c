#include <misc/init_arch.h>

void init_arch() {
	gdt_init();
	idt_init();
	isrs_init();
	com_init(COM1_PORT);
}