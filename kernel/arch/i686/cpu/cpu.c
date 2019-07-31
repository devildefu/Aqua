#include <cpu/cpu.h>
#include <cpuid.h>
#include <string.h>

void cpu_info(CPU_INFO* ptr) {
	unsigned int eax, ebx, ecx, edx;

	__get_cpuid(0x0, &eax, &ebx, &ecx, &edx);

	unsigned char vendor[13];
	memset(vendor, 0, sizeof(vendor));

	__get_cpuid(0x0, &eax, (unsigned int*)&vendor[0], (unsigned int*)&vendor[8], (unsigned int*)&vendor[4]);

	CPU_INFO inf = *ptr;
	memcpy(inf.vendor, vendor, sizeof(vendor));
	*ptr = inf;

	/* Processor Info and Feature Bits */
	if(eax >= 0x01) {
		__get_cpuid(0x01, &eax, &ebx, &ecx, &edx);

		if(ecx & ECX_SSE3) ptr->sse3 = 1;
		if(ecx & ECX_PCLMULQDQ) ptr->pclmulqdq = 1;
		if(ecx & ECX_DTES64) ptr->dtes64 = 1;
		if(ecx & ECX_MONITOR) ptr->monitor = 1;
		if(ecx & ECX_DS_CPL) ptr->ds_cpl = 1;
		if(ecx & ECX_VMX) ptr->vmx = 1;
		if(ecx & ECX_SMX) ptr->smx = 1;
		if(ecx & ECX_EST) ptr->est = 1;
		if(ecx & ECX_TM2) ptr->tm2 = 1;
		if(ecx & ECX_SSSE3) ptr->ssse3 = 1;
		if(ecx & ECX_CNXT_ID) ptr->cnxt_id = 1;
		if(ecx & ECX_FMA) ptr->fma = 1;
		if(ecx & ECX_CX16) ptr->cx16 = 1;
		if(ecx & ECX_XTPR) ptr->xtpr = 1;
		if(ecx & ECX_PDCM) ptr->pdcm = 1;
		if(ecx & ECX_PCID) ptr->pcid = 1;
		if(ecx & ECX_DCA) ptr->dca = 1;
		if(ecx & ECX_SSE41) ptr->sse4_1 = 1;
		if(ecx & ECX_SSE42) ptr->sse4_2 = 1;
		if(ecx & ECX_X2APIC) ptr->x2apic = 1;
		if(ecx & ECX_MOVBE) ptr->movbe = 1;
		if(ecx & ECX_TSC) ptr->local_apic_support = 1;
		if(ecx & ECX_AESNI) ptr->aesni = 1;
		if(ecx & ECX_XSAVE) ptr->xsave = 1;
		if(ecx & ECX_OSXSAVE) ptr->osxsave = 1;
		if(ecx & ECX_AVX) ptr->avx = 1;
		if(ecx & ECX_F16C) ptr->f16c = 1;
		if(ecx & ECX_RDRAND) ptr->rdrand = 1;

		if(edx & EDX_FPU) ptr->fpu = 1;
		if(edx & EDX_VME) ptr->vme = 1;
		if(edx & EDX_DE) ptr->de = 1;
		if(edx & EDX_PSE) ptr->pse = 1;
		if(edx & EDX_TSC) ptr->time_stamp_counter = 1;
		if(edx & EDX_MSR) ptr->msr = 1;
		if(edx & EDX_PAE) ptr->pae = 1;
		if(edx & EDX_MCE) ptr->mce = 1;
		if(edx & EDX_CX8) ptr->cx8 = 1;
		if(edx & EDX_ACPI) ptr->acpi = 1;
		if(edx & EDX_SEP) ptr->sep = 1;
		if(edx & EDX_MTRR) ptr->mtrr = 1;
		if(edx & EDX_PGE) ptr->pge = 1;
		if(edx & EDX_MCA) ptr->mca = 1;
		if(edx & EDX_CMOV) ptr->cmov = 1;
		if(edx & EDX_PAT) ptr->pat = 1;
		if(edx & EDX_PSE36) ptr->pse36 = 1;
		if(edx & EDX_PSN) ptr->psn = 1;
		if(edx & EDX_CLFLUSH) ptr->clflush = 1;
		if(edx & EDX_DS) ptr->ds = 1;
		if(edx & EDX_ACPI) ptr->acpi = 1;
		if(edx & EDX_MMX) ptr->mmx = 1;
		if(edx & EDX_FXSR) ptr->fxsr = 1;
		if(edx & EDX_SSE) ptr->sse = 1;
		if(edx & EDX_SSE2) ptr->sse2 = 1;
		if(edx & EDX_SS) ptr->ss = 1;
		if(edx & EDX_HTT) ptr->htt = 1;
		if(edx & EDX_TM) ptr->tm = 1;
		if(edx & EDX_PBE) ptr->pbe = 1;

		if(edx & EDX_64_BIT) {
			strcpy("amd64", ptr->architecture);
		} else {
			strcpy("i686", ptr->architecture);
		}
	}

	__get_cpuid(0x80000000, &eax, &ebx, &ecx, &edx);
	if(eax >= 0x80000001) {
		if(edx & EDX_SYSCALL) ptr->syscall = 1;
		if(edx & EDX_SYSCALL) ptr->syscall = 1;
		if(edx & EDX_MP) ptr->mp = 1;
		if(edx & EDX_NX) ptr->nx = 1;
		if(edx & EDX_MMXEXT) ptr->mmxext = 1;
		if(edx & EDX_FXSR_OPT) ptr->fxsr_opt = 1;
		if(edx & EDX_1GB_PAGE) ptr->pdpe1gb = 1;
		if(edx & EDX_RDTSCP) ptr->rdtscp = 1;
		if(edx & EDX_3DNOW) ptr->threeD_now = 1;
		if(edx & EDX_3DNOWEXT) ptr->threeD_nowext = 1;

		if(ecx & ECX_LAHF_LM) ptr->lahf_lm = 1;
		if(ecx & ECX_CMP_LEGACY) ptr->cmp_legacy = 1;
		if(ecx & ECX_SVM) ptr->svm = 1;
		if(ecx & ECX_EXTAPIC) ptr->ext_apic = 1;
		if(ecx & ECX_CR8_LEGACY) ptr->cr8_legacy = 1;
		if(ecx & ECX_ABM) ptr->abm = 1;
		if(ecx & ECX_SSE4A) ptr->sse4a = 1;
		if(ecx & ECX_MISALIGNSSE) ptr->misalignsse = 1;
		if(ecx & ECX_3DNOW_PREFETCH) ptr->threeD_now_prefetch = 1;
		if(ecx & ECX_OSVW) ptr->osvw = 1;
		if(ecx & ECX_IBS) ptr->ibs = 1;
		if(ecx & ECX_XOP) ptr->xop = 1;
		if(ecx & ECX_SKINIT) ptr->skinit = 1;
		if(ecx & ECX_WDT) ptr->wdt = 1;
		if(ecx & ECX_LWP) ptr->lwp = 1;
		if(ecx & ECX_FMA4) ptr->fma4 = 1;
		if(ecx & ECX_TCE) ptr->tce = 1;
		if(ecx & ECX_NODEID_MSR) ptr->nodeid_msr = 1;
		if(ecx & ECX_TBM) ptr->tbm = 1;
		if(ecx & ECX_TOPOEXT) ptr->topoext = 1;
		if(ecx & ECX_PERFCTR_CORE) ptr->perfctr_core = 1;
		if(ecx & ECX_PERFCTR_NB) ptr->perfctr_nb = 1;
		if(ecx & ECX_DBX) ptr->dbx = 1;
		if(ecx & ECX_PERFTSC) ptr->perftsc = 1;
		if(ecx & ECX_PCX_L2I) ptr->pcx_l2i = 1;
	}

	/* Processor info */

	if(eax >= 0x80000004) {
		char name[48];
		__get_cpuid(0x80000002, (unsigned int*)&(name[0]), (unsigned int*)&(name[4]), (unsigned int*)&(name[8]), (unsigned int*)&(name[12]));
		__get_cpuid(0x80000003, (unsigned int*)&(name[16]), (unsigned int*)&(name[20]), (unsigned int*)&(name[24]), (unsigned int*)&(name[28]));
		__get_cpuid(0x80000004, (unsigned int*)&(name[32]), (unsigned int*)&(name[36]), (unsigned int*)&(name[40]), (unsigned int*)&(name[44]));

		strcpy(name, ptr->name);
	}
}

void cpu_print_info() {
	/* TODO: print to serial port instead of screen */
	CPU_INFO info;
	cpu_info(&info);

	printf("CPU Vendor: %s\n", info.vendor);
	printf("CPU Name: %s\n", info.name);
	printf("CPU supported features: ");
	if(info.sse3 == 1) printf("SSE3 ");
	if(info.pclmulqdq == 1) printf("PCLMULQDQ ");
	if(info.dtes64 == 1) printf("DTES64 ");
	if(info.monitor == 1) printf("MONITOR ");
	if(info.ds_cpl == 1) printf("DS_CPL ");
	if(info.vmx == 1) printf("VMX ");
	if(info.smx == 1) printf("SMX ");
	if(info.est == 1) printf("EST ");
	if(info.tm2 == 1) printf("TM2 ");
	if(info.ssse3 == 1) printf("SSSE3 ");
	if(info.cnxt_id == 1) printf("CNXT_ID ");
	if(info.fma == 1) printf("FMA ");
	if(info.cx16 == 1) printf("CX16 ");
	if(info.xtpr == 1) printf("XTPR ");
	if(info.pdcm == 1) printf("PDCM ");
	if(info.pcid == 1) printf("PCID ");
	if(info.dca == 1) printf("DCA ");
	if(info.sse4_1 == 1) printf("SSE4.1 ");
	if(info.sse4_2 == 1) printf("SSE4.2 ");
	if(info.x2apic == 1) printf("X2APIC ");
	if(info.movbe == 1) printf("MOVBE ");
	if(info.popcnt == 1) printf("POPCNT ");
	if(info.time_stamp_counter == 1) printf("TIME_STAMP_COUNTER ");
	if(info.aesni == 1) printf("AESNI ");
	if(info.xsave == 1) printf("XSAVE ");
	if(info.osxsave == 1) printf("OSXSAVE ");
	if(info.avx == 1) printf("AVX ");
	if(info.f16c == 1) printf("F16C ");
	if(info.rdrand == 1) printf("RDRAND ");
	if(info.fpu == 1) printf("FPU ");
	if(info.vme == 1) printf("VME ");
	if(info.de == 1) printf("DE ");
	if(info.pse == 1) printf("PSE ");
	if(info.local_apic_support == 1) printf("LOCAL_APIC_SUPPORT ");
	if(info.msr == 1) printf("MSR ");
	if(info.pae == 1) printf("PAE ");
	if(info.mce == 1) printf("MCE ");
	if(info.cx8 == 1) printf("CX8 ");
	if(info.apic == 1) printf("APIC ");
	if(info.sep == 1) printf("SEP ");
	if(info.mtrr == 1) printf("MTRR ");
	if(info.pge == 1) printf("PGE ");
	if(info.mca == 1) printf("MCA ");
	if(info.cmov == 1) printf("CMOV ");
	if(info.pat == 1) printf("PAT ");
	if(info.pse36 == 1) printf("PSE36 ");
	if(info.psn == 1) printf("PSN ");
	if(info.clflush == 1) printf("CLFLUSH ");
	if(info.ds == 1) printf("DS ");
	if(info.acpi == 1) printf("ACPI ");
	if(info.mmx == 1) printf("MMX ");
	if(info.fxsr == 1) printf("FXSR ");
	if(info.sse == 1) printf("SSE ");
	if(info.sse2 == 1) printf("SSE2 ");
	if(info.ss == 1) printf("SS ");
	if(info.htt == 1) printf("HTT ");
	if(info.tm == 1) printf("TM ");
	if(info.pbe == 1) printf("PBE ");

	if(info.syscall == 1) printf("SYSCALL ");
	if(info.mp == 1) printf("MP ");
	if(info.nx == 1) printf("NX ");
	if(info.mmxext == 1) printf("MMXEXT ");
	if(info.fxsr_opt == 1) printf("FXSR_OPT ");
	if(info.pdpe1gb == 1) printf("PDPE1GB ");
	if(info.rdtscp == 1) printf("RDTSCP ");
	if(info.threeD_now == 1) printf("3DNOW! ");
	if(info.threeD_nowext == 1) printf("3DNOW!_EXT ");
	if(info.lahf_lm == 1) printf("LAHF_LM ");
	if(info.cmp_legacy == 1) printf("CMP_LEGACY ");
	if(info.svm == 1) printf("SVM ");
	if(info.ext_apic == 1) printf("EXT_APIC ");
	if(info.cr8_legacy == 1) printf("CR8_LEGACY ");
	if(info.abm == 1) printf("ABM ");
	if(info.sse4a == 1) printf("SSE4A ");
	if(info.misalignsse == 1) printf("MISALIGNSSE ");
	if(info.threeD_now_prefetch == 1) printf("3DNOW!_PREFETCH ");
	if(info.osvw == 1) printf("OSVW ");
	if(info.ibs == 1) printf("IBS ");
	if(info.xop == 1) printf("XOP ");
	if(info.skinit == 1) printf("SKINIT ");
	if(info.wdt == 1) printf("WDT ");
	if(info.lwp == 1) printf("LWP ");
	if(info.fma4 == 1) printf("FMA4 ");
	if(info.tce == 1) printf("TCE ");
	if(info.nodeid_msr == 1) printf("NODEID_MSR ");
	if(info.tbm == 1) printf("TBM ");
	if(info.topoext == 1) printf("TOPOEXT ");
	if(info.perfctr_core == 1) printf("PERFCTR_CORE ");
	if(info.perfctr_nb == 1) printf("PERFCTR_NB ");
	if(info.dbx == 1) printf("DBX ");
	if(info.perftsc == 1) printf("PERFTSC ");
	if(info.pcx_l2i == 1) printf("PCX_L2 ");

	printf("\n");
}