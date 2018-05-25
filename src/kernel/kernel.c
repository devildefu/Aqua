#include "config.h"

#include <display/tty.h>
#include <device/cpu.h>

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
  SSE_Check();
  newLine();
	
	newLine();
	puts("[Kernel] Exit");
	return;
}
