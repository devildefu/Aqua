#include <video/tty.h>
#include <definitions.h>

static char* vgaBuffer = (char*)0xb8000;

/// Get cursor x and y coordinate
uint16_t tty_get_x(struct tty_CursorData* cursor) {
	if(cursor != NULL) {
		return cursor->pos % (TTY_SCREEN_RES_X*2);
	}
	return 0;
}

uint16_t tty_get_y(struct tty_CursorData* cursor) {
	if(cursor != NULL) {
		return cursor->pos / (TTY_SCREEN_RES_X*2);
	}
	return 0;
}

/// Set and get cursor color
void tty_cursor_set_color(uint16_t color) {
	ttyMouse.color = color;
}

uint16_t tty_cursor_get_color() {
	return ttyMouse.color;
}

/// Cursor gotoxy functions
void tty_gotoxy(uint16_t x, uint16_t y) {
	tty_cursor_full_gotoxy(x+y*TTY_SCREEN_RES_X);
}

void tty_full_gotoxy(uint16_t xy) {
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t)(xy & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t)((xy >> 8) & 0xFF));
}

/// Set and move cursor position functions
void tty_setpos(uint16_t x, uint16_t y) {
	ttyMouse.pos = (x*2+y*TTY_SCREEN_RES_X);
	tty_cursor_full_gotoxy(ttyMouse.pos/2);
}

void tty_move(uint16_t x, uint16_t y) {
	ttyMouse.pos += (y*TTY_SCREEN_RES_X+x*2);
	tty_cursor_full_gotoxy(ttyMouse.pos/2);
}

/// Create new line
void tty_newline() {
	ttyMouse.pos+=((TTY_SCREEN_RES_X*2)-(ttyMouse.pos%(TTY_SCREEN_RES_X*2)));
	tty_cursor_full_gotoxy(ttyMouse.pos/2);
}

/// Clear tty
void tty_clear() {
	tty_fill_buffer(0, 0);
}

/// Put char at the cursor position
void tty_putch(char ch) {
	switch(ch) {
	case '\n':
		vgaBuffer[ttyMouse.pos]='\n';
		ttyMouse.pos+=((TTY_SCREEN_RES_X*2)-(ttyMouse.pos%(TTY_SCREEN_RES_X*2)));
		break;
	case '\0':
		break;
	case 0x08:
		if(ttyMouse.pos > 0) {
			ttyMouse.pos -= 2;
			while(!vgaBuffer[ttyMouse.pos] && ttyMouse.pos) {
				ttyMouse.pos -= 2;
			}
			vgaBuffer[ttyMouse.pos] = 0;
			vgaBuffer[ttyMouse.pos+1] = 0;
		}
		break;
	default:
		vgaBuffer[ttyMouse.pos] = ch;
		vgaBuffer[ttyMouse.pos+1] = ttyMouse.color;
		ttyMouse.pos+=2;
		break;
	}
	tty_cursor_full_gotoxy(ttyMouse.pos/2);
}

/// Put string at the cursor position
void tty_write(const char* str) {
	unsigned short i = 0;

	while(str[i] != '\0') {
		tty_putch(str[i]);
		i += 1;
 	}
}

/// Get and set tty text color
uint16_t tty_get_color(uint16_t x, uint16_t y) {
	return (x*2+y*TTY_SCREEN_RES_X-1);
}

void tty_set_color(uint16_t x, uint16_t y, uint16_t color) {
	vgaBuffer[x*2+y*TTY_SCREEN_RES_X-1] = color;
}

/// Get and set char at the position
char tty_getch(uint16_t x, uint16_t y) {
	return(x*2+y*TTY_SCREEN_RES_X);
}

void tty_setch(uint16_t x, uint16_t y, char ch) {
	vgaBuffer[x*2+y*TTY_SCREEN_RES_X] = ch;
}

/// Fill tty buffer
void tty_fill_buffer(char ch, uint16_t color) {
	for(uint16_t i = 0; i < TTY_SCREEN_RES*2; i+=2) {
		vgaBuffer[i] = ch;
		vgaBuffer[i+1] = color;
	}
}
