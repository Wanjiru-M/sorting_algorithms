#include "sort.h"

/**
 * len_list - calculates the length of a linked list
 * @h: A pointer to the head of the linked list
 *
 * Return: The length of the linked list
 */
int len_list(listint_t *h)
{
	int len = 0;

	if (h == NULL)
		return (len);

	do {
		len++;
		h = h->next;
	} while (h != NULL);

	return (len);
}


/**
 * insertion_sort_list - implements the Insertion Sort algorithm
 * @list: Double pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	curr = *list;

	while (curr != NULL)
	{
		switch (curr->prev && curr->n < curr->prev->n)
		{
			case 1:
				one = curr->prev->prev;
				two = curr->prev;
				three = curr;
				four = curr->next;

				two->next = four;
				if (four != NULL)
					four->prev = two;
				three->next = two;
				three->prev = one;
				if (one != NULL)
					one->next = three;
				else
					*list = three;
				two->prev = three;
				curr = *list;
				print_list(*list);
				break;

			default:
				curr = curr->next;
				break;
		}
	}
}

