#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if success, -1 if it fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *check;
	listint_t *last;
	unsigned int r;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		last = (*head)->next;
		free(*head);
		*head = last;
		return (1);
	}

	check = *head;
	for (r = 0; r < index - 1 && check != NULL; r++)
		check = check->next;

	if (check == NULL || check->next == NULL)
		return (-1);

	last = check->next->next;
	free(check->next);
	check->next = last;

	return (1);
}
