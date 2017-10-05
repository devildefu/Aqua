#ifndef __VGA_H_
#define __VGA_H_

#include "definitions.h"

void clear();
void putchar(char character);
void puts(const char* str);
void color(uint16_t color);
void gotoxy(int x, int y);
int sprintf(const char*, ...); //<- Draws on default display buffer text with converted variables
                               //On success returns size of displayed string

#endif
