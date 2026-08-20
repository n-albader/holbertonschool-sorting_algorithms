#include "sort.h"

/**
 * swap_values - Swaps two values in an array
 * @array: Array being sorted
 * @a: First index
 * @b: Second index
 * @size: Size of the array
 */
static void swap_values(int *array, size_t a, size_t b, size_t size)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
	print_array(array, size);
}

/**
 * hoare_partition - Partitions an array using Hoare scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the full array
 *
 * Return: Partition index
 */
static size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	long i, j;

	pivot = array[high];
	i = (long)low - 1;
	j = (long)high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return ((size_t)i);

		swap_values(array, (size_t)i, (size_t)j, size);
	}
}

/**
 * quick_hoare - Recursively sorts using Hoare partition
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the full array
 */
static void quick_hoare(int *array, size_t low, size_t high, size_t size)
{
	size_t p;

	if (low >= high)
		return;

	p = hoare_partition(array, low, high, size);

	if (p > 0)
		quick_hoare(array, low, p - 1, size);
	quick_hoare(array, p, high, size);
}

/**
 * quick_sort_hoare - Sorts an array using Hoare Quick sort
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_hoare(array, 0, size - 1, size);
}
