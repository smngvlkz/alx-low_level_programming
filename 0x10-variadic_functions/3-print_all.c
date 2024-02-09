#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - function that prints anything.
 * @format: list of types of arguments passed to the function
 *
 * Return: Always 0.
 */

void print_all(const char * const format, ...)
{
	va_list args;
	char *str;
	int i = 0;
	char c;
	float f;

	va_start(args, format);
	while (format[i])
	{
		switch (format[i])
		{
			case 'c':
				c = va_arg(args, int);
				printf("%c", c);
				break;
			case 'i':
				i = va_arg(args, int);
				printf("%d", i);
				break;
			case 'f':
				f = va_arg(args, double);
				printf("%f", f);
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
		}
		i++;
	}
	va_end(args);
}
