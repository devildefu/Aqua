#ifndef __VGA_H_
#define __VGA_H_

#include "definitions.h"

struct {
  uint16_t curr_pos;
} curr;

void clear();
void putchar(char character);
void puts(const char* str);
void color(uint16_t color);
void gotoxy(int x, int y);

int snprintf(char* s, size_t n, const char* format, ...); //<- Prints formatted text to the string with limitted size
int sprintf(char* s, const char* format, ...); //<- Prints formatted text to the string
int printf(const char* format, ...); //<- Prints formatted text to output buffer
int scanf(const char* format, ...); //<- Reads data from input data and saves to variables

#endif
