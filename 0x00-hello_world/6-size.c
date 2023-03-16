#include <stdio.h>
/**
 *main - Entry point
 *
 *return: Always 0 (Success)
 */
int main(void)
{
	printf("Size of a char: %lu byte(s)\n", sizeof(char));
	printf("Size of an int: %lu bytes(s)\n", sizeof(int));
	printf("Size of a long int: %lu bytes(s)\n", sizeof(long int));
	printf("Size of a long long int: %lu bytes(s)\n", sizeof(long long int));
	printf("Size of a float: %lu  bytes(s)\n", sizeof(float));
	printf("The size of long long is %lu byte(s).\n", sizeof(long long));
        printf("The size of float is %lu byte(s).\n", sizeof(float));
        printf("The size of double is %lu byte(s).\n", sizeof(double));
        printf("The size of long double is %lu byte(s).\n", sizeof(long double));
        printf("The size of pointer is %lu byte(s).\n", sizeof(void*));
        return (0);
}
