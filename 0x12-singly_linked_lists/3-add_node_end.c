#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the head of the linked list
 * @str: string to be added to the linked list
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *last_node;
    char *new_str;
    size_t str_len;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    /* Duplicate the string */
    new_str = strdup(str);
    if (new_str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    /* Compute the length of the string */
    for (str_len = 0; str[str_len] != '\0'; str_len++)
        ;

    /* Initialize the new node */
    new_node->str = new_str;
    new_node->len = str_len;
    new_node->next = NULL;

    /* Handle the case where the linked list is empty */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    /* Find the last node in the linked list */
    last_node = *head;
    while (last_node->next != NULL)
        last_node = last_node->next;

    /* Add the new node to the end of the linked list */
    last_node->next = new_node;

    return (new_node);
}

