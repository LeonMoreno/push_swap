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

/*	El objetivo de este algoritmo es encontrar el numero minimo del arr
	Guarda en min_idx la posicion del numero menor del arr
	El while interno arranca desde la posicion i. 
	Y hace swap, de los indices i y min_idx
	No de iteracion 14 while interno -- 4 while externo
*/
void selectionSort(int *arr, int len)
{
	int i;
	int j;
	int min_index;
	int	repe;

	i = 0;
	repe = 0;

	while (i < len - 1)
	{
		j = i;
		min_index = i;
		while (j < len)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
			j++;
			repe++;
		}
		swap(&arr[i], &arr[min_index]);
		i++;
	}
	printf ("Entro %d veces y i entro %d\n", repe, i);
}

int main(void)
{
	int arr[] = {9, 43, 2, 7, 32};
	int len;

	len = sizeof(arr) / sizeof(arr[0]);
	printf("Num len = %d\n", len);
	printarr(arr, len);
	selectionSort(arr, len);
	printf("Despues SelectionSort\n");
	printarr(arr, len);
}
