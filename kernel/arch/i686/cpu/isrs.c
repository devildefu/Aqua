#include <cpu/isrs.h>

extern void isr0();

void isrs_init() {
    idt_set(0, (unsigned)isr0, 0x08, 0x8E);
}

void isr0_handler() {
    outb(0x20, 0x20);

    debug("Divide by zero!");
}