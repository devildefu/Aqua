set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# Config only for the given architecture
set(SYSTEM_ARCH "arm32")
set(SYSTEM_PLATFORM "raspi2")

# Empty flags variables
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_C_FLAGS "")

# Force compilers
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc CACHE STRING "")
set(CMAKE_C_COMPILER arm-none-eabi-gcc CACHE STRING "")
set(LINKER arm-none-eabi-gcc CACHE STRING "")

# Inform the cmake that everything is all right.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)