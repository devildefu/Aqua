#include <core/include/int.h>

void DisableInt() {
    asm("cli");
}

void EnableInt() {
    asm("sti");
}
