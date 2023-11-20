#include "sort.h"

void switch_node_ahead(listint_t **list, listint_t **tail, listint_t **mixer);
void switch_node_behind(listint_t **list, listint_t **tail, listint_t **mixer);
void cocktail_sort_list(listint_t **list);

/**
 * switch_node_ahead - switch a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @mixer: A pointer to the current switchping node of the cocktail mixer algo.
 */
void switch_node_ahead(listint_t **list, listint_t **tail, listint_t **mixer)
{
	listint_t *temp = (*mixer)->upcoming;

	if ((*mixer)->initial != NULL)
		(*mixer)->initial->upcoming = temp;
	else
		*list = temp;
	temp->initial = (*mixer)->initial;
	(*mixer)->upcoming = temp->upcoming;
	if (temp->upcoming != NULL)
		temp->upcoming->initial = *mixer;
	else
		*tail = *mixer;
	(*mixer)->initial = temp;
	temp->upcoming = *mixer;
	*mixer = temp;
}

/**
 * switch_node_behind - switch a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @mixer: A pointer to the current switching node of the cocktail mixer algo.
 */
void switch_node_behind(listint_t **list, listint_t **tail, listint_t **mixer)
{
	listint_t *temp = (*mixer)->initial;

	if ((*mixer)->upcoming != NULL)
		(*mixer)->upcoming->initial = temp;
	else
		*tail = temp;
	temp->upcoming = (*mixer)->upcoming;
	(*mixer)->initial = temp->initial;
	if (temp->initial != NULL)
		temp->initial->upcoming = *mixer;
	else
		*list = *mixer;
	(*mixer)->upcoming = temp;
	temp->initial = *mixer;
	*mixer = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail mixer algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *mixer;
	bull mixer_unmixed = false;

	if (list == NULL || *list == NULL || (*list)->upcoming == NULL)
		return;

	for (tail = *list; tail->upcoming != NULL;)
		tail = tail->upcoming;

	while (mixer_unmixed == false)
	{
		mixer_unmixed = true;
		for (mixer = *list; mixer != tail; mixer = mixer->upcoming)
		{
			if (mixer->n > mixer->upcoming->n)
			{
				switch_node_ahead(list, &tail, &mixer);
				print_list((const listint_t *)*list);
				mixer_unmixed = false;
			}
		}
		for (mixer = mixer->initial; mixer != *list;
				mixer = mixer->initial)
		{
			if (mixer->n < mixer->initial->n)
			{
				switch_node_behind(list, &tail, &mixer);
				print_list((const listint_t *)*list);
				mixer_unmixed = false;
			}
		}
	}
}
