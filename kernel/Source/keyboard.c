#include "../Include/keyboard.h"
#include "../Include/io.h"
#include "../Include/definitions.h"


char ANSI_Translation_Tab[] =
{'1','2','3','4','5','6','7','8','9','0','-','=',9,'q','w','e','r','t'
,'y','u','i','o','p','[',']','a','s','d','f','g','h','j','k','l',';','\'',
'`','\\','z','x','c','v','b','n','m',',','.','/','*',' ','7','8','9','-',
'4','5','6','+','1','2','3','0','.',13,27,127,127,15,14,32,8};


char getKeycode() {
	char k = inb(0x60);
	outb(0x60,0);
	return k;
}

char getKeycodeWait() {
	char k;
	while(!(k = getKeycode()));
	return k;
}

char getchar(char show_opts) {
	char keycode;
	if(show_opts = 1)
		keycode = getKeycodeWait();
	else
		keycode = getKeycode();
	if(keycode < 2) return 0;
	return  ANSI_Translation_Tab[keycode-2];
}
