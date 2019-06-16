CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
enable_language(ASM_NASM)
project(Aqua)

# Check that all the programs needed exists
find_program(NASM_EXISTS "nasm")
if(NOT NASM_EXISTS)
    message("NASM not found!")
endif()

add_subdirectory(kernel)