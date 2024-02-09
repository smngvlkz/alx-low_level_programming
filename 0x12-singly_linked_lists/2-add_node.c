#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new nod a the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be added to the new node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *y = malloc(sizeof(list_t));

	if (y == NULL)
		return (NULL);

	y->str = strdup(str);
	y->len = strlen(str);
	y->next = *head;
	*head = y;

	return (y);
}
