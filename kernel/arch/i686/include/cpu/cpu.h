#ifndef CPU_H
#define CPU_H

/** Streaming SIMD Extensions 3 */
#define ECX_SSE3 (1 << 0)
/** PCLMULQDQ Instruction */
#define ECX_PCLMULQDQ (1 << 1)
/** 64-Bit Debug Store Area */
#define ECX_DTES64 (1 << 2)
/** MONITOR/MWAIT */
#define ECX_MONITOR (1 << 3)
/** CPL Qualified Debug Store */
#define ECX_DS_CPL (1 << 4)
/** Virtual Machine Extensions */
#define ECX_VMX (1 << 5)
/** Safer Mode Extensions */
#define ECX_SMX (1 << 6)
/** Enhanced SpeedStep Technology */
#define ECX_EST (1 << 7)
/** Thermal Monitor 2 */
#define ECX_TM2 (1 << 8)
/** Supplemental Streaming SIMD Extensions 3 */
#define ECX_SSSE3 (1 << 9)
/** L1 Context ID */
#define ECX_CNXT_ID (1 << 10)
/** Fused Multiply Add */
#define ECX_FMA (1 << 12)
/** CMPXCHG16B Instruction */
#define ECX_CX16 (1 << 13)
/** xTPR Update Control */
#define ECX_XTPR (1 << 14)
/** Perf/Debug Capability MSR */
#define ECX_PDCM (1 << 15)
/** Process-context Identifiers */
#define ECX_PCID (1 << 17)
/** Direct Cache Access */
#define ECX_DCA (1 << 18)
/** Streaming SIMD Extensions 4.1 */
#define ECX_SSE41 (1 << 19)
/** Streaming SIMD Extensions 4.2 */
#define ECX_SSE42 (1 << 20)
/** Extended xAPIC Support */
#define ECX_X2APIC (1 << 21)
/** MOVBE Instruction */
#define ECX_MOVBE (1 << 22)
/** POPCNT Instruction */
#define ECX_POPCNT (1 << 23)
/** Local APIC supports TSC Deadline */
#define ECX_TSC (1 << 24)
/** AESNI Instruction */
#define ECX_AESNI (1 << 25)
/** XSAVE/XSTOR States */
#define ECX_XSAVE (1 << 26)
/** OS Enabled Extended State Management */
#define ECX_OSXSAVE (1 << 27)
/** AVX Instructions */
#define ECX_AVX (1 << 28)
/** 16-bit Floating Point Instructions */
#define ECX_F16C (1 << 29)
/** RDRAND Instruction */
#define ECX_RDRAND (1 << 30)

/** Floating-Point Unit On-Chip */
#define EDX_FPU (1 << 0)
/** Virtual 8086 Mode Extensions */
#define EDX_VME (1 << 1)
/** Debugging Extensions */
#define EDX_DE (1 << 2)
/** Page Size Extension */
#define EDX_PSE (1 << 3)
/** Time Stamp Counter */
#define EDX_TSC (1 << 4)
/** Model Specific Registers */
#define EDX_MSR (1 << 5)
/** Physical Address Extension */
#define EDX_PAE (1 << 6)
/** Machine-Check Exception */
#define EDX_MCE (1 << 7)
/** CMPXCHG8 Instruction */
#define EDX_CX8 (1 << 8)
/** APIC On-Chip */
#define EDX_APIC (1 << 9)
/** SYSENTER/SYSEXIT instructions */
#define EDX_SEP (1 << 11)
/** Memory Type Range Registers */
#define EDX_MTRR (1 << 12)
/** Page Global Bit */
#define EDX_PGE (1 << 13)
/** Machine-Check Architecture */
#define EDX_MCA (1 << 14)
/** Conditional Move Instruction */
#define EDX_CMOV (1 << 15)
/** Page Attribute Table */
#define EDX_PAT (1 << 16)
/** 36-bit Page Size Extension */
#define EDX_PSE36 (1 << 17)
/** Processor Serial Number */
#define EDX_PSN (1 << 18)
/** CLFLUSH Instruction */
#define EDX_CLFLUSH (1 << 19)
/** Debug Store */
#define EDX_DS (1 << 21)
/** Thermal Monitor and Software Clock Facilities */
#define EDX_ACPI (1 << 22)
/** MMX Technology */
#define EDX_MMX (1 << 23)
/** FXSAVE and FXSTOR Instructions */
#define EDX_FXSR (1 << 24)
/** Streaming SIMD Extensions */
#define EDX_SSE (1 << 25)
/** Streaming SIMD Extensions 2 */
#define EDX_SSE2 (1 << 26)
/** Self Snoop */
#define EDX_SS (1 << 27)
/** Multi-Threading */
#define EDX_HTT (1 << 28)
/** Thermal Monitor */
#define EDX_TM (1 << 29)
/** Pending Break Enable */
#define EDX_PBE (1 << 31)

// ------------------------------------------------------------------------------------------------
// Extended Function 0x01

/** SYSCALL/SYSRET */
#define EDX_SYSCALL (1 << 11)
/** Multiprocessor Capable */
#define EDX_MP (1 << 19)
/** No Executable bit */
#define EDX_NX (1 << 20)
/** Extended MMX */
#define EDX_MMXEXT (1 << 22)
/** FXSAVE/FXRSTOR optimizations */
#define EDX_FXSR_OPT (1 << 25)
/** 1 GB Pages */
#define EDX_1GB_PAGE (1 << 26)
/** RDTSCP and IA32_TSC_AUX */
#define EDX_RDTSCP (1 << 27)
/** 64-bit Architecture */
#define EDX_64_BIT (1 << 29)
/** 3DNow! Technology */
#define EDX_3DNOW (1 << 31)
/** Extended 3DNow! */
#define EDX_3DNOWEXT (1 << 30)

/** LAHF/SAHF in long mode */
#define ECX_LAHF_LM (1 << 0)
/** Hyperthreading not valid */
#define ECX_CMP_LEGACY (1 << 1)
/** Secure Virtual Machine */
#define ECX_SVM (1 << 2)
/** Extended APIC space */
#define ECX_EXTAPIC (1 << 3)
/** CR8 in 32-bit mode */
#define ECX_CR8_LEGACY (1 << 4)
/** Advanced bit manipulation */
#define ECX_ABM (1 << 5)
/** SSE4a */
#define ECX_SSE4A (1 << 6)
/** Misaligned SSE mode */
#define ECX_MISALIGNSSE (1 << 7)
/** PREFETCH and PREFETCHW instructions */
#define ECX_3DNOW_PREFETCH (1 << 8)
/** OS Visible Workaround */
#define ECX_OSVW (1 << 9)
/** Instruction Based Sampling */
#define ECX_IBS (1 << 10)
/** XOP instruction set */
#define ECX_XOP (1 << 11)
/** SKINIT/STGI instructions */
#define ECX_SKINIT (1 << 12)
/** Watchdog timer */
#define ECX_WDT (1 << 13)
/** Light Weight Profiling */
#define ECX_LWP (1 << 15)
/** 4 operands fused multiply-add */
#define ECX_FMA4 (1 << 16)
/** Translation Cache Extension */
#define ECX_TCE (1 << 17)
/** NodeID MSR */
#define ECX_NODEID_MSR (1 << 19)
/** Trailing Bit Manipulation */
#define ECX_TBM (1 << 21)
/** Topology Extensions */
#define ECX_TOPOEXT (1 << 22)
/** Core performance counter extensions */
#define ECX_PERFCTR_CORE (1 << 23)
/** NB performance counter extensions */
#define ECX_PERFCTR_NB (1 << 24)
/** Data breakpoint extensions */
#define ECX_DBX (1 << 26)
/** Performance TSC */
#define ECX_PERFTSC (1 << 27)
/** L2I perf counter extension */
#define ECX_PCX_L2I (1 << 28)

#include <debug/debug.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/** Info about processor */
typedef struct {
	/* CPU basic informations */
	char vendor[14];
	char name[48];
	char architecture[5];
	/* CPU features */
	uint8_t sse3;
	uint8_t pclmulqdq;
	uint8_t dtes64;
	uint8_t monitor;
	uint8_t ds_cpl;
	uint8_t vmx;
	uint8_t smx;
	uint8_t est;
	uint8_t tm2;
	uint8_t ssse3;
	uint8_t cnxt_id;
	uint8_t fma;
	uint8_t cx16;
	uint8_t xtpr;
	uint8_t pdcm;
	uint8_t pcid;
	uint8_t dca;
	uint8_t sse4_1;
	uint8_t sse4_2;
	uint8_t x2apic;
	uint8_t movbe;
	uint8_t popcnt;
	uint8_t time_stamp_counter;
	uint8_t aesni;
	uint8_t xsave;
	uint8_t osxsave;
	uint8_t avx;
	uint8_t f16c;
	uint8_t rdrand;
	uint8_t fpu;
	uint8_t vme;
	uint8_t de;
	uint8_t pse;
	uint8_t local_apic_support;
	uint8_t msr;
	uint8_t pae;
	uint8_t mce;
	uint8_t cx8;
	uint8_t apic;
	uint8_t sep;
	uint8_t mtrr;
	uint8_t pge;
	uint8_t mca;
	uint8_t cmov;
	uint8_t pat;
	uint8_t pse36;
	uint8_t psn;
	uint8_t clflush;
	uint8_t ds;
	uint8_t acpi;
	uint8_t mmx;
	uint8_t fxsr;
	uint8_t sse;
	uint8_t sse2;
	uint8_t ss;
	uint8_t htt;
	uint8_t tm;
	uint8_t pbe;

	/* Extended functions */
	uint8_t syscall;
	uint8_t mp;
	uint8_t nx;
	uint8_t mmxext;
	uint8_t fxsr_opt;
	uint8_t pdpe1gb;
	uint8_t rdtscp;
	uint8_t threeD_now;
	uint8_t threeD_nowext;
	uint8_t lahf_lm;
	uint8_t cmp_legacy;
	uint8_t svm;
	uint8_t ext_apic;
	uint8_t cr8_legacy;
	uint8_t abm;
	uint8_t sse4a;
	uint8_t misalignsse;
	uint8_t threeD_now_prefetch;
	uint8_t osvw;
	uint8_t ibs;
	uint8_t xop;
	uint8_t skinit;
	uint8_t wdt;
	uint8_t lwp;
	uint8_t fma4;
	uint8_t tce;
	uint8_t nodeid_msr;
	uint8_t tbm;
	uint8_t topoext;
	uint8_t perfctr_core;
	uint8_t perfctr_nb;
	uint8_t dbx;
	uint8_t perftsc;
	uint8_t pcx_l2i;
} CPU_INFO;

/**
* Creates a CPU_INFO object with CPU information.
*
* @param ptr A CPU_INFO struct
*/
void cpu_info(CPU_INFO* ptr);

/** Prints info about CPU */
void cpu_print_info();

#endif
