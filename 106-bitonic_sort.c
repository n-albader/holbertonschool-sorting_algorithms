#include <stdio.h>
#include "sort.h"

/**
 * bitonic_merge - Merges a bitonic sequence
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Sorting direction
 */
static void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t i, half;
	int temp;

	if (count < 2)
		return;

	half = count / 2;
	for (i = low; i < low + half; i++)
	{
		if ((dir && array[i] > array[i + half]) ||
		    (!dir && array[i] < array[i + half]))
		{
			temp = array[i];
			array[i] = array[i + half];
			array[i + half] = temp;
		}
	}

	bitonic_merge(array, low, half, dir);
	bitonic_merge(array, low + half, half, dir);
}

/**
 * bitonic_sequence - Builds and sorts a bitonic sequence
 * @array: Array to sort
 * @low: Starting index
 * @count: Number of elements
 * @dir: Sorting direction
 * @size: Total size of the array
 */
static void bitonic_sequence(int *array, size_t low, size_t count,
	int dir, size_t size)
{
	size_t half;

	if (count < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", count, size,
		dir ? "UP" : "DOWN");
	print_array(array + low, count);

	half = count / 2;
	bitonic_sequence(array, low, half, 1, size);
	bitonic_sequence(array, low + half, half, 0, size);

	bitonic_merge(array, low, count, dir);

	printf("Result [%lu/%lu] (%s):\n", count, size,
		dir ? "UP" : "DOWN");
	print_array(array + low, count);
}

/**
 * bitonic_sort - Sorts an array using Bitonic sort
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, 0, size, 1, size);
}
