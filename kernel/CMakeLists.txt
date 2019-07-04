CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
if("${CMAKE_ASM_COMPILER}" STREQUAL "nasm")
    enable_language(ASM_NASM)
else()
    enable_language(ASM-ATT)
endif()

include(../sdk/cmake/macros.cmake)

# Create config.h
generate_config_header()

# Informs where the headers are
include_directories("include")
include_directories("arch/${SYSTEM_ARCH}/include")
include_directories("arch/${SYSTEM_ARCH}/${SYSTEM_PLATFORM}/include")
include_directories("${CMAKE_SOURCE_DIR}")
include_directories("../sdk/c")

execute_process(COMMAND "${CMAKE_C_COMPILER}" "--print-file-name=crtbegin.o" OUTPUT_VARIABLE crtbegin RESULT_VARIABLE crtbegin_result)
execute_process(COMMAND "${CMAKE_C_COMPILER}" "--print-file-name=crtend.o" OUTPUT_VARIABLE crtend RESULT_VARIABLE crtend_result)

string(STRIP ${crtbegin} crtbegin)
string(STRIP ${crtend} crtend)

set(SOURCE  libssp/ssp.c
            memory/memory.c
            misc/file.c
            misc/random.c
            misc/stdlib.c
            misc/string.c
            misc/stdio.c
            kernel.c)

include("arch/${SYSTEM_ARCH}/settings.cmake")
include("arch/${SYSTEM_ARCH}/${SYSTEM_PLATFORM}/settings.cmake")

# How to compile asm code
set(CMAKE_ASM_COMPILE_OBJECT "<CMAKE_ASM_COMPILER> ${ARCH_ASM_FLAGS} ${PLATFORM_ASM_FLAGS} -o <OBJECT> <SOURCE>")

set(CMAKE_C_FLAGS "${ARCH_C_FLAGS} ${PLATFORM_C_FLAGS}")
set(PLATFORM_LAYOUT "${CMAKE_SOURCE_DIR}/kernel/arch/${SYSTEM_ARCH}/${SYSTEM_PLATFORM}/linker.ld")

add_executable(aqua ${WORKAROUND} ${SOURCE})

# Change linker and flags, so we can compile a kernel
set(CMAKE_C_LINK_EXECUTABLE "${LINKER} <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> ${crtbegin} <OBJECTS> ${crtend} -o <TARGET> <LINK_LIBRARIES>")
set_target_properties(aqua PROPERTIES LINK_FLAGS "-T ${PLATFORM_LAYOUT} ${ARCH_LINKER_FLAGS} ${PLATFORM_LINKER_FLAGS}")