#include "sata.h"
#include "../../Include/vga.h"
#include "../../Include/string.h"
#include "../../Include/memory.h"

// Check device type
int check_type(HBA_PORT* port) {
	//uint32_t = port->ssts;

	uint8_t ipm = (port->ssts >> 8) & 0x0F;
	uint8_t det = port->ssts & 0x0F;

	if (det != HBA_PORT_DET_PRESENT)	// Check drive status
		return AHCI_DEV_NULL;
	if (ipm != HBA_PORT_IPM_ACTIVE)
		return AHCI_DEV_NULL;

	switch (port->sig)
	{
	case SATA_SIG_ATAPI:
		return AHCI_DEV_SATAPI;
	case SATA_SIG_SEMB:
		return AHCI_DEV_SEMB;
	case SATA_SIG_PM:
		return AHCI_DEV_PM;
	default:
		return AHCI_DEV_SATA;
	}
}

void probe_port(HBA_MEM *abar) {
	// Search disk in impelemented ports
	uint32_t pi = abar->pi;
	int i = 0;
	while (i<32)
	{
		if (pi & 1)
		{
			int dt = check_type(&abar->ports[i]);
			if (dt == AHCI_DEV_SATA)
			{
        puts("SATA drive found at port ");
        char* i2sp;
        integerToString(i, i2sp);
        puts(i2sp);
	      newLine();
			}
			else if (dt == AHCI_DEV_SATAPI)
			{
        puts("SATAPI drive found at port ");
        char* i2sp;
        integerToString(i, i2sp);
        puts(i2sp);
	      newLine();
			}
			else if (dt == AHCI_DEV_SEMB)
			{
        puts("SEMB drive found at port ");
        char* i2sp;
        integerToString(i, i2sp);
        puts(i2sp);
	      newLine();
			}
			else if (dt == AHCI_DEV_PM)
			{
        puts("PM drive found at port ");
        char* i2sp;
        integerToString(i, i2sp);
        puts(i2sp);
	      newLine();
			}
			else
			{
        puts("No drive found at port ");
        char* i2sp;
        integerToString(i, i2sp);
        puts(i2sp);
	      newLine();
			}
		}

		pi >>= 1;
		i ++;
	}
}

// Start command engine
void start_cmd(HBA_PORT *port) {
	// Wait until CR (bit15) is cleared
	while (port->cmd & HBA_PxCMD_CR);

	// Set FRE (bit4) and ST (bit0)
	port->cmd |= HBA_PxCMD_FRE;
	port->cmd |= HBA_PxCMD_ST;
}

// Stop command engine
void stop_cmd(HBA_PORT *port) {
	// Clear ST (bit0)
	port->cmd &= ~HBA_PxCMD_ST;

	// Wait until FR (bit14), CR (bit15) are cleared
	while(1)
	{
		if (port->cmd & HBA_PxCMD_FR)
			continue;
		if (port->cmd & HBA_PxCMD_CR)
			continue;
		break;
	}

	// Clear FRE (bit4)
	port->cmd &= ~HBA_PxCMD_FRE;
}

void port_rebase(HBA_PORT *port, int portno) {
	stop_cmd(port);	// Stop command engine

	// Command list offset: 1K*portno
	// Command list entry size = 32
	// Command list entry maxim count = 32
	// Command list maxim size = 32*32 = 1K per port
	port->clb = AHCI_BASE + (portno<<10);
	port->clbu = 0;
	memset((void*)(port->clb), 0, 1024);

	// FIS offset: 32K+256*portno
	// FIS entry size = 256 bytes per port
	port->fb = AHCI_BASE + (32<<10) + (portno<<8);
	port->fbu = 0;
	memset((void*)(port->fb), 0, 256);

	// Command table offset: 40K + 8K*portno
	// Command table size = 256*32 = 8K per port
	HBA_CMD_HEADER *cmdheader = (HBA_CMD_HEADER*)(port->clb);
	for (int i=0; i<32; i++)
	{
		cmdheader[i].prdtl = 8;	// 8 prdt entries per command table
					// 256 bytes per command table, 64+16+48+16*8
		// Command table offset: 40K + 8K*portno + cmdheader_index*256
		cmdheader[i].ctba = AHCI_BASE + (40<<10) + (portno<<13) + (i<<8);
		cmdheader[i].ctbau = 0;
		memset((void*)cmdheader[i].ctba, 0, 256);
	}

	start_cmd(port);	// Start command engine
}
