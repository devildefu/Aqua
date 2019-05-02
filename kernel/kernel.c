#include "config.h"

#include <kernel/include/video/tty.h>
#include <kernel/include/video/colors.h>
#include <kernel/include/string.h>
#include <kernel/include/cpu.h>
#include <kernel/include/devices/serial.h>
#include <kernel/include/stdlib.h>

void kmain(unsigned long magic, const void* multiboot_pointer) {
    clear();
    color(7);

    char abc[10];
    abc[10] = 'a';
    printf("aaaaa\n");
    return;
}
