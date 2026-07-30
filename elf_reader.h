#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>

const uint8_t* ELF_BASE; 
Elf64_Ehdr* ELF_HEADER64;
Elf64_Shdr* ELF_SHEADER64;
Elf64_Phdr* ELF_PHEADER64;

bool read_elf_file (FILE* file_path);
void delete_elf_header (uint8_t* ELF_BASE);

bool print_elf_header(Elf64_Ehdr* ELF_HEADER64);
bool print_elf_sheader(Elf64_Ehdr* ELF_SHEADER64, Elf64_Half num);
bool print_elf_pheader(Elf64_Ehdr* ELF_PHEADER64, Elf64_Half num);
