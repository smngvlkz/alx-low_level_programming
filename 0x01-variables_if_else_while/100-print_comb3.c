#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int m;

	for (n = 48; n <= 56; n++)
	{
		for (m = 49; m < 56; m++)
			{
				putchar(n);
				putchar(m);
				if (n != 56 || m != 57)
				{
				putchar(',');
				putchar(' ');
				}
			}
	}
	putchar('\n');
	return (0);
}

