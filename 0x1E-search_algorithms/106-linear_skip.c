#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev;

	if (list == NULL)
		return (NULL);

	express = list->express;
	prev = list;
	printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

	while (express && express->n < value)
	{
		prev = express;
		express = express->express;
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
	}

	if (express == NULL)
	{
		express = prev;
		while (express->next)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, express->index);

	while (prev && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
