arch=i686
build=build/$(arch)

kernel=src/kernel
drivers=src/drivers
shell=src/shell
executable=src/executable

GCC=gcc
GPP=g++
LD=ld
NASM=nasm

G++_FLAGS=-m32 -c -O2 -Wall -Wextra -fno-builtin -nostdlib
GCC_FLAGS=-m32 -c -std=gnu99 -O2 -Wall -fno-stack-protector -fno-builtin -nostdlib -I$(kernel)

ASM_FILES=$(build)/boot.o $(build)/v86.o $(build)/sse_asm.o
C_FILES=$(build)/kernel.o $(build)/tty.o $(build)/keyboard.o $(build)/memory.o $(build)/string.o $(build)/shell.o $(build)/interrupts.o $(build)/beeper.o $(build)/pci.o $(build)/sse_c.o
LD_FILES=$(ASM_FILES) $(C_FILES) 
LD_FLAGS=-m elf_i386 -T linker.ld -o kirid -O2 -nostdlib

all: Kirid

Kirid: assembly c_lang
	$(LD) $(LD_FILES) $(LD_FLAGS)

#Assembly ####################################################
assembly: boot.o v86.o sse_asm.o

boot.o:
	$(NASM) -felf32 $(kernel)/boot.asm -o $(build)/boot.o

v86.o:
	$(NASM) -felf32 $(kernel)/v86/v86.asm -o $(build)/v86.o

sse_asm.o:
	$(NASM) -felf32 $(kernel)/device/cpu/sse.asm -o $(build)/sse_asm.o

#C ###########################################################
c_lang: kernel.o keyboard.o memory.o string.o tty.o shell.o interrupts.o beeper.o pci.o sse_c.o

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

shell.o:
	$(GCC) $(shell)/shell.c -o $(build)/shell.o $(GCC_FLAGS)

interrupts.o:
	$(GCC) $(kernel)/utils/interrupts.c -o $(build)/interrupts.o $(GCC_FLAGS)

sse_c.o:
	$(GCC) $(kernel)/device/cpu/sse.c -o $(build)/sse_c.o $(GCC_FLAGS)

#Drivers ########################################################
beeper.o:
	$(GCC) $(drivers)/beeper/beeper.c -o $(build)/beeper.o $(GCC_FLAGS)

pci.o:
	$(GCC) $(drivers)/PCI/pci.c -o $(build)/pci.o $(GCC_FLAGS)
############################################################

create_directories:
	mkdir build/$(arch);

clear:
	rm -rf build
	mkdir build
