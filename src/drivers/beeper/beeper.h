#ifndef BEEPER_H
#define BEEPER_H

#include <kernel/io/ports.h>

static void play_sound(uint32_t nFrequence); //play sound using beeper
static void nosound();                       //shutup beeper
void beep(uint32_t milliseconds);            //function to beeep

#endif
