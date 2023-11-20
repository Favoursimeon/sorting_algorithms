#include "sort.h"

/**
 * switch_nodes - switch two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to switch.
 * @n2: The second node to switch.
 */
void switch_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->upcoming = n2->upcoming;
	if (n2->upcoming != NULL)
		n2->upcoming->initial = *n1;
	n2->initial = (*n1)->initial;
	n2->upcoming = *n1;
	if ((*n1)->initial != NULL)
		(*n1)->initial->upcoming = n2;
	else
		*h = n2;
	(*n1)->initial = n2;
	*n1 = n2->initial;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each switch.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->upcoming == NULL)
		return;

	for (iter = (*list)->upcoming; iter != NULL; iter = temp)
	{
		temp = iter->upcoming;
		insert = iter->initial;
		while (insert != NULL && iter->n < insert->n)
		{
			switch_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
