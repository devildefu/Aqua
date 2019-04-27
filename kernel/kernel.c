#include "config.h"

#include <kernel/include/tty.h>
#include <kernel/include/keyboard.h>
#include <kernel/include/string.h>
#include <kernel/include/cpu.h>
#include <kernel/include/devices/serial.h>

#include <drivers/ps2/ps2.h>
#include <drivers/pci/pci.h>

void kmain(void* lkc) {
    CPU_INFO* cpuinfo;

    clear();
    color(12);
    
    puts("Hello");
    return;
}
