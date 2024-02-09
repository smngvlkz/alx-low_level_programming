#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_number - checks if a string contains only digits
 * @str: the string to check
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int is_number(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of command-line arguments
 * @argv: the command-line arguments
 *
 * Return: 0 if successful, 98 otherwise
 */
int main(int argc, char *argv[])
{
	long num1, num2;

	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
	{
		printf("Error\n");
		return (98);
	}

	num1 = atol(argv[1]);
	num2 = atol(argv[2]);

	printf("%ld\n", num1 * num2);

	return (0);
}
