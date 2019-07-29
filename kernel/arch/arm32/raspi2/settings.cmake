set(PLATFORM_LINKER_FLAGS "")
set(PLATFORM_C_FLAGS "")
set(PLATFORM_ASM_FLAGS "")

list(APPEND SOURCE arch/arm32/raspi2/boot.s
                   arch/arm32/raspi2/kernel.c)