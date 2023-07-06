#include "main.h"
#include <stdio.h>

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number for the bit
 * @index: index of the bit starting from 0
 *
 * Return: The value of the bit at index, or -1 if an error occures
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(n) * 8))
		return (-1);

	return ((n >> index) & 1);
}
