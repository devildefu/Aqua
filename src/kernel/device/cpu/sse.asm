check_SSE:
  mov eax, 0x1
  cpuid
  test edx, 1<<25
  jz .noSSE
  ; SSE is available

  .noSSE:
  ; I'll add something later
