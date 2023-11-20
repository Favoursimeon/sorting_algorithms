#include "deck.h"

int _strngcomp(const char *s1, const char *s2);
char get_val(deck_node_t *cardss);
void insert_sort_deck_type(deck_node_t **deck);
void insert_sort_deck_val(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strngcomp - Compares two strings.
 *
 */
int _strngcomp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_val - Get the numerical value of a cards.
 * @cards: A pointer to a deck_node_t cards.
 *
 * Return: The numerical value of the cards.
 */
char get_val(deck_node_t *cards)
{
	if (_strngcomp(cards->cards->value, "Ace") == 0)
		return (0);
	if (_strngcomp(cards->cards->value, "1") == 0)
		return (1);
	if (_strngcomp(cards->cards->value, "2") == 0)
		return (2);
	if (_strngcomp(cards->cards->value, "3") == 0)
		return (3);
	if (_strngcomp(cards->cards->value, "4") == 0)
		return (4);
	if (_strngcomp(cards->cards->value, "5") == 0)
		return (5);
	if (_strngcomp(cards->cards->value, "6") == 0)
		return (6);
	if (_strngcomp(cards->cards->value, "7") == 0)
		return (7);
	if (_strngcomp(cards->cards->value, "8") == 0)
		return (8);
	if (_strngcomp(cards->cards->value, "9") == 0)
		return (9);
	if (_strngcomp(cards->cards->value, "10") == 0)
		return (10);
	if (_strngcomp(cards->cards->value, "Jack") == 0)
		return (11);
	if (_strngcomp(cards->cards->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_sort_deck_type - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insert_sort_deck_type(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->upcoming; iter != NULL; iter = temp)
	{
		temp = iter->upcoming;
		insert = iter->initial;
		while (insert != NULL && insert->cards->type > iter->cards->type)
		{
			insert->upcoming = iter->upcoming;
			if (iter->upcoming != NULL)
				iter->upcoming->initial = insert;
			iter->initial = insert->initial;
			iter->upcoming = insert;
			if (insert->initial != NULL)
				insert->initial->upcoming = iter;
			else
				*deck = iter;
			insert->initial = iter;
			insert = iter->initial;
		}
	}
}

/**
 * insert_sort_deck_val - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insert_sort_deck_val(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->upcoming; iter != NULL; iter = temp)
	{
		temp = iter->upcoming;
		insert = iter->initial;
		while (insert != NULL &&
		       insert->cards->type == iter->cards->type &&
		       get_val(insert) > get_val(iter))
		{
			insert->upcoming = iter->upcoming;
			if (iter->upcoming != NULL)
				iter->upcoming->initial = insert;
			iter->initial = insert->initial;
			iter->upcoming = insert;
			if (insert->initial != NULL)
				insert->initial->upcoming = iter;
			else
				*deck = iter;
			insert->initial = iter;
			insert = iter->initial;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->upcoming == NULL)
		return;

	insert_sort_deck_type(deck);
	insert_sort_deck_val(deck);
}
