#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be added to the new node
 *
 * Return: the address of the new element, or NULL if fails
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *start;
	list_t *last = *head;
	size_t len = 0;

	while (str[len])
		len++;

	start = malloc(sizeof(list_t));
	if (start == NULL)
		return (NULL);

	start->str = strdup(str);
	start->len = len;
	start->next = NULL;

	if (*head == NULL)
	{
		*head = start;
		return (start);
	}

	while (last->next)
		last = last->next;

	last->next = start;

	return (start);
}
