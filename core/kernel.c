#include "config.h"

#include <core/include/tty.h>
#include <core/include/keyboard.h>
#include <core/include/string.h>
#include <core/include/cpu.h>

#include <drivers/ps2/ps2.h>
#include <drivers/pci/pci.h>
#include <drivers/com/com.h>
#include <drivers/gfx/bga/bga.h>

void kmain(void* lkc) {
    CPU_INFO* cpuinfo;

    clear();
    color(12);
    
    puts("Hello");
    return;
}
