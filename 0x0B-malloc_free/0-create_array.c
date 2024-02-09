#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - creates an array of chars, and initializes it
 * with a specific char.
 * @size: array size
 * @c: character
 *
 * Return: pointer to the array, or NULL if size is 0.
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *r;

	if (size == 0)
		return (NULL);

	r = malloc(size * sizeof(char));

	if (r == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		r[i] = c;
	}
	return (r);
}
