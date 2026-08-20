#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays
 * @array: Array to merge
 * @buffer: Temporary buffer
 * @start: Start index
 * @mid: Middle index
 * @end: End index
 */
static void merge(int *array, int *buffer, size_t start,
	size_t mid, size_t end)
{
	size_t i = start, j = mid, k = start;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	while (i < mid && j < end)
	{
		if (array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}
	while (i < mid)
		buffer[k++] = array[i++];
	while (j < end)
		buffer[k++] = array[j++];

	for (i = start; i < end; i++)
		array[i] = buffer[i];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * split_merge - Recursively splits and merges an array
 * @array: Array to sort
 * @buffer: Temporary buffer
 * @start: Start index
 * @end: End index
 */
static void split_merge(int *array, int *buffer, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;

	mid = start + (end - start) / 2;
	split_merge(array, buffer, start, mid);
	split_merge(array, buffer, mid, end);
	merge(array, buffer, start, mid, end);
}

/**
 * merge_sort - Sorts an array using top-down Merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	split_merge(array, buffer, 0, size);
	free(buffer);
}
