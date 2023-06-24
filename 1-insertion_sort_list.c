#include <stdio.h>
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

    listint_t *curr, *insert, *temp;

    curr = (*list)->next;
    while (curr != NULL)
    {
        insert = curr;
        temp = insert->prev;

        while (temp != NULL && temp->n > insert->n)
        {
            if (temp->prev != NULL)
                temp->prev->next = insert;
            else
                *list = insert;

            if (insert->next != NULL)
                insert->next->prev = temp;

            temp->next = insert->next;
            insert->prev = temp->prev;
            temp->prev = insert;
            insert->next = temp;

            print_list(*list);

            temp = insert->prev;
        }

        curr = curr->next;
    }
}

