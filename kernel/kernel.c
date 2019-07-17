#include "config.h"

#include <stdint.h>
#include <stdbool.h>
#include <video/tty.h>
#include <video/colors.h>
#include <multiboot/multiboot.h>
#include <devices/keyboard.h>
#include "stdio.h"
#include <misc/init_arch.h>
#include <cpu/cpu.h>

#include <debug/debug.h>

#define CHECK_FLAG(flags,bit) ((flags) & (1 << (bit)))

char line[100];//for debug

void print_splash_screen(){
	for(int i=0; i<80; i++){
		printf("=");
	}
	for(int i=0; i<26; i++){
		printf(" ");
	}
	printf("Aqua initialized successfully.\n");
	printf("\n");
}


void kmain(unsigned long magic, unsigned long multiboot_pointer) {
	/* Initialize */
	init_arch();

	mman_init();//Init memory management

	tty_clear();
	tty_cursor_set_color(7);

	printf("Aqua %s version %s\n\n", SYSTEM_ARCH, SYSTEM_VERSION);

	/* Get multiboot information structure */
	const multiboot_info_t* mb_info = (multiboot_info_t*)multiboot_pointer;

	/* Is the bootloader compatible with multiboot? */
	if(magic == MULTIBOOT_BOOTLOADER_MAGIC) {
		debug("Kernel booted by a bootloader compatible with multiboot!");

		printf("Multiboot info:\n");
		if(CHECK_FLAG(mb_info->flags, 0)) {
			indent(1);printf("Lower memory: 0 - %i KiB\n", mb_info->mem_lower);
			/* "The value returned for upper memory is maximally the address of the first upper memory hole minus 1 megabyte." and we need to add 128, I don't know why */
			indent(1);printf("Upper memory: %i KiB - %i KiB\n", mb_info->mem_lower, mb_info->mem_upper);
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

		if(CHECK_FLAG(mb_info->flags, 9)) {
			indent(1);printf("Used bootloader: %s\n", mb_info->boot_loader_name);
		}

		/* maybe it'll work someday... maybe */
		if(CHECK_FLAG(mb_info->flags, 12)) {
			printf("%i", mb_info->framebuffer_height);
		}
	}

	print_splash_screen();

	/* Keyboard testing */
	while(true) {
		tty_putch(getch());
	}

	return;
}
