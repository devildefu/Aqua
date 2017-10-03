#ifndef __VGA_H_
#define __VGA_H_

#include "definitions.h"

void clear();
void putchar(char character);
void puts(const char* str);
void color(uint16_t color);
void gotoxy(int x, int y);

#endif
