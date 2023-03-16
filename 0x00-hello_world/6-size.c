#include <stdio.h>
/**
*main - print the string in the put function
*Return: 0
*/
int main(void)
{
printf("Size of char: %ld byte(s)\n", sizeof(char));
printf("Size of short: %ld byte(s)\n", sizeof(short));
printf("Size of int: %ld byte(s)\n", sizeof(int));
printf("Size of long: %ld byte(s)\n", sizeof(long));
printf("Size of long long: %ld byte(s)\n", sizeof(long long));
printf("Size of float: %ld byte(s)\n", sizeof(float));
printf("Size of double: %ld byte(s)\n", sizeof(double));
printf("Size of long double: %ld byte(s)\n", sizeof(long double));
printf("Size of void pointer: %ld byte(s)\n", sizeof(void *));
return (0);
}
