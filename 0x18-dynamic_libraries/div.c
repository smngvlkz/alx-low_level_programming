#include "operations.h"

/**
 * div - divides two integers
 * @a: the numerator
 * @b: the denominator
 *
 * Return: result of a / b, or an error if b is 0
 */
int div(int a, int b)
{
	if (b == 0)
	{
		return (-1);
	}
	return (a / b);
}
