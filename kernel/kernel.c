#include "Include/vga.h"
#include "Include/keyboard.h"
#include "Include/string.h"
#include "Include/time.h"
#include "Include/memory.h"
#include "kernelData.h"
#include "Include/cpu.h"
#include "Shell/Shell.h"
#include "Include/disk.h"
char ch[100];

void kmain(void) {
	clear();
	color(0x0F);

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

	/* Not working disk support!
	ide_initialize(0x1F0, 0x3F6, 0x170, 0x376, 0x000);
	ide_print_error(0, err);
	*/

	newLine();
	puts("[Kernel] Exit");

	return;
}
