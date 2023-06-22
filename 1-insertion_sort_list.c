#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using Insertion Sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *sorted, *prev;

	sorted = (*list)->next;
	while (sorted != NULL)
	{
		current = sorted;
		sorted = sorted->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			print_list(*list);
		}
	}
}
