set(ARCH_LINKER_FLAGS "-ffreestanding -O2 -nostdlib -lgcc")
set(ARCH_C_FLAGS "-m64 -ffreestanding -z max-page-size=0x1000 -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -std=gnu11 -O2 -nostdlib")
set(ARCH_ASM_FLAGS "-felf64")