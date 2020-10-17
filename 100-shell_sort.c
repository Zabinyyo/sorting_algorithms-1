#include "sort.h"

int pow_(int base, int power)
{
	while (power > 0)
	{
		base *= base;
		power--;
	}
	return (base);
}

void shell_sort(int *array, size_t size)
{
	size_t k = 1, gap = 0, i = 0, j = 0;
	int tmp = 0;

	if (size < 2)
		return;
	gap = (pow_(3, k) - 1) / 2;
	while (gap < size / 3)
	{
		k++;
		gap = (pow_(3, k) - 1) / 2;
	}
	while (gap > 0)
	{
		j = gap;
		while (j < size)
		{
			tmp = array[j];
			i = j;
			while (i > gap - 1 && array[i - gap] >= tmp)
			{
				array[i] = array[i - gap];
				i -= gap;
			}
			array[i] = tmp;
			j++;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
