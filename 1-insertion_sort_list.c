#include "sort.h"

/**
 * len_list - returns the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *h)
{
    int len = 0;

    if (h == NULL)
        return len;

    do {
        len++;
        h = h->next;
    } while (h != NULL);

    return len;
}
