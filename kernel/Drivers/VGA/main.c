//Kirid VGA Driver

void vmain(void) {
    DisableDisplay();
    UnlockCRTC();

    LoadRegisters();
    ClearScreen();

    LockCRTC();
    EnableDisplay();
}