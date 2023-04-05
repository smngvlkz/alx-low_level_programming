#include "main.h"

/**
 * is_palindrome - check if a string is a palindrome
 * @s: string
 *
 * Return: 1 if string is palindrome or else 0
 */

int is_palindrome(char *s)
{
	int len = 0, i;

	while (*(s + len))
		len++;

	for (i = 0; i < len / 2; i++)
	{
		if (*(s + i) != *(s + len - i - 1))
			return (0);
	}
	return (1);
}
