#include "elf_reader.h"
#include <stdio.h>



bool read_elf_file (FILE* file_path){
    if(!file_path) return false;

    struct stat fileInfo;
    fstat(fileno(file_path), &fileInfo);

    ELF_BASE = malloc(fileInfo.st_size);
    if(!ELF_BASE) return false;
    fread(ELF_BASE,fileInfo.st_size,1,file_path);
    fclose(file_path);

    ELF_HEADER64  = (Elf64_Ehdr*)ELF_BASE;
    ELF_SHEADER64 = (Elf64_Shdr*)(ELF_HEADER64 + ELF_HEADER64->e_shoff);
    ELF_PHEADER64 = (Elf64_Phdr*)(ELF_HEADER64 + ELF_HEADER64->e_phoff);

}
void delete_elf_file (uint8_t* ELF_BASE){
    if(!ELF_BASE) return NULL;
    free(ELF_BASE);
    return;
}

bool print_elf_header(Elf64_Ehdr* ELF_HEADER64){
    unsigned char magic = ELF_HEADER64->e_ident;

    char *class = NULL;
        if(ELF_HEADER64->e_ident[EI_CLASS] == ELFCLASS64)
            class = "ELF64";
        else if(ELF_HEADER64->e_ident[EI_CLASS] == ELFCLASS32)
            class = "ELF32";
        else{
            printf("the file is not a 64bit class");
            exit(1);
        }

    char *data = NULL;
        if(ELF_HEADER64->e_ident[EI_DATA] == ELFDATA2LSB)
            data = "Two's complement, little-endian.";
        else if (ELF_HEADER64->e_ident[EI_DATA] == ELFDATA2MSB)
            data = "Two's complement, big-endian.";
        else
            data = "Unknown data format.";
    
    char *os = NULL;
        switch (ELF_HEADER64->e_ident[EI_OSABI])
        {
        case ELFOSABI_SYSV:
            os = "UNIX System V ABI";
            break;
        case ELFOSABI_HPUX:
            os = "HP-UX ABI";
            break;
        case ELFOSABI_NETBSD:
            os = "NetBSD ABI";
            break;
        case ELFOSABI_LINUX:
            os = "Linux ABI";
            break;
        case ELFOSABI_SOLARIS:
            os = "Solaris ABI";
            break;
        case ELFOSABI_IRIX:
            os = "IRIX ABI";
            break;
        case ELFOSABI_FREEBSD:
            os = "FreeBSD ABI";
            break;;
        case ELFOSABI_TRU64:
            os = "TRU64 UNIX ABI";
            break;
        case ELFOSABI_ARM:
            os = "ARM architecture ABI";
            break;
        case ELFOSABI_STANDALONE:
            os = "Stand-alone (embedded) ABI";
            break;
    
    char *type = NULL;
        switch (ELF_HEADER64->e_type){
        case ET_NONE:
            type = "An unknown type.";
            break;
        case ET_REL:
            type = "A relocatable file.";
            break;
        case ET_EXEC:
            type = "An executable file.";
            break;
        case ET_DYN:
            type = "A shared object.";
            break;
        case ET_CORE:
            type = "A core file.";
            break;
        }
    
    char *machine = NULL;
        switch (ELF_HEADER64->e_machine){
        case EM_NONE:
        }

    unsigned int entry_point_address = ELF_HEADER64->e_entry;

    unsigned int start_of_sheaders  = ELF_HEADER64->e_shoff;
    unsigned int size_of_sheaders   = ELF_HEADER64->e_shentsize;
    unsigned int number_of_sheaders = ELF_HEADER64->e_shnum;

    unsigned int start_of_pheaders  = ELF_HEADER64->e_phoff;
    unsigned int size_of_Pheaders   = ELF_HEADER64->e_phentsize;
    unsigned int number_of_Pheaders = ELF_HEADER64->e_phnum;

    unsigned int section_strtab_index = ELF_HEADER64->e_shstrndx;

    printf("%s\n%s\n%s\n%s\n");
}
bool print_elf_sheader(Elf64_Ehdr* ELF_SHEADER64, Elf64_Half num){}
bool print_elf_pheader(Elf64_Ehdr* ELF_PHEADER64, Elf64_Half num){}