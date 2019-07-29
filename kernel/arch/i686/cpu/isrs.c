#include <cpu/isrs.h>

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr30();

void isrs_init() {
	idt_set(0, (unsigned)isr0, 0x08, 0x8E);
	idt_set(1, (unsigned)isr1, 0x08, 0x8E);
	idt_set(2, (unsigned)isr2, 0x08, 0x8E);
	idt_set(3, (unsigned)isr3, 0x08, 0x8E);
	idt_set(4, (unsigned)isr4, 0x08, 0x8E);
	idt_set(5, (unsigned)isr5, 0x08, 0x8E);
	idt_set(6, (unsigned)isr6, 0x08, 0x8E);
	idt_set(7, (unsigned)isr7, 0x08, 0x8E);
	idt_set(8, (unsigned)isr8, 0x08, 0x8E);
	idt_set(10, (unsigned)isr10, 0x08, 0x8E);
	idt_set(11, (unsigned)isr11, 0x08, 0x8E);
	idt_set(12, (unsigned)isr12, 0x08, 0x8E);
	idt_set(13, (unsigned)isr13, 0x08, 0x8E);
	idt_set(14, (unsigned)isr14, 0x08, 0x8E);
	idt_set(16, (unsigned)isr16, 0x08, 0x8E);
	idt_set(17, (unsigned)isr17, 0x08, 0x8E);
	idt_set(18, (unsigned)isr18, 0x08, 0x8E);
	idt_set(19, (unsigned)isr19, 0x08, 0x8E);
	idt_set(20, (unsigned)isr20, 0x08, 0x8E);
	idt_set(30, (unsigned)isr30, 0x08, 0x8E);
}

/**
 * Manage any exception that has occurred.
 *
 * Exceptions list: https://wiki.osdev.org/Exceptions
 * @param id Exception Id
 * @param err_code Exception's error code, if the exception does not return an error code, it is 0
 */
void isr_handler(int id, uint32_t err_code) {
	ExceptionType exception_type;

	debugf("Exception Id: %i", id);

	/* Print exception type */
	switch(id) {
	case 2:
		debug("Exception Type: Interrupt");
		break;
	case 3:
	case 4:
		exception_type = Trap;
		debug("Exception Type: Trap");
		break;
	case 8:
	case 18:
		exception_type = Abort;
		debug("Exception Type: Abort");
		break;
	default:
		exception_type = Fault;
		debug("Exception Type: Fault");
		break;
	}

	/* Double Fault's (id: 8) error code is always 0 */
	/* TODO: add use of error code */
	if(err_code != 0 || id == 8) {
		switch(id) {
		case 8:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 17:
			break;
		case 30:
			break;
		}
	}

	if(exception_type == Abort) {
		abort();
	}
}