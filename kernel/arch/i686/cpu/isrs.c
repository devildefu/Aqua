#include <cpu/isrs.h>

extern void isr0();

void isrs_init() {
	idt_set(0, (unsigned)isr0, 0x08, 0x8E);
}

void isr_handler() {
	debug("ISR Handler called!");
	//debug("Divide by zero!");
}