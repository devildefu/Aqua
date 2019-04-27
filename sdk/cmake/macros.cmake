# set_arch() function
# first argument - architecture (i686, x86_64, aarch64, etc.)
# second argument - platform (pc, etc.)
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

function(generate_config_header)
    include(sdk/cmake/config.cmake)
    configure_file(kernel/config.h.in ${CMAKE_SOURCE_DIR}/kernel/config.h @ONLY)
endfunction(generate_config_header)