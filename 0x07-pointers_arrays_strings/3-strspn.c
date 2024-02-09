#include "main.h"
#include <stdio.h>

/**
 * _strspn - function that gets the length of a prefix substring
 * @s:substring
 * @accept: bytes
 *
 * Return: number of bytes in initial segment
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, n, check = 0;
	int value;

	for (i = 0; s[i]; i++)
	{
		value = 0;
		for (n = 0; accept[n]; n++)
		{
			if (s[i] == accept[n])
			{
				value = 1;
				check++;
				break;
			}
		}
		if (value == 0)
			return (check);
	}
	return (check);
}
