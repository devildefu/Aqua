#include "config.h"

#include <kernel/include/video/tty.h>
#include <kernel/include/video/colors.h>
#include <kernel/include/string.h>
#include <kernel/include/cpu.h>
#include <kernel/include/devices/serial.h>

void kmain(void* lkc) {
    clear();
    puts(SYSTEM_VERSION);
    return;
}
