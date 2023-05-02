#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Pointer to a pointer to the first node of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Data for the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp_node;
    unsigned int i;

    if (head == NULL)
        return (NULL);

    if (idx == 0)
        return (add_nodeint(head, n));

    temp_node = *head;
    for (i = 0; i < idx - 1 && temp_node != NULL; i++)
        temp_node = temp_node->next;

    if (temp_node == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = temp_node->next;
    temp_node->next = new_node;

    return (new_node);
}

