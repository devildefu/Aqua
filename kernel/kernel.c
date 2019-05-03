#include "config.h"

#include <video/tty.h>
#include <video/colors.h>
#include <multiboot/multiboot.h>
#include <devices/serial.h>

#include <debug/debug.h>

void kmain(unsigned long magic, const void* multiboot_pointer) {
    clear();
    color(7);

    /* Initialize devices */
    com_init(COM1_PORT);

    printf("Aqua %s version %s", SYSTEM_ARCH, SYSTEM_VERSION);
    debug("aaa");
    return;
}
