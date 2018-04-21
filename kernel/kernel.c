#include "Include/vga.h"
#include "Include/keyboard.h"
#include "Include/string.h"
#include "Include/time.h"
#include "Include/memory.h"
#include "kernelData.h"
#include "Include/cpu.h"
#include "Include/io.h"
#include "Shell/Shell.h"
#include "Drivers/ATA/ata.h"
#include "Include/A20.h"
#include "Drivers/VGA/include/main.h"
#include "Drivers/Beeper/beeper.h"

void kmain(void) {
	clear();
	color(0x0F);

	//startVGA();
	//Kernel Logs
	CPU_INFO cpuData;
	CPUInfo(&cpuData);

	puts("[Kernel] Kernel Version: ");
	puts(kernelVer);
	newLine();
	puts("[CPU] Manufacturer: ");
	puts(cpuData.vendor);
	newLine();
	puts("[CPU] Name: ");
	puts(cpuData.name);
	newLine();
	//puts("[Kernel] Starting main shell...");

	//shell();
	puts("[ATA Driver]: ");
	identify(0x1F6);
  newLine();

  puts("[KShell] Running...");
  newLine();
  shell();

	beep(1000);

	newLine();
	puts("[Kernel] Exit");

	//startVGA();
	return;
}
