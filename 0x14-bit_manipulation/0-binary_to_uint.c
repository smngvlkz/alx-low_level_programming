#include "main.h"
#include <stdlib.h>

/**
 * binary_to_uint - converts a binary numberr to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1 or b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int r;

	if (b == NULL)
		return (0);

	for (r = 0; b[r]; r++)
	{
		if (b[r] != '0' && b[r] != '1')
			return (0);
		num = (num << 1) | (b[r] - '0');
	}

	return (num);
}
