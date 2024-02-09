#include "main.h"

/**
 * _memcpy - function that copies memory area
 * @dest: where memory is stored
 * @src: where memory is copied
 * @n: bytes from memory area
 *
 * Return: pointer to where memory is stored
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}
