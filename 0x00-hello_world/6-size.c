#include <stdio.h>
/**
 *You should produce the exact same output as in the example
 *Warnings are allowed
 *
 *return: Always 0 (Success)
 */
int main(void)
{
	char c;
	int i;
	long int li;
	long long lli;
	float f;

	printf("size of a char: %ld byte(s)\n", sizeof(c));
	printf("size of an int: %ld bytes(s)\n", sizeof(i));
	printf("size of a long int: %ld bytes(s)\n", sizeof(li));
	printf("size of a long long int: %ld bytes(s)\n", sizeof(lli));
        printf("size of float is %ld byte(s).\n", sizeof(f));
        return (0);
}
