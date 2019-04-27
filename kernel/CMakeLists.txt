set(kernel_source "${CMAKE_SOURCE_DIR}/kernel")

include(sdk/cmake/macros.cmake)

generate_config_header()

# Add all files *.c and *.asm to KERNEL_SOURCE from kernel source code
file(GLOB_RECURSE KERNEL_SOURCE "${kernel_source}/*.c" "${kernel_source}/*.asm")

include_directories("${CMAKE_SOURCE_DIR}")
# Set architecture
set_arch("i686" "pc")

# How to compile asm code
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> ${ARCH_ASM_FLAGS} ${PLATFORM_ASM_FLAGS} -o <OBJECT> <SOURCE>")

# C Flags
set(CMAKE_C_FLAGS "${ARCH_C_FLAGS} ${PLATFORM_C_FLAGS}")