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
 * counting_digit - Sorts an array by one significant digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Significant digit
 * @output: Temporary output array
 */
static void counting_digit(int *array, size_t size, int exp, int *output)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array using LSD Radix sort
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max, exp;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_digit(array, size, exp, output);
		print_array(array, size);
	}

	free(output);
}
