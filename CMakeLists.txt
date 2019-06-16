CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
enable_language(ASM_NASM)
project(Aqua)

# Check that all the programs needed exists
find_program(NASM_EXISTS "nasm")
if(NOT NASM_EXISTS)
    message("-- NASM not found!")
endif()

if("${LINKER}" STREQUAL "")
    message(FATAL_ERROR "-- LINKER is empty!")
endif()

if(NOT "${CROSS_PATH}" STREQUAL "")
    set(LINKER "${CROSS_PATH}/${LINKER}")
    set(CMAKE_C_COMPILER "${CROSS_PATH}/${CMAKE_C_COMPILER}")
endif()

add_subdirectory(kernel)