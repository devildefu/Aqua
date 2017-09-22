import os

commands = [
    "nasm -felf32 src/boot.asm -o build/boot.o",
    "gcc -m32 -c src/Modules/vga.c -o build/vga.o -std=gnu99 -O2 -Wall -Wextra -fno-builtin -nostdlib",
    "gcc -m32 -c src/kernel.c -o build/kernel.o -std=gnu99 -O2 -Wall -Wextra -fno-builtin -nostdlib",
    "gcc -c src/Modules/io.c -o build/io.o -std=gnu99 -O2 -Wall -Wextra -fno-builtin -nostdlib",
    "gcc -c src/Modules/keyboard.c -o build/keyboard.o -std=gnu99 -O2 -Wall -Wextra -fno-builtin -nostdlib",
    "ld -m elf_i386 build/boot.o build/kernel.o build/vga.o build/keyboard.o -T linker.ld -o kernel -O2 -nostdlib"
]

for cmd in commands:
    print('Running: ' + cmd)
    os.system(cmd)
