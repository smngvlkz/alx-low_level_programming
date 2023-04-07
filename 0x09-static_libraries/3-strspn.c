#include "main.h"
#include <stdio.h>

/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
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
