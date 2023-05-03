#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *start = head;
	listint_t *last = head;

	while (start != NULL && last != NULL && last->next != NULL)
	{
		start = start->next;
		last = last->next->next;

		if (start == last)
		{
			start = head;
			while (start != last)
			{
				start = start->next;
				last = last->next;
			}
			return (start);
		}
	}

	return (NULL);
}
