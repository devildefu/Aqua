list(APPEND SOURCE
    libk/stdlib.c
    libk/string.c
    libk/stdio.c
    libk/stdio/printf.c
    libk/stdio/sprintf.c
    libk/stdio/vsprintf.c
)

set(SOURCE "${SOURCE}" PARENT_SCOPE)