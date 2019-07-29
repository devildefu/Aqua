set(ARCH_LINKER_FLAGS "-O0 -nostdlib -ffreestanding -lgcc")
set(ARCH_C_FLAGS "-std=gnu11 -ffreestanding -c")
set(ARCH_ASM_FLAGS "-c")

list(APPEND SOURCE arch/arm32/devices/uart.c
                   arch/arm32/video/tty.c)