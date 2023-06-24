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
        switch (c->prev && c->n < c->prev->n)
        {
            case 1:
                o = c->prev->prev;
                t1 = c->prev;
                t2 = c;
                t3 = c->next;

                t1->next = t3;
                if (t3 != NULL)
                    t3->prev = t1;
                t2->next = t1;
                t2->prev = o;
                if (o != NULL)
                    o->next = t2;
                else
                    *list = t2;
                t1->prev = t2;
                c = *list;
                print_list(*list);
                break;

            default:
                c = c->next;
                break;
        }
    }
}

