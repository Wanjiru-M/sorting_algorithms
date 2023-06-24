#include "sort.h"

/**
 * swapNodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @nodeA: A pointer to the first node to swap.
 * @nodeB: The second node to swap.
 */
void swapNodes(listint_t **head, listint_t **nodeA, listint_t *nodeB)
{
    listint_t *temp = *nodeA;
    
    do {
        temp->next = nodeB->next;
        if (nodeB->next != NULL)
            nodeB->next->prev = temp;
        nodeB->prev = temp->prev;
        nodeB->next = temp;
        if (temp->prev != NULL)
            temp->prev->next = nodeB;
        else
            *head = nodeB;
        temp->prev = nodeB;
        *nodeA = nodeB->prev;
    } while (0);
}

/**
 * insertionSortList - Sorts a doubly linked list of integers
 *                     using the insertion sort algorithm.
 * @head: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertionSortList(listint_t **head)
{
    listint_t *current, *insert, *tmp;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return;

    current = (*head)->next;
    while (current != NULL)
    {
        tmp = current->next;
        insert = current->prev;
        while (insert != NULL && current->n < insert->n)
        {
            swapNodes(head, &insert, current);
            printList((const listint_t *)*head);
            insert = current->prev;
        }
        current = tmp;
    }
}

