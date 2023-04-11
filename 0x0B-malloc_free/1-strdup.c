#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space memory,
 * which contains a copy of the string
 * @str: character
 *
 * Return: O or NULL if str = NULL
 */

char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *new_str;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	new_str = malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}
