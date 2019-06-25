set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# Config only for the given architecture
set(SYSTEM_ARCH "x86_64")
set(SYSTEM_PLATFORM "pc")

# Empty flags variables
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

# Force compilers
set(CMAKE_ASM_COMPILER nasm CACHE STRING "")
set(CMAKE_C_COMPILER amd64-elf-gcc CACHE STRING "")
set(LINKER amd64-elf-ld CACHE STRING "")

# Inform the cmake that everything is all right.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)