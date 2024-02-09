#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: Pointer to a newly allocated space or NULL if failure.
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int len1 = 0, len2 = 0, i = 0, r = 0;
	char *equals;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	equals = malloc((len1 + len2 + 1) * sizeof(char));

	if (equals == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
	{
		equals[i] = s1[i];
	}
	for (r = 0; s2[r]; r++)
	{
		equals[i + r] = s2[r];
	}

	equals[i + r] = '\0';

	return (equals);
}
