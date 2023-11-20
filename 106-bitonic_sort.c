
#include "sort.h"

void switch_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char flow);
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * switch_ints - switch two integers in an array.
 * @a: The first integer to switch.
 * @b: The second integer to switch.
 */
void switch_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @sequence: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t sequence,
		char flow)
{
	size_t i, jump = sequence / 2;

	if (sequence > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				switch_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic seqence.
 * @sequence: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t sequence, char flow)
{
	size_t cut = sequence / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + start, sequence);

		bitonic_sequence(array, size, start, cut, UP);
		bitonic_sequence(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, sequence, flow);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + start, sequence);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * Description: Prints the array after each switch. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
