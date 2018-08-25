src = ['core/kernel.c', 'cpu/int.c', 'cpu/sse.c', 'cpu/sse.h', 'devices/keyboard.c', 'memory/memory.c', 'misc/file.c', 'misc/random.c', 'misc/setjmp.c', 'misc/string.c',
]
asm_src = ['cpu/sse.asm', '']

# meson.get_cross_property('somekey')

subdir('arch/' + host_machine.cpu())
subdir('arch/' + host_machine.cpu() + '/' +meson.get_cross_property('machine'))