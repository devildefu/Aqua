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
	
    init_ps2();
    init_keyboard();
    init_pci();
    COM_init(COM1_PORT);
    cpu_info(cpuinfo);

    clear();
    color(12);

    
    puts("Hello");
    return;
}
