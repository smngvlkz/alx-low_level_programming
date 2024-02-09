#include "main.h"
#include <stdio.h>


/**
 * _atoi - convert a string into an integer
 * @s: the string to use.
 *
 * Return: integer.
 */

int _atoi(char *s)
{
	int n = 1, l = 0;
	unsigned int r = 0;

	while (!(s[l] <= '9' && s[l] >= '0') && s[l] != '\0')
	{
		if (s[l] == '-')
			n *= -1;
		l++;
	}
	while (s[l] <= '9' && (s[l] >= '0' && s[l] != '\0'))
	{
		r = (r * 10) + (s[l] - '0');
		l++;
	}
	r *= n;

	return (r);
}
