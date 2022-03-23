#include <stdio.h>

void printarr(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
		i++;
	}
}

void swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/* 	Con esta version de Bubble sort, pocisionando el indice siempre a CERO,
	en un Array de 5 numeros, entraria 24 veces el ciclo While*/
/*void bubleSort(int *arr, int len)
{
	int i;
	int tmp;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(&arr[i], &arr[i +1]);
			i = 0;
		}
		else
			i++;
		j++;
	}
	printf ("Entro %d veces\n", j);
}*/

/* 	Con esta version de Bubble sort:
	1 - len - 1
	2 - Hacinedo 2 while
	en un Array de 5 numeros, entraria 14 veces sumando los dos ciclos While*/
void bubleSort(int *arr, int len)
{
	int i;
	int j;
	int repe;
	int	k;

	i = 0;
	repe = 0;

	while (i < len - 1)
	{
		if (k == 0)
			break;
		j = 0;
		k = 0;
		while (j < (len - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j +1]);
				k++;
			}
			j++;
			repe++;
		}
		i++;
	}
	printf ("Entro %d veces y i entro %d\n", repe, i);
}

int main(void)
{
	int arr[] = {7, 43, 9, 32, 2};
	int len;

	len = sizeof(arr) / sizeof(arr[0]);
	printf("Num len = %d\n", len);
	printarr(arr, len);
	bubleSort(arr, len);
	printf("Despues BubleSort\n");
	printarr(arr, len);
}
