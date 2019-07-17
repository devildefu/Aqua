#include <stdint.h>
#include <stdlib.h>
#ifdef __i386__
	#include <devices/serial.h>
#endif
#include <debug/debug.h>

#if UINT32_MAX == UINTPTR_MAX
#define STACK_CHK_GUARD 0xE2DEE396
#else
#define STACK_CHK_GUARD 0x595E9FBD94FDA766
#endif

uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void) {
	fail("Stack smashing detected! Terminated.");
}

/* This function is only for compiling kernel without cross-compiler. */
void __stack_chk_fail_local(void) {
	
}

void __chk_fail(void) {
	fail("Buffer overflow detected! Terminated.");
}
