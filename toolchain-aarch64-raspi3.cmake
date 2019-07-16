set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# Config only for the given architecture
set(SYSTEM_ARCH "aarch64")
set(SYSTEM_PLATFORM "raspi3")

# Empty flags variables
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_C_FLAGS "")

# Force compilers
set(CMAKE_ASM_COMPILER aarch64-elf-as CACHE STRING "")
set(CMAKE_C_COMPILER aarch64-elf-gcc CACHE STRING "")
set(CMAKE_LINKER aarch64-elf-gcc CACHE STRING "")

# Inform the cmake that everything is all right.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)