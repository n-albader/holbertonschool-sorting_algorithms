#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
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
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *end;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;

		end = current;
		swapped = 0;

		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
