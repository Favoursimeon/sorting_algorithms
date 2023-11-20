#include "sort.h"

void switch_ints(int *a, int *b);
void maximum_heaping(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * maximum_heaping - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void maximum_heaping(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, big;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < base && array[left] > array[big])
		big = left;
	if (right < base && array[right] > array[big])
		big = right;

	if (big != root)
	{
		switch_ints(array + root, array + big);
		print_array(array, size);
		maximum_heaping(array, size, base, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each switch.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		maximum_heaping(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		switch_ints(array, array + i);
		print_array(array, size);
		maximum_heaping(array, size, i, 0);
	}
}
