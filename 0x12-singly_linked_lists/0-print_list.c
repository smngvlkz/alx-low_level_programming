#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the head of the list
 *
 * Return: the nymber of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	for (; h; h = h->next, count++)
	{
		printf("[%d] %s\n", h->len, h->str ? h->str : "(nil)");
	}

	return (count);
}
