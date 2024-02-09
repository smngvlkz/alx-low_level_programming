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
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
	}
	return (count);
}
