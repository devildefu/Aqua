GCC=g++
LD=ld
NASM=nasm

GCC_FLAGS=-m32 -c -O2 -Wall -Wextra -fno-builtin -nostdlib
GCC_FLAGS2=-m32 -c -std=gnu99 -O2 -Wall -Wextra -fno-builtin -nostdlib

LD_FILES=build/boot.o build/kernel.o build/vga.o build/keyboard.o build/memory.o build/string.o
LD_FLAGS=-m elf_i386 -T linker.ld -o kirid -O2 -nostdlib

all: clear Kirid

Kirid: boot.o kernel.o keyboard.o memory.o string.o vga.o
	$(LD) $(LD_FILES) $(LD_FLAGS)

#############################################################
boot.o:
	$(NASM) -felf32 kernel/boot.asm -o build/boot.o

kernel.o:
	gcc kernel/kernel.c -o build/kernel.o $(GCC_FLAGS2)

keyboard.o:
	gcc kernel/Source/keyboard.c -o build/keyboard.o $(GCC_FLAGS2)

memory.o:
	gcc kernel/Source/memory.c -o build/memory.o $(GCC_FLAGS2)

string.o:
	gcc kernel/Source/string.c -o build/string.o $(GCC_FLAGS2)

vga.o:
	gcc kernel/Source/vga.c -o build/vga.o $(GCC_FLAGS2)
############################################################

clear:
	rm -rf build
	mkdir build
