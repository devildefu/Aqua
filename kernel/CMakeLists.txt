CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
enable_language(ASM_NASM)

include(../sdk/cmake/macros.cmake)

# Create config.h
generate_config_header()

# Informs where the headers are
include_directories("include")
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("../sdk/c")

include("arch/${SYSTEM_ARCH}/flags.cmake")
include("arch/${SYSTEM_ARCH}/${SYSTEM_PLATFORM}/flags.cmake")

# How to compile asm code
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> ${ARCH_ASM_FLAGS} ${PLATFORM_ASM_FLAGS} -o <OBJECT> <SOURCE>")

set(CMAKE_C_FLAGS "${ARCH_C_FLAGS} ${PLATFORM_C_FLAGS}")
set(PLATFORM_LAYOUT "${CMAKE_SOURCE_DIR}/kernel/arch/${SYSTEM_ARCH}/${SYSTEM_PLATFORM}/linker.ld")

add_executable(aqua arch/${SYSTEM_ARCH}/${SYSTEM_PLATFORM}/boot.asm
                    cpu/cpu.c
                    devices/serial/serial.c
                    libssp/ssp.c
                    memory/memory.c
                    misc/file.c
                    misc/random.c
                    misc/registers.asm
                    misc/setjmp.c
                    misc/stdlib.c
                    misc/string.c
                    video/tty.c
                    kernel.c)

# Change linker and flags, so we can compile a kernel
set(CMAKE_C_LINK_EXECUTABLE "${LINKER} <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
set_target_properties(aqua PROPERTIES LINK_FLAGS "-T ${PLATFORM_LAYOUT} -N ${ARCH_LINKER_FLAGS} ${PLATFORM_LINKER_FLAGS}")