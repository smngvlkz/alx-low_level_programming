#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list using Jump search
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: Value to search for
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step, step_size;
    listint_t *prev, *current;

    if (list == NULL || size == 0)
        return (NULL);

    step = sqrt(size);
    prev = current = list;

    while (current->index < size - 1 && current->n < value)
    {
        prev = current;
        step_size = 0;
        while (current->next && step_size < step)
        {
            current = current->next;
            step_size++;
        }
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);

    while (prev->index <= current->index && prev->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
        if (prev == NULL)
            break;
    }

    return (NULL);
}
