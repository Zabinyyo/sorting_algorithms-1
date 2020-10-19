#include "sort.h"
/**
 * pow_ - Find the result of 3^k ultin a gap is found
 * @base: Number 3 acording to the Knuth sequence
 * @power: Starts at 1 ultil condition met
 * Return: result of operation
 */
int pow_(int base, int power)
{
	while (power > 0)
	{
		base *= base;
		power--;
	}
	return (base);
}
/**
 * shell_sort - This algorithm uses insertion sort on a widely
 * spread elements, first to sort them and then sorts the less widely
 * spaced elements. This spacing is termed as interval. This interval
 * is calculated based on Knuth's formula as − h = h * 3 + 1
 * @array: Array of data to be sorted
 * @size: Size of the array
 */
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
