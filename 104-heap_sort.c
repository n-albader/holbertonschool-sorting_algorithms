#include "sort.h"

/**
 * swap_values - Swaps two integers
 * @a: First integer
 * @b: Second integer
 * @array: Array being sorted
 * @size: Size of the array
 */
static void swap_values(int *a, int *b, int *array, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}

/**
 * sift_down - Restores the max heap property
 * @array: Array to sort
 * @size: Full size of the array
 * @root: Root index
 * @end: Heap boundary
 */
static void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t child, swap;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;

		swap_values(&array[root], &array[swap], array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array using sift-down Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (array == NULL || size < 2)
		return;

	start = (size - 2) / 2 + 1;
	while (start > 0)
	{
		start--;
		sift_down(array, size, start, size - 1);
	}

	end = size - 1;
	while (end > 0)
	{
		swap_values(&array[0], &array[end], array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
