#ifndef __VGA_H_
#define __VGA_H_

//#include "definitions.h"

typedef unsigned int uint16_t;

void clear();
void putchar(char character);
void puts(const char* str);
void color(uint16_t color);
static void vga_scroll();

#endif
