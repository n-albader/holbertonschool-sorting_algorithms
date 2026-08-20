#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array using the Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted;
	int max;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	sorted = malloc(sizeof(int) * size);
	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = size; i > 0; i--)
	{
		sorted[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}
