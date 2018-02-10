GCC=g++
LD=ld
NASM=nasm

G++_FLAGS=-m32 -c -O2 -Wall -Wextra -fno-builtin -nostdlib
GCC_FLAGS=-m32 -c -std=gnu99 -O2 -Wall -fno-stack-protector -fno-builtin -nostdlib

LD_FILES=build/boot.o build/kernel.o build/vga.o build/keyboard.o build/memory.o build/string.o build/shell.o build/ata.o
LD_FLAGS=-m elf_i386 -T linker.ld -o kirid.bin -O2 -nostdlib

all: clear Kirid

Kirid: boot.o kernel.o keyboard.o memory.o string.o vga.o shell.o ata.o
	$(LD) $(LD_FILES) $(LD_FLAGS)

#############################################################
boot.o:
	$(NASM) -felf32 kernel/boot.asm -o build/boot.o

kernel.o:
	gcc kernel/kernel.c -o build/kernel.o $(GCC_FLAGS)

keyboard.o:
	gcc kernel/Source/keyboard.c -o build/keyboard.o $(GCC_FLAGS)

memory.o:
	gcc kernel/Source/memory.c -o build/memory.o $(GCC_FLAGS)

string.o:
	gcc kernel/Source/string.c -o build/string.o $(GCC_FLAGS)

vga.o:
	gcc kernel/Source/vga.c -o build/vga.o $(GCC_FLAGS)

shell.o:
	gcc kernel/Shell/Shell.c -o build/shell.o $(GCC_FLAGS)

#Drivers########################################################
ata.o:
	gcc kernel/Drivers/ATA/ata.c -o build/ata.o $(GCC_FLAGS)

############################################################

clear:
	rm -rf build
	mkdir build
