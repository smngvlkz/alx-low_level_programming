#include "main.h"
#include <stdio.h>

/**
 * _memset - memory of block
 * @s: address of memory
 * @b: value desired
 * @n: bytes
 *
 * Return: Always 0 (Success)
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
