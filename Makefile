arch=i686
build=build/$(arch)

GCC=gcc
GPP=g++
LD=ld
NASM=nasm

G++_FLAGS=-m32 -c -O2 -Wall -Wextra -fno-builtin -nostdlib
GCC_FLAGS=-m32 -c -std=gnu99 -O2 -Wall -fno-stack-protector -fno-builtin -nostdlib

LD_FILES=$(build)/boot.o $(build)/kernel.o $(build)/vga.o $(build)/keyboard.o $(build)/memory.o $(build)/string.o $(build)/shell.o $(build)/A20.o $(build)/interrupts.o $(build)/ata.o 
LD_FLAGS=-m elf_i386 -T linker.ld -o kirid -O2 -nostdlib
:q
all: Kirid

Kirid: boot.o kernel.o keyboard.o memory.o string.o vga.o shell.o A20.o interrupts.o ata.o
	$(LD) $(LD_FILES) $(LD_FLAGS)

#############################################################
boot.o:
	$(NASM) -felf32 kernel/boot.asm -o $(build)/boot.o

kernel.o:
	$(GCC) kernel/kernel.c -o $(build)/kernel.o $(GCC_FLAGS)

keyboard.o:
	$(GCC) kernel/Source/keyboard.c -o $(build)/keyboard.o $(GCC_FLAGS)

memory.o:
	$(GCC) kernel/Source/memory.c -o $(build)/memory.o $(GCC_FLAGS)

string.o:
	$(GCC) kernel/Source/string.c -o $(build)/string.o $(GCC_FLAGS)

vga.o:
	$(GCC) kernel/Source/vga.c -o $(build)/vga.o $(GCC_FLAGS)

shell.o:
	$(GCC) kernel/Shell/Shell.c -o $(build)/shell.o $(GCC_FLAGS)

A20.o:
	$(GCC) kernel/Source/A20.c -o $(build)/A20.o $(GCC_FLAGS) -masm=intel

interrupts.o:
	$(GCC) kernel/Source/interrupts.c -o $(build)/interrupts.o $(GCC_FLAGS)

#Drivers########################################################
ata.o:
	$(GCC) kernel/Drivers/ATA/ata.c -o $(build)/ata.o $(GCC_FLAGS)

vga_driver.o:
	$(GCC) kernel/Drivers/VGA/source/main.c -o $(build)/vga_driver.o $(GCC_FLAGS)

############################################################

create_directories:
	mkdir build/$(arch);

clear:
	rm -rf build
	mkdir build
