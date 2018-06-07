arch=i686
build=build/$(arch)

src=src
kernel=$(src)/kernel
drivers=$(src)/drivers
shell=$(src)/shell
executable=$(src)/executable

GCC=gcc
GPP=g++
LD=ld
NASM=nasm

G++_FLAGS=-m32 -c -O2 -Wall -Wextra -fno-builtin -nostdlib
GCC_FLAGS=-m32 -c -std=gnu99 -O2 -Wall -fno-stack-protector -fno-builtin -nostdlib -I$(src)

ASM_FILES=$(build)/boot.o $(build)/v86.o $(build)/sse_asm.o $(build)/registers.o
C_FILES=$(build)/kernel.o $(build)/tty.o $(build)/keyboard.o $(build)/memory.o $(build)/string.o $(build)/interrupts.o $(build)/beeper.o $(build)/pci.o $(build)/sse_c.o $(build)/setjmp.o $(build)/file.o $(build)/ps2.o $(build)/ps2_keyboard.o
LD_FILES=$(ASM_FILES) $(C_FILES) 
LD_FLAGS=-m elf_i386 -T linker.ld -o kirid -O2 -nostdlib

all: Kirid

Kirid: create_directories assembly c_lang
	$(LD) $(LD_FILES) $(LD_FLAGS)

#Assembly ####################################################
assembly: boot.o v86.o sse_asm.o registers.o

boot.o:
	$(NASM) -felf32 $(kernel)/boot.asm -o $(build)/boot.o

v86.o:
	$(NASM) -felf32 $(kernel)/v86/v86.asm -o $(build)/v86.o

sse_asm.o:
	$(NASM) -felf32 $(kernel)/device/cpu/sse.asm -o $(build)/sse_asm.o

registers.o:
	$(NASM) -felf32 $(kernel)/processor/registers.asm -o $(build)/registers.o

#C ###########################################################
c_lang: kernel.o keyboard.o memory.o string.o tty.o interrupts.o beeper.o pci.o sse_c.o setjmp.o file.o ps2.o ps2_keyboard.o

kernel.o:
	$(GCC) $(kernel)/kernel.c -o $(build)/kernel.o $(GCC_FLAGS)

keyboard.o:
	$(GCC) $(kernel)/input/keyboard.c -o $(build)/keyboard.o $(GCC_FLAGS)

memory.o:
	$(GCC) $(kernel)/memory/memory.c -o $(build)/memory.o $(GCC_FLAGS)

string.o:
	$(GCC) $(kernel)/string/string.c -o $(build)/string.o $(GCC_FLAGS)

tty.o:
	$(GCC) $(kernel)/display/tty.c -o $(build)/tty.o $(GCC_FLAGS)

#shell.o:
#	$(GCC) $(shell)/shell.c -o $(build)/shell.o $(GCC_FLAGS)

interrupts.o:
	$(GCC) $(kernel)/utils/interrupts.c -o $(build)/interrupts.o $(GCC_FLAGS)

sse_c.o:
	$(GCC) $(kernel)/device/cpu/sse.c -o $(build)/sse_c.o $(GCC_FLAGS)

setjmp.o:
	$(GCC) $(kernel)/processor/setjmp.c -o $(build)/setjmp.o $(GCC_FLAGS)

file.o:
	$(GCC) $(kernel)/files/file.c -o $(build)/file.o $(GCC_FLAGS)

#Drivers ########################################################
beeper.o:
	$(GCC) $(drivers)/beeper/beeper.c -o $(build)/beeper.o $(GCC_FLAGS)

pci.o:
	$(GCC) $(drivers)/PCI/pci.c -o $(build)/pci.o $(GCC_FLAGS)

#PS2#

ps2.o:
	$(GCC) $(drivers)/PS2/ps2.c -o $(build)/ps2.o $(GCC_FLAGS)

ps2_keyboard.o:
	$(GCC) $(drivers)/PS2/keyboard/keyboard.c -o $(build)/ps2_keyboard.o $(GCC_FLAGS)

############################################################

create_directories:
	rm -rf build
	mkdir build
	mkdir build/$(arch)
