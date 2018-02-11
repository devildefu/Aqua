#include "../Include/interrupts.h"

void disable_int() {
    asm("cli");
}

void enable_int() {
    asm("sli");
}