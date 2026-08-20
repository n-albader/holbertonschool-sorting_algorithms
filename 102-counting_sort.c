#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Finds the largest value in an array
 * @array: Array to inspect
 * @size: Size of the array
 *
 * Return: Largest value
 */
static int get_max(const int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * build_count - Builds the cumulative counting array
 * @array: Array to count
 * @size: Size of the array
 * @count: Counting array
 * @max: Largest value in array
 */
static void build_count(int *array, size_t size, int *count, int max)
{
	size_t i;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];
}

/**
 * counting_sort - Sorts an array using Counting sort
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

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	sorted = malloc(sizeof(int) * size);
	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}

	build_count(array, size, count, max);
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
