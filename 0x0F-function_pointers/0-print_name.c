#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - prints a name using pointer to function
 * @name: name of a person
 * @f: pointer
 *
 * Return: Nothing.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
