#include "config.h"

#include <video/tty.h>
#include <video/colors.h>
#include <multiboot/multiboot.h>

void kmain(unsigned long magic, const void* multiboot_pointer) {
    clear();
    color(7);
    printf("Aqua %s version %s", SYSTEM_ARCH, SYSTEM_VERSION);
    return;
}
