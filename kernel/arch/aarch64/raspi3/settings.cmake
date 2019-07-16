set(PLATFORM_LINKER_FLAGS "")
set(PLATFORM_C_FLAGS "")
set(PLATFORM_ASM_FLAGS "")

include_directories("arch/arm32/include")

list(APPEND SOURCE arch/aarch64/raspi3/boot.s)