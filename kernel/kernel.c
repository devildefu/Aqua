#include "config.h"

#include <stdint.h>
#include <video/tty.h>
#include <video/colors.h>
#include <multiboot/multiboot.h>
#include <devices/keyboard.h>
#include <libk/stdio.h>
#include <misc/init_arch.h>

#include <debug/debug.h>

#define CHECK_FLAG(flags,bit) ((flags) & (1 << (bit)))

void kmain(unsigned long magic, unsigned long multiboot_pointer) {
    /* Initialize */
    init_arch();

    tty_clear();
    tty_cursor_set_color(7);

    printf("Aqua %s version %s\n", SYSTEM_ARCH, SYSTEM_VERSION);
    printf("(%s:%i)\n", __FILE__, __LINE__);

    /* Get multiboot information structure */
    const multiboot_info_t* mb_info = (multiboot_info_t*)multiboot_pointer;

    /* Is the bootloader compatible with multiboot? */
    if(magic == MULTIBOOT_BOOTLOADER_MAGIC) {
        debug("Kernel booted by a bootloader compatible with multiboot!");

        if(CHECK_FLAG(mb_info->flags, 0)) {
            printf("mem_lower: %i\n", mb_info->mem_lower);
            /* "The value returned for upper memory is maximally the address of the first upper memory hole minus 1 megabyte." and we need to add 128, I don't know why */
            printf("mem_upper: %i in megabytes: %i\n", mb_info->mem_upper, (mb_info->mem_upper+1024+128)/1024);
        }

        /* Has ramdisk been loaded? */
        if(CHECK_FLAG(mb_info->flags, 3)) {
            if(mb_info->mods_count > 0) {
                debug("RamDisk found!");

                /* Get ramdisk structure */
                multiboot_module_t* mod;
                mod = (multiboot_module_t*)mb_info->mods_addr;
            }
        }

        /* maybe it'll work someday... maybe */
        if(CHECK_FLAG(mb_info->flags, 12)) {
            printf("%i", mb_info->framebuffer_height);
        }
    }

    int dog = 10 / 0;
    debug("Divide-by-zero ISR works!\n");

    /* Keyboard testing */
    while(true) {
	    tty_putch(getch());
    }

    return;
}
