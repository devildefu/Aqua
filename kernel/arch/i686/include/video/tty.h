#ifndef __TTY_H_
#define __TTY_H_

#include <stdint.h>
#include <stdbool.h>
#include <file.h>
#include <ports.h>

#define TTY_SCREEN_RES_X 80
#define TTY_SCREEN_RES_Y 25
#define TTY_SCREEN_RES TTY_SCREEN_RES_X * TTY_SCREEN_RES_Y

/// Struct for containing cursor date such as color and position
struct tty_CursorData {
   void(*res_func)(struct cursor_position*);
   uint16_t color;
   uint16_t pos;
} ttyMouse;

/// Get cursor x and y coordinate
uint16_t tty_cursor_get_x(struct tty_CursorData* cursor);
uint16_t tty_cursor_get_y(struct tty_CursorData* cursor);
/// Set and get cursor color
void tty_cursor_set_color(uint16_t color);
uint16_t tty_cursor_get_color();
/// Cursor gotoxy functions
void tty_cursor_gotoxy(uint16_t x, uint16_t y);
void tty_cursor_full_gotoxy(uint16_t xy);
/// Set and move cursor position functions
void tty_cursor_setpos(uint16_t x, uint16_t y);
void tty_cursor_move(uint16_t x, uint16_t y);
/// Create new line
void tty_newline();

/// Clear tty
void tty_clear();
/// Put char at the cursor position
void tty_putch(char ch);
/// Put string at the cursor position
void tty_putstr(const char* str);
/// Get and set tty text color
uint16_t tty_get_color(uint16_t x, uint16_t y);
void tty_set_color(uint16_t x, uint16_t y, uint16_t color);
/// Get and set char at the position
char tty_getch(uint16_t x, uint16_t y);
void tty_setch(uint16_t x, uint16_t y, char ch);
/// Fill tty buffer
void tty_fill_buffer(char ch, uint16_t color);

void* tty_procedure(int procedure, void* p, uint32_t size, FILE* that);

extern FILE sysTTY[1];

#define stdout sysTTY
#define stdin sysTTY
#define stderr sysTTY
#endif
