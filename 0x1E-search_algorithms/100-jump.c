#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * min - Returns the minimum of two size_t values
 * @a: First value
 * @b: Second value
 * Return: Minimum of a and b
 */
size_t min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

/**
 * jump_search - Searches for a value in a sorted array using Jump search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: First index where value is located, or -1 if not found or array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step, prev, curr;

    if (array == NULL || size == 0)
        return (-1);

    step = sqrt(size);
    prev = 0;
    curr = 0;

    while (curr < size && array[curr] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", curr, array[curr]);
        prev = curr;
        curr += step;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

    curr = min(curr, size - 1);

    while (prev <= curr)
    {
        printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
        if (array[prev] == value)
            return (prev);
        prev++;
    }

    return (-1);
}
