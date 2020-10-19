#include "sort.h"
/**
 * bubble_sort - Used to sort a given set of n elements
 * provided in form of an array with n number of elements.
 * Bubble Sort compares all the element one by one and sort
 * them based on their values.
 * @array: Array of data to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int i = 0, j = 0, sorted = 1, tmp = 0;

	if (size < 2)
		return;
	j = size;
	while (sorted == 1 && j > 0)
	{
		sorted = 0;
		i = 1;
		while (i <= j)
		{
			if (array[i - 1] > array[i] && array[i] != '\0')
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				sorted = 1;
			}
			i += 1;
		}
		j -= 1;
	}
}
