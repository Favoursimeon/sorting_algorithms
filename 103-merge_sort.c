#include "sort.h"

void merge_subArraysays(int *subArrays, int *buffa, size_t front, size_t middledle,
		size_t back);
void merge_sort_recursive(int *subArrays, int *buffa, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subArraysays - Sort a subArraysay of integers.
 * @subArrays: A subArraysay of an array of integers to sort.
 * @buffa: A buffer to store the sorted subArraysay.
 * @front: The front index of the array.
 * @middledle: The middledledle index of the array.
 * @back: The back index of the array.
 */
void merge_subArraysays(int *subArrays, int *buffa, size_t front, size_t middledle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subArrays + front, middledle - front);

	printf("[right]: ");
	print_array(subArrays + middledle, back - middledle);

	for (i = front, j = middledle; i < middledle && j < back; k++)
		buffa[k] = (subArrays[i] < subArrays[j]) ? subArrays[i++] : subArrays[j++];
	for (; i < middledle; i++)
		buffa[k++] = subArrays[i];
	for (; j < back; j++)
		buffa[k++] = subArrays[j];
	for (i = front, k = 0; i < back; i++)
		subArrays[i] = buffa[k++];

	printf("[Done]: ");
	print_array(subArrays + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 *
 */
void merge_sort_recursive(int *subArrays, int *buffa, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subArrays, buffa, front, middle);
		merge_sort_recursive(subArrays, buffa, middle, back);
		merge_subArraysays(subArrays, buffa, front, middle, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffa;

	if (array == NULL || size < 2)
		return;

	buffa = malloc(sizeof(int) * size);
	if (buffa == NULL)
		return;

	merge_sort_recursive(array, buffa, 0, size);

	free(buffa);
}
