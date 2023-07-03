#include "sort.h"

void swap_nodes(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Double pointer to the head of the doubly linked list
 * @tail: Double pointer to the tail of the doubly linked list
 * @shaker: Double pointer to the current swapping node
 */
void swap_nodes(listint_t **list, listint_t **tail, listint_t **shaker)
{
    listint_t *tmp_prev, *tmp_next;

    tmp_prev = (*shaker)->prev;
    tmp_next = (*shaker)->next;

    if (tmp_prev)
        tmp_prev->next = *shaker;
    else
        *list = *shaker;

    if (tmp_next)
        tmp_next->prev = *shaker;
    else
        *tail = *shaker;

    (*shaker)->prev = tmp_next;
    (*shaker)->next = tmp_prev;

    if (tmp_prev)
        tmp_prev->prev = *shaker;

    if (tmp_next)
        tmp_next->next = *shaker;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *shaker;
    int swapped;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    tail = NULL;
    swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (shaker = *list; shaker->next != tail; shaker = shaker->next)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_nodes(list, &tail, &shaker);
                print_list((const listint_t *)*list);
                swapped = 1;
            }
        }
        tail = shaker;

        if (!swapped)
            break;

        swapped = 0;
        for (shaker = shaker->prev; shaker != NULL; shaker = shaker->prev)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_nodes(list, &tail, &shaker->next);
                print_list((const listint_t *)*list);
                swapped = 1;
            }
        }
    }
}

