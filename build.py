import os

commands = [
    "nasm -felf32 src/boot.asm -o build/boot.o",
    "gcc -c src/kernel.c -o build/kernel.o -std=c99 -O2 -Wall -Wextra -fno-builtin -nostdlib",
    "ld build/boot.o build/kernel.o -T linker.ld -o kernel -O2 -nostdlib"
]

for cmd in commands:
    print('Running: ' + cmd)
    os.system(cmd)
