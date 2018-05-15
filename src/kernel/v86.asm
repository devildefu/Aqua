detect_v86:
  smsw ax
  and eax, 1
  ret

; Entering to V86
; in C:
; extern void entering_v86(uint32_t ss, uint32_t esp, uint32_t cs, uint32_t eip);
entering_v86:
  mov ebp, esp               ; save esp (stack pointer)

  push dword [ebp+4]         ; ss
  push dword [ebp+8]         ; esp
  pushfd                     ; eflags
  or dword [esp], (1 << 17)
  push dword [ebp+12]
  push dword [ebp+16]
  iret
