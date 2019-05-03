CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
enable_language(ASM_NASM)

project(Aqua)

set(CMAKE_BINARY_DIR build)

include(kernel/CMakeLists.txt)
include(drivers/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_C_COMPILER}" "--print-file-name=crtbegin.o" OUTPUT_VARIABLE crtbegin RESULT_VARIABLE crtbegin_result)
message("crtbegin.o: ${crtbegin}")
execute_process(COMMAND "${CMAKE_C_COMPILER}" "--print-file-name=crtend.o" OUTPUT_VARIABLE crtend RESULT_VARIABLE crtend_result)
message("crtend.o: ${crtend}")

string(STRIP ${crtbegin} crtbegin)
string(STRIP ${crtend} crtend)

add_executable(aqua ${PLATFORM_SOURCE} ${ARCH_SOURCE} ${KERNEL_SOURCE} ${DRIVERS_SOURCE})
set_target_properties(aqua PROPERTIES LINK_FLAGS "-T ${PLATFORM_LAYOUT} -N ${ARCH_LINKER_FLAGS} ${PLATFORM_LINKER_FLAGS}")
target_link_libraries(aqua ${crtbegin} ${crtend})
target_compile_options(aqua PRIVATE -Wno-int-conversion -Wno-shift-count-overflow -Wno-implicit-function-declaration)
