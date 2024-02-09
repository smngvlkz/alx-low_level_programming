#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number to set the bit
 * @index: index of the bit to set starting from 0
 *
 * Return: 1 if its correct, or -1 if an error occures
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(*n) * 8))
		return (-1);

	*n |= (1UL << index);

	return (1);
}
