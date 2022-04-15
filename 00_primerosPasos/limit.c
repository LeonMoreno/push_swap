#include <stdio.h>
#include <limits.h>

int main(void)
{
	long int num;

	num = 2147483648;
	if (num > INT_MAX)
		printf("Max = %ld\n", num);
	return (0);
}
