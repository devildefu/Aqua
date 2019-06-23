set(ARCH_LINKER_FLAGS "-m elf_i386 -O0 -nostdlib")
set(ARCH_C_FLAGS "-std=gnu11 -ffreestanding -m32 -fno-builtin -nostdlib -fstack-protector")
set(ARCH_ASM_FLAGS "-felf32")

list(APPEND SOURCE  arch/i686/pc/boot.asm
                    arch/i686/cpu/cpu.c
                    arch/i686/cpu/gdt.asm
                    arch/i686/cpu/gdt.c
                    arch/i686/cpu/idt.c
                    arch/i686/cpu/idt.asm
                    arch/i686/devices/serial/serial.c
                    arch/i686/misc/registers.asm
                    arch/i686/video/tty.c)