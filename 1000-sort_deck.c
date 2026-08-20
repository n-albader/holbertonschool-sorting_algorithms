#include <string.h>
#include "deck.h"

/**
 * card_value - Gets the numeric rank of a card
 * @value: Card value
 *
 * Return: Numeric rank
 */
static int card_value(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
	};
	int i;

	for (i = 0; i < 13; i++)
		if (strcmp(value, values[i]) == 0)
			return (i);

	return (0);
}

/**
 * card_before - Checks the order of two cards
 * @a: First card
 * @b: Second card
 *
 * Return: 1 if a should come before b, otherwise 0
 */
static int card_before(const card_t *a, const card_t *b)
{
	if (a->kind < b->kind)
		return (1);

	if (a->kind > b->kind)
		return (0);

	return (card_value(a->value) < card_value(b->value));
}

/**
 * swap_nodes - Swaps two adjacent deck nodes
 * @deck: Pointer to the head of the deck
 * @left: Left node
 * @right: Right node
 */
static void swap_nodes(deck_node_t **deck, deck_node_t *left,
	deck_node_t *right)
{
	left->next = right->next;
	if (right->next != NULL)
		right->next->prev = left;

	right->prev = left->prev;
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*deck = right;

	right->next = left;
	left->prev = right;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next;

	if (deck == NULL || *deck == NULL)
		return;

	current = (*deck)->next;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL &&
			card_before(current->card, current->prev->card))
			swap_nodes(deck, current->prev, current);

		current = next;
	}
}
