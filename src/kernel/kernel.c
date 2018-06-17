#include "config.h"

#include <kernel/include/tty.h>
#include <kernel/include/keyboard.h>
#include <kernel/include/string.h>
#include <kernel/include/arg.h>

#include <drivers/ps2/ps2.h>
#include <drivers/cmos/cmos.h>

void kmain(void* lkc) {
	  init_ps2();
	  init_keyboard();

    clear();
    color(12);
}
