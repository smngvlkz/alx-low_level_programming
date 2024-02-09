#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * string_nconcat - concatenates two srings
 * @s1: frist string
 * @s2: second string
 * @n: number of bytes
 * Return: pointer to the string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int len1, len2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
	{
		n = len2;
	}

	s = malloc(sizeof(char) * (len1 + n + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	strcpy(s, s1);
	strncat(s, s2, n);
	return (s);
}
