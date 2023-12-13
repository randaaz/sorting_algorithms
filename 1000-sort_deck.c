#include "deck.h"
#include <stdio.h>

/**
 * _cmp - Compare two strings.
 *
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: 1 if equal, 0 otherwise.
 */

int _cmp(const char *s1, char *s2)
{
	size_t j = 0;

	if (s1 == NULL)
		return (0);
	while (s1[j])
	{
		if (s1[j] != s2[j])
			return (0);
		j++;
	}
	if (s1[j] == '\0' && s2[j])
		return (0);
	return (1);
}

/**
 * _c_p - Calculate the numeric value of a card.
 *
 * @no: Pointer to a deck node.
 *
 * Return: Numeric value of the card.
 */

int _c_p(deck_node_t *no)
{
	int v;

	v = (*no).card->value[0] - '0';
	if (v < 50 || v > 57)
	{
		if (_cmp((*no).card->value, "Ace") == 1)
			v = 1;
		else if (_cmp((*no).card->value, "10") == 1)
			v = 10;
		else if (_cmp((*no).card->value, "Jack") == 1)
			v = 11;
		else if (_cmp((*no).card->value, "Queen") == 1)
			v = 12;
		else if (_cmp((*no).card->value, "King") == 1)
			v = 13;
	}
	v += (*no).card->kind * 13;
	return (v);
}

/**
 * sp_c - Swap a node with its previous node.
 *
 * @ca: Current node.
 * @d: Double pointer to the deck.
 *
 * Return: Pointer to the current node after the swap.
 */

deck_node_t *sp_c(deck_node_t *ca, deck_node_t **d)
{
	deck_node_t *b = ca->prev, *current = ca;

	b->next = current->next;
	if (current->next)
		current->next->prev = b;
	current->next = b;
	current->prev = b->prev;
	b->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*d = current;
	return (current);
}

/**
 * ins_sort - Perform insertion sort on a deck of cards.
 *
 * @d: Double pointer to the deck.
 */

void ins_sort(deck_node_t **d)
{
	int v_p, v_c;
	deck_node_t *no;

	if (d == NULL || (*d)->next == NULL)
		return;
	no = (*d)->next;
	while (no)
	{
		if (no->prev)
		{
			v_p = _c_p((no->prev));
			v_c = _c_p(no);
		}
		while ((no->prev) && (v_p > v_c))
		{
			v_p = _c_p((no->prev));
			v_c = _c_p(no);
			no = sp_c(no, d);

		}
		no = no->next;
	}
}

/**
 * sort_deck - Sort a deck of cards in ascending order using insertion sort.
 *
 * @deck: Double pointer to the deck.
 */

void sort_deck(deck_node_t **deck)
{
	ins_sort(deck);
}
