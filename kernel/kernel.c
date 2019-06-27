#include "config.h"

#include <stdint.h>
#include <video/tty.h>
#include <video/colors.h>
#include <multiboot/multiboot.h>
#include <devices/serial.h>
#include <cpu/gdt.h>
#include <cpu/idt.h>
#include <cpu/isrs.h>
#include <stdio.h>

#include <debug/debug.h>

#define CHECK_FLAG(flags,bit) ((flags) & (1 << (bit)))

void kmain(unsigned long magic, unsigned long multiboot_pointer) {
    /* Initialize */
    gdt_init();
    idt_init();
    isrs_init();

    tty_clear();
    tty_cursor_set_color(7);

    /* Initialize devices */
    com_init(COM1_PORT);

    printf("Aqua %s version %s\n", SYSTEM_ARCH, SYSTEM_VERSION);
    
    /* Get multiboot information structure */
    const multiboot_info_t* mb_info = (multiboot_info_t*)multiboot_pointer;

    /* Is the bootloader compatible with multiboot? */
    if(magic == MULTIBOOT_BOOTLOADER_MAGIC) {
        debug("Kernel booted by a bootloader compatible with multiboot!");

        if(CHECK_FLAG(mb_info->flags, 0)) {
            printf("mem_lower: %i\n", mb_info->mem_lower);
            printf("mem_upper: %i\n", mb_info->mem_upper);
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

    return;
}