#include "Include/vga.h"
#include "Include/keyboard.h"
#include "Include/string.h"
#include "Include/time.h"
#include "Include/memory.h"

typedef void(*c_ptr)(char);

void kmain(void) {
	/*
	char str[10];
	getStringc(str,10,13);
	memset(str,'-',9);
	str[9] = '\0';
	puts(str);
	*/
	clear();
	color(0x0F);

  //void* lol = (void*)0x1000e;
  //c_ptr f_ptr = (c_ptr)0x1000e;
  //f_ptr('a');

  uint16_t CS;
  asm("movl %0, %%cs;" : "=r"(CS));

  const char* dog;
  integerToString(CS, dog);

  puts(dog);

	return;
}
