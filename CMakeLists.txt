CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
enable_language(ASM_NASM)

project(Kirid)

set(CMAKE_BINARY_DIR build)

include(kernel/CMakeLists.txt)
include(drivers/CMakeLists.txt)

add_executable(kirid ${PLATFORM_SOURCE} ${ARCH_SOURCE} ${KERNEL_SOURCE} ${DRIVERS_SOURCE})
set_target_properties(kirid PROPERTIES LINK_FLAGS "-T ${PLATFORM_LAYOUT} -N ${ARCH_LINKER_FLAGS} ${PLATFORM_LINKER_FLAGS}")
