#include <multiboot/multiboot.h>

#define NULL 0

void lmain(const void* multiboot_struct) {
    // GDT here

    const multiboot_info_t* mb_info = multiboot_struct;
    multiboot_uint32_t mb_flags = mb_info->flags;

    void* kentry = NULL;

    if (mb_flags & MULTIBOOT_INFO_MODS) {
        
    }
}