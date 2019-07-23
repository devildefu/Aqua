#include <cpu/isrs.h>

extern void isr0();

void isrs_init() {
	idt_set(0, (unsigned)isr0, 0x08, 0x8E);
}

void isr_handler(int type) {
	switch(type) {
		/* These can be corrected and the program may continue as if nothing happened. */
		case Fault: 
			debug("Exception Type: Fault"); 
			break;
		/* Traps are reported immediately after the execution of the trapping instruction. */
		case Trap: 
			debug("Exception Type: Trap"); 
			break;
		/* Some severe unrecoverable error. */
		case Abort: 
			debug("Exception Type: Abort");
			abort();
			break;
		default: 
			debug("Exception Type: Unknown"); 
			break;
	}
}