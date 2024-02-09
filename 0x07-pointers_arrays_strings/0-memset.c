#include "main.h"

/**
 * _memset - fils memory with a constant byte
 * @s: address of memory to be filled
 * @b: value desired
 * @n: bytes of the memory area pointed
 *
 * Return: pointer to the memory area
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
