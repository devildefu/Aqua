#include "config.h"

#include <kernel/include/tty.h>
#include <kernel/include/keyboard.h>
#include <kernel/include/string.h>
#include <kernel/include/arg.h>
#include <kernel/include/cpu.h>

#include <drivers/ps2/ps2.h>
#include <drivers/cmos/cmos.h>
#include <drivers/pci/pci.h>

void kmain(void* lkc) {
	init_ps2();
	init_keyboard();

    clear();
    color(12);

    init_pci();
    lspci();
}
