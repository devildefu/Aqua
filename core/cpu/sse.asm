global SSE_Check:function

SSE_Check:
  mov eax, 0x1
  cpuid
  test edx, 1<<25
  jz .noSSE
  ; SSE is available
  extern SSE_Available
  call SSE_Available
  ret
  .noSSE:
  extern SSE_NotAvailable ; Print message
  call SSE_NotAvailable
  ret
