#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list safely
 * @h: a pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *temp;

	while (*h != NULL)
	{
		if (*h <= (*h)->next)
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
		temp = (*h)->next;
		free(*h);
		*h = temp;
		count++;
	}
	return (count);
}

