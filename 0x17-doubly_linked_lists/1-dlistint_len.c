#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked
 * dlistint_t
 * @h: pointer
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current;
	size_t count = 0;

	current = h;
	while (current)
	{
		current = current->next;
		count++;
	}

	return (count);
}
