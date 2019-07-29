MBALIGN equ 1<<0
MEMINFO equ 1<<1
MUSEGFX equ 1<<2
FLAGS equ MBALIGN | MEMINFO | MUSEGFX
MAGIC equ 0x1BADB002
CHECKSUM equ - (MAGIC + FLAGS)

section .multiboot
align 4
multiboot_header:
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
	dd 0x00000000
	dd 0x00000000
	dd 0x00000000
	dd 0x00000000
	dd 0x00000000
	; We want Text Mode with 80x25
	dd 0x00000001
	dd 80
	dd 25
	; We have no preference
	dd 0

section .bss
align 4
stack_bottom:
resb 16384
stack_top:

section .text
global _start:function (_start.end - _start)

_start:
	cli

	mov esp, stack_top

	extern _init
	call _init

	push ebx
	push eax

	extern kmain
	call kmain

	extern _fini
	call _fini
.hang: hlt
	jmp .hang

.end:
