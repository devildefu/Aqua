set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# Config only for the given architecture
set(SYSTEM_ARCH "i686")
set(SYSTEM_PLATFORM "pc")

# Empty flags variables
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_C_FLAGS "")

# Force compilers
set(CMAKE_ASM_COMPILER nasm CACHE STRING "")
#set(CMAKE_ASM_NASM_COMPILER nasm CACHE STRING "")
set(CMAKE_C_COMPILER i686-elf-gcc CACHE STRING "")
set(CMAKE_LINKER i686-elf-gcc CACHE STRING "") # I don't know why, but if we set up CMAKE_LINKER, it's empty...

# Inform the cmake that everything is all right.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1) # Funny, because we don't use i686-elf-c++ but CMake still checks it out...
