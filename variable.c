#include <stdio.h>

int main(void)
{
	int i;
	int j;

	i = 0;
	j = 2;
	while (i < 3)
	{
		printf("Valor de i = %d\n", i);
		j = j * 2;
		i++;
	}
	printf("Valor 2 Elevado a la 3 es = %d\n", j);
	return (0);
}
