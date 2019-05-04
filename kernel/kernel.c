#include "config.h"

#include <video/tty.h>
#include <video/colors.h>
#include <multiboot/multiboot.h>
#include <devices/serial.h>

#include <debug/debug.h>

#define CHECK_FLAG(flags,bit) ((flags) & (1 << (bit)))

void kmain(unsigned long magic, unsigned long multiboot_pointer) {
    clear();
    color(7);

    /* Initialize devices */
    com_init(COM1_PORT);

    printf("Aqua %s version %s\n\n", SYSTEM_ARCH, SYSTEM_VERSION);

    /* Get multiboot information structure */
    const multiboot_info_t* mb_info = (multiboot_info_t*)multiboot_pointer;

    /* Is the bootloader compatible with multiboot? */
    if(magic == MULTIBOOT_BOOTLOADER_MAGIC) {
        debug("Kernel booted by a bootloader compatible with multiboot!");
        
        if(CHECK_FLAG(mb_info->flags, 3)) {
            if(mb_info->mods_count > 0) {
                debug("RamDisk found!");

                /* Get ramdisk structure */
                multiboot_module_t* mod;
                mod = (multiboot_module_t*)mb_info->mods_addr;
            }
        }
    }

    return;
}
