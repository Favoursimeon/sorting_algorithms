#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum type_e - Enumeration of cards suits.
 * @SPADE: Spades suit.
 * @HEART: Hearts suit.
 * @CLUB: Clubs suit.
 * @DIAMOND: Diamonds suit.
 */
typedef enum type_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} type_t;

/**
 * struct cards_s - Playing cards
 *
 * @value: Value of the cards
 * From "Ace" to "King"
 * @type: type of the cards
 */
typedef struct cards_s
{
	const char *value;
	const type_t type;
} cards_t;

/**
 * struct deck_node_s - Deck of cards
 */
typedef struct deck_node_s
{
	const cardss_t *cards;
	struct deck_node_s *initial;
	struct deck_node_s *upcoming;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
