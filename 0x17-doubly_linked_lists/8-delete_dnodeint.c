#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked
 * @head: double pointer
 * @index: index of the deleted node
 * Return: 1 if success, -1 if fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int count = 0;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	current = *head;
	while (current && count < index)
	{
		count++;
		current = current->next;
	}

	if (count != index || current == NULL)
	{
		return (-1);
	}

	if (current->prev)
	{
		current->prev->next = current->next;
	}
	else
	{
		*head = current->next;
	}

	if (current->next)
	{
		current->next->prev = current->prev;
	}

	free(current);

	return (1);
}
