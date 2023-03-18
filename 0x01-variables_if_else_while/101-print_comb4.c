#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, m, l;

	for (n = 0; n < 10; n++)
	{
		for (m = 1; m < 10; m++)
		{
			for (l = 2; l < 10; l++)
			{
				if (n < m && m < l)
				{
					putchar(n + '0');
					putchar(m + '0');
					putchar(l + '0');
					if (n + m + l <= 24)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}

