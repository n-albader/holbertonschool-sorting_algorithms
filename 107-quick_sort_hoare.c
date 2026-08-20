#include "sort.h"

/**
 * swap_values - Swaps two integers
 * @array: Array being sorted
 * @a: First index
 * @b: Second index
 * @size: Size of the array
 */
static void swap_values(int *array, size_t a, size_t b, size_t size)
{
	int temp;

	if (a == b)
		return;

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
	long i;
	size_t j;

	pivot = array[high];
	i = (long)low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if ((size_t)i >= j)
			return (j);

		swap_values(array, (size_t)i, j, size);
	}
}

/**
 * quick_hoare - Recursively sorts an array using Hoare partition
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the full array
 */
static void quick_hoare(int *array, size_t low, size_t high, size_t size)
{
	size_t partition;

	if (low >= high)
		return;

	partition = hoare_partition(array, low, high, size);

	if (partition > low)
		quick_hoare(array, low, partition, size);

	quick_hoare(array, partition + 1, high, size);
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
