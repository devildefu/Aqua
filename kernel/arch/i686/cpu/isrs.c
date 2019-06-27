#include <cpu/isrs.h>

extern void isr0();

void isrs_init() {
    idt_set(0, (unsigned)isr0, 0x08, 0x8E);
}

void isr0_handler() {
    debug("Divide by zero!");
}

void isr1_handler() {

}

void isr2_handler() {

}

void isr3_handler() {

}

void isr4_handler() {

}

void isr5_handler() {

}

void isr6_handler() {

}

void isr7_handler() {

}

void isr8_handler() {

}

void isr10_handler() {

}

void isr11_handler() {

}

void isr12_handler() {

}

void isr13_handler() {

}

void isr14_handler() {

}

void isr16_handler() {

}

void isr17_handler() {

}

void isr18_handler() {

}

void isr19_handler() {

}

void isr20_handler() {

}

void isr30_handler() {

}