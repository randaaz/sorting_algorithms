#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Represents the suits of a
 * standard deck of playing cards.
 * @SPADE: Spade suit.
 * @HEART: Heart suit.
 * @CLUB: Club suit.
 * @DIAMOND: Diamond suit.
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents an
 * individual playing card.
 * @value: Pointer to a string representing the
 * value of the card (e.g., "2", "K", "Ace").
 * @kind: The suit of the card, represented by a
 * kind_t enumerator (SPADE, HEART, CLUB, DIAMOND).
 *
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a
 * doubly-linked list for a deck of playing cards.
 * @card: Pointer to a card_t structure representing
 * an individual playing card.
 * @prev: Pointer to the previous deck_node_t
 * in the doubly-linked list.
 * @next: Pointer to the next deck_node_t
 * in the doubly-linked list.
 *
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
#endif
