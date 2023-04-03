#include "main.h"
#include <stddef.h>

/**
 * _strstr - function that locates a substring
 * @needle: substring
 * @haystack: string
 * Return: Always 0 (Success)
 */

char *_strstr(char *haystack, char *needle)
{
	int i, n;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (*needle == '\0')
		{
			return (haystack);
		}
		if (haystack[i] == needle[0])
		{
			for (n = 0; needle[n] != '\0'; n++)
			{
				if (haystack[i + n] != needle[n])
					break;
			}
			if (needle[n] == '\0')
			{
				return (&haystack[i]);
			}
		}
	}

	return (NULL);
}
