import os

commands = [
    "nasm stage1.asm -o build/stage1.bin"
]

files = [
    "build/stage1.bin"
]

for cmd in commands:
    os.system(cmd)

buf = []
for f in files:
    with open(f, "rb") as x:
        buf.append(x.read())

with open('floppy.img', 'wb') as f:
    f.write(''.join(buf))