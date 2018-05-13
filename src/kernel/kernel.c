#include "kernelData.h"

#include <display/tty.h>
#include <device/cpu.h>

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

	newLine();
	puts("[Kernel] Exit");

	//startVGA();
	return;
}
