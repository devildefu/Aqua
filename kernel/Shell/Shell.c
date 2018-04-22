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
  /*
  newLine();
  while(1) {
    newLine();
    puts("$ -> ");
    getStringc(command, 2000, 13);
    puts(command);
    commands(command);
    if(command == "exit") {
      return;
    }
  }
  */
  
  //I commented on the code because it did not work + broke the entire screen ;) ~defu
  puts("[KShell] KShell does not work fully due to the lack of ATA and FAT32 support, so most commands do not work or are... artificial?");
  newLine();
  //puts("$ -> ");
  return;
}
