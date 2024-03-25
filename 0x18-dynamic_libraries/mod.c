#include "operations.h"

/**
 * mod - calculates the remainder of the division of two integers
 * @a: the dividend
 * @b: the divisor
 *
 * Return: the remainder of a / b, or -1 if b is 0
 */
int mod(int a, int b)
{
	if (b == 0)
	{
		return (-1);
	}
	return (a % b);
}
