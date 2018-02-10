#include "Include/vga.h"
#include "Include/keyboard.h"
#include "Include/string.h"
#include "Include/time.h"
#include "Include/memory.h"
#include "kernelData.h"
#include "Include/cpu.h"
#include "Shell/Shell.h"

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
	puts("[Kernel] Starting main shell...");

	//shell();
	char tab[10];
	int a = getchar(1);
	integerToString(a,tab);
	puts(a);

	newLine();
	puts("[Kernel] Exit");

	return;
}
