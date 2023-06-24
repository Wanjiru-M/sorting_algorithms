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

    while (h != NULL)
    {
        len++;
        h = h->next;
    }

    return len;
}

/**
 * insertion_sort_list - sorts a linked list with the Insert Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *c = NULL, *o = NULL;
    listint_t *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;

    if (!list || !(*list) || len_list(*list) < 2)
        return;

    c = *list;

    while (c != NULL)
    {
        (void)(c->prev != NULL && c->n < c->prev->n) ? (
            t1 = c->prev->prev,
            t2 = c->prev,
            t3 = c,
            t4 = c->next,
            t2->next = t4,
            (t4 != NULL) ? (t4->prev = t2) : 0,
            t3->next = t2,
            t3->prev = t1,
            (t1 != NULL) ? (t1->next = t3) : (*list = t3),
            t2->prev = t3,
            c = *list,
            print_list(*list)
        ) : (
            c = c->next
        );
    }
}

