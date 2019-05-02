#include <kernel/include/definitions.h>
#include <kernel/include/stdlib.h>
#include <kernel/include/devices/serial.h>

#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0xE2DEE396
#else
#define STACK_CHK_GUARD 0x595E9FBD94FDA766
#endif

uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void fail(const char* msg) {
    color(0x0C);
    printf(msg);
    // TODO: Don't use color(0x07)! Instead: color(old_color)
    color(0x07);

    abort();
}

void __stack_chk_fail(void) {
    fail("Stack smashing detected! Terminated.");
}

void __chk_fail(void) {
    fail("Buffer overflow detected! Terminated.");
    
}
