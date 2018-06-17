arch = i686
build = build/$(arch)

src = src
kernel = $(src)/kernel
drivers = $(src)/drivers
elf = $(src)/elf

GCC = gcc
LD = ld
ASM = nasm

GCC_FLAGS = -m32 -c -std=gnu99 -Wall -fno-stack-protector -fno-builtin -nostdlib -I$(src)
# Additional arguments
GCC_FLAGS += -O2

ASM_FILES = $(build)/boot.o $(build)/v86.o $(build)/sse_asm.o $(build)/registers.o
C_FILES = $(build)/kernel.o $(build)/tty.o $(build)/keyboard.o $(build)/memory.o $(build)/string.o $(build)/int.o $(build)/beeper.o $(build)/pci.o $(build)/sse_c.o $(build)/setjmp.o $(build)/file.o $(build)/ps2.o $(build)/ps2_keyboard.o $(build)/cmos.o
LD_FILES = $(ASM_FILES) $(C_FILES) 
LD_FLAGS = -m elf_i386 -T linker.ld -o kirid -O2 -nostdlib

all: Kirid

Kirid: assembly c_lang
	$(LD) $(LD_FILES) $(LD_FLAGS)

#Assembly ####################################################
assembly: boot.o v86.o sse_asm.o registers.o

boot.o:
	$(ASM) -felf32 $(kernel)/boot.asm -o $(build)/boot.o

v86.o:
	$(ASM) -felf32 $(kernel)/sys/v86.asm -o $(build)/v86.o

sse_asm.o:
	$(ASM) -felf32 $(kernel)/cpu/sse.asm -o $(build)/sse_asm.o

registers.o:
	$(ASM) -felf32 $(kernel)/misc/registers.asm -o $(build)/registers.o

#C ###########################################################
c_lang: kernel.o keyboard.o memory.o string.o tty.o int.o beeper.o pci.o sse_c.o setjmp.o file.o ps2.o ps2_keyboard.o cmos.o

kernel.o:
	$(GCC) $(kernel)/kernel.c -o $(build)/kernel.o $(GCC_FLAGS)

keyboard.o:
	$(GCC) $(kernel)/devices/keyboard.c -o $(build)/keyboard.o $(GCC_FLAGS)

memory.o:
	$(GCC) $(kernel)/memory/memory.c -o $(build)/memory.o $(GCC_FLAGS)

string.o:
	$(GCC) $(kernel)/misc/string.c -o $(build)/string.o $(GCC_FLAGS)

tty.o:
	$(GCC) $(kernel)/video/tty.c -o $(build)/tty.o $(GCC_FLAGS)

int.o:
	$(GCC) $(kernel)/cpu/int.c -o $(build)/int.o $(GCC_FLAGS)

sse_c.o:
	$(GCC) $(kernel)/cpu/sse.c -o $(build)/sse_c.o $(GCC_FLAGS)

setjmp.o:
	$(GCC) $(kernel)/misc/setjmp.c -o $(build)/setjmp.o $(GCC_FLAGS)

file.o:
	$(GCC) $(kernel)/misc/file.c -o $(build)/file.o $(GCC_FLAGS)

#Drivers ########################################################
beeper.o:
	$(GCC) $(drivers)/beeper/beeper.c -o $(build)/beeper.o $(GCC_FLAGS)

pci.o:
	$(GCC) $(drivers)/pci/pci.c -o $(build)/pci.o $(GCC_FLAGS)

cmos.o:
	$(GCC) $(drivers)/cmos/cmos.c -o $(build)/cmos.o $(GCC_FLAGS)

#PS2#

ps2.o:
	$(GCC) $(drivers)/ps2/ps2.c -o $(build)/ps2.o $(GCC_FLAGS)

ps2_keyboard.o:
	$(GCC) $(drivers)/ps2/keyboard/keyboard.c -o $(build)/ps2_keyboard.o $(GCC_FLAGS)

############################################################
