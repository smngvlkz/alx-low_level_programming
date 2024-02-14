#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - displays the information contained in the ELF header at the start
 * of an ELF file
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 *
 * Return: 0 on success, 98 on error
 */

int main(int argc, char **argv)
{
	int r;
	ssize_t i;
	Elf64_Ehdr header;
	int j;

	if (argc !=2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filname\n", argv[0]);
		exit(98);
	}
	r = open(argv[1], O_RDONLY);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
	i = read(r, &header, sizeof(header));
	if (i != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
		exit(98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (j = 0; j < EI_NIDENT; j++)
		printf("%02x ", header.e_ident[j]);
	printf("\n");
	printf("  Class:                             ");
	printf("%s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              ");
	printf("%s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian"
: "2's complement, big endian");
	printf("  Version:                           %d ", header.e_ident[EI_VERSION]);
	printf("(current)\n");
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		default:
			printf("<unknown: %x>", header.e_ident[EI_OSABI]);
			break;
	}
	printf("\n");
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	printf("%s\n", header.e_type == ET_EXEC ? "EXEC (Executable file)" : "DYN (Shared object file)");
	printf("  Entry point address:               0x%lx\n", header.e_entry);

	close(r);
	return (0);
}

