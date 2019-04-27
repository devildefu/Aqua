#include "config.h"

#include <kernel/include/tty.h>
#include <kernel/include/string.h>
#include <kernel/include/cpu.h>
#include <kernel/include/devices/serial.h>

void kmain(void* lkc) {
    clear();
    color(7);
    puts(SYSTEM_VERSION);
    return;
}
