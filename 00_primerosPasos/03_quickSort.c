#include <stdio.h>
#include <unistd.h>

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

int partir (int *arr, int i_min, int i_max)
{
	int pivo;
	int j;
	int i;

	i = i_min;
	pivo = arr[i_max];
	printf("Pivo = %d\n", pivo);
	sleep(5);
	j = i_min - 1;
	while (i <= i_max - 1)
	{
		if (arr[i] < pivo)
			{
				j++;
				swap(&arr[j], &arr[i]);
			}
		i++;
	}
	swap(&arr[i_max], &arr[j + 1]);
	return (j + 1);
}

void quickSort (int *arr, int i_min, int i_max)
{
	int pa;

	if (i_min < i_max)
	{
		pa = partir(arr, i_min, i_max);

		quickSort (arr, i_min, pa - 1);
		quickSort (arr, pa + 1, i_max);
	}
}

int main(void)
{
	int arr[] = {9, 43, 2, 7, 32};
	int len;

	len = sizeof(arr) / sizeof(arr[0]);
	printf("Num len = %d\n", len);
	printarr(arr, len);
	quickSort(arr, 0, len - 1);
	printf("Despues BubleSort\n");
	printarr(arr, len);
}
