GCC=gcc
LD=ld
NASM=nasm

GCC_FLAGS=-m32 -c -std=gnu99 -O2 -Wall -Wextra -fno-builtin -nostdlib

LD_FILES=build/boot.o build/kernel.o build/vga.o build/keyboard.o build/memory.o build/string.o
LD_FLAGS=-m elf_i386 -T linker.ld -o kernel -O2 -nostdlib

all: clear DogOS

DogOS: boot.o kernel.o keyboard.o memory.o string.o vga.o
	$(LD) $(LD_FILES) $(LD_FLAGS)

#############################################################
boot.o:
	$(NASM) -felf32 kernel/boot.asm -o build/boot.o

kernel.o:
	$(GCC) kernel/kernel.c -o build/kernel.o $(GCC_FLAGS)

keyboard.o:
	$(GCC) kernel/Modules/keyboard.c -o build/keyboard.o $(GCC_FLAGS)

memory.o:
	$(GCC) kernel/Modules/memory.c -o build/memory.o $(GCC_FLAGS)

string.o:
	$(GCC) kernel/Modules/string.c -o build/string.o $(GCC_FLAGS)

vga.o:
	$(GCC) kernel/Modules/vga.c -o build/vga.o $(GCC_FLAGS)
############################################################

clear:
	rm -rf build
	mkdir build