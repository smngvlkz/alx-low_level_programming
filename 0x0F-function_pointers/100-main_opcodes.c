#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 or 2 on error
 */

int main(int argc, char *argv[])
{
	int i, num_bytes;
	char *ptr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	ptr = (char *)main;
	for (i = 0; i < num_bytes; i++)
	{
		printf("%02hhx", ptr[i]);
		if (i < num_bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
