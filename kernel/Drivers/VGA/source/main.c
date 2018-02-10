//Kirid VGA Driver
#include "../include/Display.h"
#include "../include/CRTC.h"

void vmain(void) {
    DisableDisplay();
    UnlockCRTC();

    LoadRegisters();
    ClearScreen();

    LockCRTC();
    EnableDisplay();
}