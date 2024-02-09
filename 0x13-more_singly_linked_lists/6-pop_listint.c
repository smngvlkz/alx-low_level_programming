#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: double pointer to the head of the list
 *
 * Return: the head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *last;
	int n;

	if (*head == NULL)
		return (0);

	last = *head;
	n = last->n;
	*head = last->next;
	free(last);

	return (n);
}
