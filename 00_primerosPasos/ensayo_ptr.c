#include <stdio.h>

void ft_f(int **p)
{
	int b;

	*p = &b;
	**p = 8;
}

int main(void)
{
	int num;
	int *ptr;

	num = 5;
	ptr = &num;
	printf("num = %d\n", num);
	printf("ptr = %p\n", ptr);
	ft_f(&ptr);
	printf("num = %d\n", num);
	printf("ptr = %p\n", ptr);
}
