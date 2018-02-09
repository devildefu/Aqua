#include "../Include/vga.h"
#include "../Include/keyboard.h"
#include "../Include/string.h"
#include "../Include/time.h"
#include "../Include/memory.h"
#include "Shell.h"

int isExit = 0;
char* command = "NULL";

void commands(char* cmd) {
  if(cmd == "exit") {
    isExit = 1;
    puts("BYYHB");
  }
}

void shell(void) {
  newLine();
  while(1) {
    newLine();
    puts("$ ");
    getStringc(command, 2000, 13);
    puts(command);
    commands(command);
    if(command == "exit") {
      isExit = 1;
      puts("BYYHB");
    }
  }
  return;
}
