#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes
 * @list: Pointer to the head of the list
 * @left: Left node
 * @right: Right node
 */
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	left->next = right->next;
	if (right->next != NULL)
		right->next->prev = left;

	right->prev = left->prev;
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	right->next = left;
	left->prev = right;
}

/**
 * forward_pass - Performs a forward pass
 * @list: Pointer to the head of the list
 * @end: End boundary
 * @swapped: Swap flag
 *
 * Return: Last node reached
 */
static listint_t *forward_pass(listint_t **list, listint_t *end, int *swapped)
{
	listint_t *current = *list;

	while (current->next != end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			print_list(*list);
			*swapped = 1;
		}
		else
			current = current->next;
	}
	return (current);
}

/**
 * backward_pass - Performs a backward pass
 * @list: Pointer to the head of the list
 * @current: Node to start from
 * @swapped: Swap flag
 */
static void backward_pass(listint_t **list, listint_t *current, int *swapped)
{
	while (current->prev != NULL)
	{
		if (current->prev->n > current->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
			*swapped = 1;
		}
		else
			current = current->prev;
	}
}

/**
 * cocktail_sort_list - Sorts a list using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *end = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		current = forward_pass(list, end, &swapped);
		if (swapped == 0)
			break;

		end = current;
		swapped = 0;
		backward_pass(list, current, &swapped);
	}
}
