#include "setjmp.h"

int setjmp(_jmp_buf* buf) {
    return throw_regs(buf);
}

void longjmp(_jmp_buf* buf, int signal) {
    buf->eax = signal;
    set_regs(buf);
}