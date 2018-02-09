#ifndef __VGA_H_
#define __VGA_H_

#include "definitions.h"

struct cursor_position {
  void(*res_func)(struct cursor_position*);
  uint16_t p;
};

uint16_t get_x_coordinate(struct cursor_position* cursor);
uint16_t get_y_coordinate(struct cursor_position* cursor);

void clear();
void putchar(char character);
void puts(const char* str);
void color(uint16_t color);
void sgotoxy(uint16_t x, uint16_t y);
void mgotoxy(uint16_t xy);
void newLine();
void move(uint16_t x, uint16_t y);

int snprintf(char* s, size_t n, const char* format, ...); //<- Prints formatted text to the string with limitted size
int sprintf(char* s, const char* format, ...); //<- Prints formatted text to the string
int printf(const char* format, ...); //<- Prints formatted text to output buffer
int scanf(const char* format, ...); //<- Reads data from input data and saves to variables

#endif
