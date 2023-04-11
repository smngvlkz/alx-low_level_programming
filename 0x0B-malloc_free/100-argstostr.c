#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Pointer to a new string, or NULL if is fails.
 */

char *argstostr(int ac, char **av)
{
	int i, r, len = 0, n = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (r = 0; av[i][r]; r++)
			len++;
		len++;
	}

	str = malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (r = 0; av[i][r]; r++)
		{
			str[n] = av[i][r];
			n++;
		}
		if (str[n] == '\0')
		{
			str[n++] = '\n';
		}
	}	
	return (str);
}
