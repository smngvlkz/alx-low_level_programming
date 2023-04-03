#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: starting address of memeory
 * @b: value
 * @n: bytes of the memory area pointed
 *
 * Return: a pointer to the memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
