#include "config.h"

#include <core/include/tty.h>
#include <core/include/keyboard.h>
#include <core/include/string.h>
#include <core/include/cpu.h>

#include <drivers/ps2/ps2.h>
#include <drivers/pci/pci.h>

CPU_INFO* cpuinfo;

void kmain(void* lkc) {
    init_ps2();
    init_keyboard();
    init_pci();
    CPUInfo(cpuinfo);

    clear();
    color(12);

    /*
    printf("----------- CPU INFO ---------\n");
    CPUInfoPrint(cpuinfo);
    printf("----------- PCI INFO ---------\n");
    lspci();
    */
    puts("Hello");

    return;
}
