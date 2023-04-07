#include "main.h"
#include <stdio.h>

/**
 * _strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int r = 0;

	while (*(src + i) != '\0')
	{
		i++;
	}
	for (r = 0; r < i; r++)
	{
		dest[r] = src[r];
	}
	dest[i] = '\0';
	return (dest);
}
