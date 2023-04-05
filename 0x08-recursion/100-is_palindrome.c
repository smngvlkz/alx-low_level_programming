#include "main.h"

/**
 * is_palindrome - check if a string is a palindrome
 * @s: string
 *
 * Return: 1 if string is palindrome or else 0
 */

int is_palindrome(char *s)
{
	int len = 0, i = 0;

	while (*(s + len))
		len++;

	if (len <= 1)
		return (1);

	while (i < len / 2)
	{
		if (*(s + i) != *(s + len - i - 1))
			return (0);
		i++;
	}

	return (1);
}
