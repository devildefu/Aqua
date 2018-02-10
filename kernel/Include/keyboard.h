#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

typedef enum {
	GET_WAIT,
	GET_NOWAIT
} BREAK;

char getKeycode();
char getKeycodeWait();
char getchar(BREAK show_opts);

#endif
