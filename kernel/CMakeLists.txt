set(kernel_source "${CMAKE_SOURCE_DIR}/kernel")

# set_arch() function
# first argument - architecture (i686, x86_64, aarch64, itd.)
# second argument - platform (pc, itd.)
function(set_arch arch platform)
  file(GLOB ARCH_SOURCE "${kernel_source}/arch/${arch}/*.c" "${kernel_source}/arch/${arch}/*.asm")
  file(GLOB PLATFORM_SOURCE "${kernel_source}/arch/${arch}/${platform}/*.c" "${kernel_source}/arch/${arch}/${platform}/*.asm")
  
  include("${kernel_source}/arch/${arch}/flags.cmake")
  include("${kernel_source}/arch/${arch}/${platform}/flags.cmake")

  set(ARCH_SOURCE ${ARCH_SOURCE} PARENT_SCOPE)
  set(PLATFORM_SOURCE ${PLATFORM_SOURCE} PARENT_SCOPE)
  set(PLATFORM_LAYOUT "${kernel_source}/arch/${arch}/${platform}/linker.ld" PARENT_SCOPE)

  set(ARCH_C_FLAGS ${ARCH_C_FLAGS} PARENT_SCOPE)
  set(ARCH_ASM_FLAGS ${ARCH_ASM_FLAGS} PARENT_SCOPE)
endfunction(set_arch)

# Add all files *.c and *.asm to KERNEL_SOURCE from kernel source code
file(GLOB_RECURSE KERNEL_SOURCE "${kernel_source}/*.c" "${kernel_source}/*.asm")

include_directories("${CMAKE_SOURCE_DIR}")
# Set architecture
set_arch("i686" "pc")

# How to compile asm code
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> ${ARCH_ASM_FLAGS} ${PLATFORM_ASM_FLAGS} -o <OBJECT> <SOURCE>")

# C Flags
set(CMAKE_C_FLAGS "${ARCH_C_FLAGS} ${PLATFORM_C_FLAGS}")