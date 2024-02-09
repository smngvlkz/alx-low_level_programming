#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was freed
 */

size_t free_listint_safe(listint_t **h)
{
	size_t check = 0;
	listint_t *start;
	listint_t *last;
	listint_t **address_array;
	size_t i;

	if (h == NULL || *h == NULL)
		return (0);

	address_array = malloc(sizeof(listint_t *) * 1024);
	if (address_array == NULL)
		exit(98);

	start = *h;
	while (start != NULL)
	{
		for (i = 0; i < check; i++)
		{
			if (address_array[i] == start)
			{
				*h = NULL;
				free(address_array);
				return (check);
			}
		}

		address_array[check] = start;
		last = start;
		start = start->next;
		free(last);
		check++;
	}

	*h = NULL;
	free(address_array);
	return (check);
}
