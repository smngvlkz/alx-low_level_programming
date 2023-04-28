#include <stdio.h>


/**
 * my_constructor - function that will be executed before main
 *
 * This function is marked with the '__attribute__ ((constructor))' attribute,
 * which means it will be executed before the main() function.
 * This can be useful for initializing data structures or running code
 * before the main program  begins.
 */

void my_constructor(void) __attribute__ ((constructor));

void my_constructor(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
