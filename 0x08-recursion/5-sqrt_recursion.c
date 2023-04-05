#include "main.h"

/**
 * _sqrt - helper function for _sqrt_recursion
 * @n: number of the square root
 * @i: iterator
 *
 * Return: square root of n, or -1 if n doesn't
 */

int _sqrt(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - recursively searches for the square root of a number
 * @n: the number to find the square root
 *
 * Return: the square root of n, or -1 if n doesn't have a natural square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_sqrt(n, 0));
}
