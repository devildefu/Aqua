/*  ELF Documentation:
 *  http://www.skyfree.org/linux/references/ELF_Format.pdf
 * */

#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include "types.h"

#define EI_NIDENT 16

/*  ELF Header
 *  e_ident - the initial bytes mark the file as an object file and provide machine-independent data with which to decode and interpret the file’s contents
 *  
 *  e_type - identifies the object file type, e.g ET_EXEC - executable file
 *  
 *  e_machine - architecture for an individual file, Intel 80386 (architecture
 *  that interests me) is EM_386, value: 3
 *  
 *  e_version - identifies the object file version, EV_NONE is 0, EV_CURRENT is
 *  1, but will change to reflect the current version number.
 *
 *  e_entry - the virtual address where kirid has to give control, is zero if there is no entry point.
 *
 *  e_phoff - stores header table's file offset (in bytes), is zero if there is no program
 *  header table
 *
 *  e_shoff - stores section table's file offset (in bytes), is zero if there is
 *  no section header table
 *
 *  e_flags - processor-specific flags associated with the file.
 *
 *  e_ehsize - ELF header's size (in bytes)
 *
 *  e_phentsize - size (in bytes) of one entry in file's program header, all
 *  entries are the same size
 *
 *  e_phnum - number of entries in the program header table, is zero if a file
 *  has no program header table
 *
 *  e_shentsize - section header's size (in bytes), a section header in one
 *  entry in the section header table, all entries are the same size
 *
 *  e_shnum - number of entries in the section header table, is zero if a file
 *  has no program header table
 * */

typedef struct {
  unsigned char e_ident[EL_NIDENT];
  Elf32_Half    e_type;
  Elf32_Half    e_machine;
  Elf32_Word    e_version;
  Elf32_Addr    e_entry;
  Elf32_Off     e_phoff;
  Elf32_Off     e_shoff;
  Elf32_Word    e_flags;
  Elf32_Half    e_ehsize;
  Elf32_Half    e_phentsize;
  Elf32_Half    e_phnum;
  Elf32_Half    e_shentsize;
  Elf32_Half    e_shnum;
  Elf32_Half    e_shstrndx;
} __attribute__((packed)) Elf32_Ehdr;
/* Ehdr - Just shortcut of 'Elf Header' */

#endif
