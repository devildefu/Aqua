set(ARCH_LINKER_FLAGS "-O0 -nostdlib -lgcc -ffreestanding")
set(ARCH_C_FLAGS "-std=gnu11 -ffreestanding -mcpu=cortex-a7 -fpic -c")
set(ARCH_ASM_FLAGS "-mcpu=cortex-a7 -fpic -ffreestanding -c")

list(APPEND SOURCE arch/arm32/devices/uart.c
                   arch/arm32/video/tty.c)