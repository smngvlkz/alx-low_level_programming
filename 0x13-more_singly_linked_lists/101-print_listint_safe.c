#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the first node of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t check = 0;
	const listint_t *start = head;
	const listint_t **address_array;
	size_t i;

	address_array = malloc(sizeof(listint_t *) * 1024);
	if (address_array == NULL)
		exit(98);

	while (start != NULL)
	{
		for (i = 0; i < check; i++)
		{
			if (address_array[i] == start)
			{
				printf("-> [%p] %d\n", (void *)start, start->n);
				free(address_array);
				return (check);
			}
		}

		printf("[%p] %d\n", (void *)start, start->n);
		address_array[check] = start;
		start = start->next;
		check++;
	}

	free(address_array);
	return (check);
}

