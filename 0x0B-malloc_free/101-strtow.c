#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in string
 * @str: string input
 *
 * Return: Number of words in a string
 */

int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
	}

	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string input
 *
 * Return: pointer to an array of strings
 */

char **strtow(char *str)
{
	int i, r, n, len, words;
	char **equals;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_words(str);
	equals = malloc(sizeof(char *) * (words + 1));
	if (equals == NULL)
		return (NULL);

	for (i = 0; i < words; i++)
	{
		while (*str == ' ')
			str++;

		len = 0;
		while (*(str + len) != ' ' && *(str + len) != '\0')
			len++;

		equals[i] = malloc(sizeof(char) * (len + 1));
		if (equals[i] == NULL)
		{
			for (n = 0; n < i; n++)
				free(equals[n]);
			free(equals);
			return (NULL);
		}

		for (n = 0; n < len; n++)
			equals[i][n] = *(str++);
		equals[i][n] = '\0';
		r++;
	}

	equals[r] = NULL;
	return (equals);
}
