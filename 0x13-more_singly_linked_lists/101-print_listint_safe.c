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
	const listint_t *last;

	while (start != NULL)
	{
		printf("[%p] %d\n", (void *)start, start->n);
		start = start->next;
		check++;

		last = head;
		while (last != start)
		{
			if (last == start->next)
			{
				printf("-> [%p] %d\n", (void *)start->next, start->next->n);
				return (check);
			}
			last = last->next;
		}
	}

	return (check);
}

