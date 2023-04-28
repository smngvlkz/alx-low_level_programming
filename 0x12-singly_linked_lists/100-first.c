#include <stdio.h>

/**
 * marked with the attribute
 * sentence will be executed before the main function
 */

void __attribute__ ((constructor)) premain()
{
	printf("You're beat! and yet, you must allow,\n"\n);
	printf("I bore my house upon my back!\n");
}
