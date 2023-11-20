#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bull - Enumeration of boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bull
{
	false = 0,
	true
} bull;

/**
 * struct listints_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @initial: Pointer to the initialious element of the list
 * @upcoming: Pointer to the upcoming element of the list
 */
typedef struct listints_s
{
	const int n;
	struct listints_s *initial;
	struct listints_s *upcoming;
} listint_t;

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
