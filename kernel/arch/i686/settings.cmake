set(ARCH_LINKER_FLAGS "-g -ffreestanding -O0 -nostdlib -lgcc")
set(ARCH_C_FLAGS "-g -std=gnu11 -ffreestanding -fstack-protector")
set(ARCH_ASM_FLAGS "-felf32")

#list(REVERSE SOURCE)
set(WORKAROUND arch/i686/crti.asm)

list(APPEND SOURCE  arch/i686/pc/boot.asm
                    arch/i686/cpu/cpu.c
                    arch/i686/cpu/gdt.asm
                    arch/i686/cpu/gdt.c
                    arch/i686/cpu/idt.c
                    arch/i686/cpu/idt.asm
                    arch/i686/cpu/isrs.asm
                    arch/i686/cpu/isrs.c
                    arch/i686/devices/serial/serial.c
                    arch/i686/misc/registers.asm
                    arch/i686/video/tty.c
                    arch/i686/devices/ps2/keyboard/keyboard.c
                    arch/i686/misc/init_arch.c
                    arch/i686/crtn.asm)
