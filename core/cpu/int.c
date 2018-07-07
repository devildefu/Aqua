#include <core/include/int.h>

void disable_int() {
    asm("cli");
}

void enable_int() {
    asm("sti");
}
