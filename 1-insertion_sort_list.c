#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		prev = current->prev;

		while (prev && current->n < prev->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			print_list(*list);

			prev = current->prev;
		}

		current = next;
	}
}
