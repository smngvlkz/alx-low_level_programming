#include "main.h"
#include <stdio.h>

/**
 * _strncat - concatenate two strings using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, b;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	b = 0;
	while (b < n && src[b] != '\0')
	{
		dest[i] = src[b];
		i++;
		b++;
	}
	dest[i] = '\0';

	return (dest);
}
