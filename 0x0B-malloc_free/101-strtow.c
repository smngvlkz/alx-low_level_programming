#include "main.h"
#include <stdlib.h>


/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */

int count_word(char *s)
{
	int len, i, r;

	len = 0;
	r = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			len = 0;
		else if (len == 0)
		{
			len = 1;
			r++;
		}
	}

	return (r);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 */

char **strtow(char *str)
{
	char **equals, *results;
	int i, n = 0, count = 0, words, b = 0, start, end;

	while (*(str + count))
		count++;
	words = count_word(str);
	if (words == 0)
		return (NULL);
	equals = malloc(sizeof(char *) * (words + 1));
	if (equals == NULL)
		return (NULL);

	for (i = 0; i <= count; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (b)
			{
				end = i;
				results = malloc(sizeof(char) * (b + 1));
				if (results == NULL)
					return (NULL);
				while (start < end)
					*results = str[start++];
				*results = '\0';
				equals[n] = results - b;
				n++;
				b = 0;
			}
		}
		else if (b++ == 0)
			start = i;
	}
	equals[b] = NULL;

	return (equals);
}
