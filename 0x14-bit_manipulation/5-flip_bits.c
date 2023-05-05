#include "main.h"

/**
 * flip_bits - returns the number of bits youwould need to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int check = 0;

	for (check = 0; xor; check++)
		xor &= (xor - 1);

	return (check);
}
