#include "config.h"

#include <kernel/display/tty.h>
#include <kernel/processor/setjmp.h>
#include <kernel/memory/memory.h>
#include <kernel/files/file.h>
#include <kernel/input/keyboard.h>

#include <kernel/string/string.h>

#include <drivers/PS2/ps2.h>

#include <kernel/args/arg.h>

void kmain(void* lkc) {
	init_ps2();
	init_keyboard();

    clear();
    color(12);

    while(1) {
		putchar(getch());
	}
}