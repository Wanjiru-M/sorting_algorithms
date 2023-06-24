#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr, *prev, *next;

	curr = (*list)->next;

	while (curr != NULL)
	{
		prev = curr->prev;
		next = curr->next;

		while (prev != NULL && curr->n < prev->n)
		{
			swap_nodes(list, &prev, curr);
			print_list(*list);
			prev = curr->prev;
		}

		curr = next;
	}
}

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	if (*n1 == n2)
		return;

	if (n2->prev != NULL)
		n2->prev->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = n2->prev;

	if (*n1 != NULL)
		(*n1)->prev = n2;
	n2->next = *n1;
	n2->prev = (*n1)->prev;

	*n1 = n2;

	if (n2->prev != NULL)
		n2->prev->next = n2;
	else
		*h = n2;
}

