#include "main.h"

/**
 * is_prime - checks if a number is a prime
 * @n: number to be checked
 * @d: divisor to check
 * Return: 1 if n is prime or just 0
 */

int is_prime(int n, int d)
{
	if (n <= 1)
		return (0);
	if (d == 1)
		return (1);
	if (n % d == 0)
		return (0);
	return (is_prime(n, d - 1));
}

/**
 * is_prime_number - recursively checks if number is a prime
 * @n: number to be checked
 *
 * Return: 1 if n is prime or else 0
 */

int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (is_prime(n, n - 2));
}
