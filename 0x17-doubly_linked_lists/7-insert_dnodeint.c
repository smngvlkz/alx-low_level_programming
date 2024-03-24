#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to head of list
 * @idx: index of the list where the new node should be added
 * @n: data to insert in new node
 * Return: address of new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current;
	unsigned int count = 0;

	if (h == NULL)
	{
		return (NULL);
	}

	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}

	current = *h;
	while (current && count < idx)
	{
		count++;
		if (count == idx)
		{
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
			{
				return (NULL);
			}
			new_node->n = n;
			new_node->prev = current;
			new_node->next = current->next;
			if (current->next)
			{
				current->next->prev = new_node;
			}
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
	}

	if (count == idx)
	{
		return (add_dnodeint_end(h, n));
	}

	return (NULL);
}
