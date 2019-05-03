#ifndef __TTY_H_
#define __TTY_H_

#include <stdint.h>
#include <file.h>
#include <ports.h>
#include <string.h>
#include <devices/keyboard.h>

#include <stdarg.h>

#define SCREEN_RES_X 80
#define SCREEN_RES_Y 25
#define SCREEN_RES SCREEN_RES_X * SCREEN_RES_Y

struct cursor_position {
  void(*res_func)(struct cursor_position*);
  uint16_t c;
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
void set_position(uint16_t x, uint16_t y);
void set_color(uint16_t x, uint16_t y, uint16_t color);
void set_char(uint16_t x, uint16_t y, char c);
char get_char(uint16_t x, uint16_t y);
uint16_t get_color(uint16_t x, uint16_t y);

void fill_buffer(char c, uint16_t color);

int snprintf(char* s, size_t n, const char* format, ...); //<- Prints formatted text to the string with limitted size
int sprintf(char* s, const char* format, ...); //<- Prints formatted text to the string
int printf(const char* format, ...); //<- Prints formatted text to output buffer
int scanf(const char* format, ...); //<- Reads data from input data and saves to variables

void* tty_procedure(int procedure, void* p, uint32_t size, FILE* that);

extern FILE systty[1];

#define stdout systty
#define stdin systty
#define stderr systty

#endif
