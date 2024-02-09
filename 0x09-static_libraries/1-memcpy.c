#include "main.h"
#include <stdio.h>

/**
 *_memcpy - function that copies memory area
 * @dest: memory where is stored
 * @src: memory where is copied
 * @n: number of bytes
 *
 * Return: copied memory with n byted changed
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = n;
	int j = 0;

	for (i = 0; j < i; i++)
	{
		dest[j] = src[j];
		n--;
	}
	return (dest);
}
