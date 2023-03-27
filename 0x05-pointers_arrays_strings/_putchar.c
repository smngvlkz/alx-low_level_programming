#include <unistd.h>

/**
 * _putchar - writes the chaacter c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is et appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
