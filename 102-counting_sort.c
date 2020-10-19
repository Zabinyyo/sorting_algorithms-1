#include "sort.h"
void counting_sort(int *array, size_t size)
{
	size_t i = 1, index = 0;
	int max_ = array[0], *buffer = NULL, *copy;

	if (size < 2)
		return;
	while (i < size)
	{
		if (max_ < array[i])
			max_ = array[i];
		i++;
	}
	buffer = malloc(sizeof(int) * (++max_));
	i = 0;
	while (i < max_)
		buffer[i] = '\0', i++;
	i = 0;
	while (i < size)
		buffer[array[i]]++, i++;
	i = 1;
	while (i < max_)
		buffer[i] = buffer[i] + buffer[i - 1], i++;
	print_array(buffer, max_);
	i = 0;
	copy = malloc(sizeof(int) * size);
	while (i < size)
	{
		index = --buffer[array[i]];
		copy[index] = array[i];
		i++;
	}
	i = 0;
	while (i < size)
		array[i] = copy[i], i++;

	free(copy);
	free(buffer);
}
