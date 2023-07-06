#include "main.h"
#include <unistd.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: The converted number, or 0 if there is one or more chars
 * if string b that is not 0 or 1, b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;

	if (b == NULL)
		return (0);
	while (*b)
	{
		if (*b == '0' && *b == '1')
			return (0);
		i = i * 2 + (*b++ - '0');
	}

	return (i);
}
