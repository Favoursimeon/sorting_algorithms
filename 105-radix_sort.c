#include "sort.h"

int get_maximum_value(int *array, int size);
void radix_counts_sort(int *array, size_t size, int significant, int *buffa);
void radix_sort(int *array, size_t size);

/**
 *
 * Return: The maximum integer in the array.
 */
int get_maximum_value(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * radix_counts_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 */
void radix_counts_sort(int *array, size_t size, int significant, int *buffa)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / significant) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffa[count[(array[i] / significant) % 10] - 1] = array[i];
		count[(array[i] / significant) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffa[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, significant, *buffa;

	if (array == NULL || size < 2)
		return;

	buffa = malloc(sizeof(int) * size);
	if (buffa == NULL)
		return;

	maximum = get_maximum_value(array, size);
	for (significant = 1; maximum / significant > 0; significant *= 10)
	{
		radix_counts_sort(array, size, significant, buffa);
		print_array(array, size);
	}

	free(buffa);
}
