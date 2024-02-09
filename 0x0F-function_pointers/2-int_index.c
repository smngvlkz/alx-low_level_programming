#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - searches for an integer
 * @size: seize of elements in array
 * @array: the array
 * @cmp: pointer to function
 * Return: Always 0.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
	}
	return (-1);
}
