#ifndef BEEPER_H
#define BEEPER_H

#include <core/include/ports.h>

static void play_sound(uint32_t frequence); //play sound using beeper
static void nosound();                      //shutup beeper
void beep(uint32_t frequence);              //function to beeep

#endif
