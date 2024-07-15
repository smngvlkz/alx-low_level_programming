#include <stdio.h>
#include <stdlib.h>
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
 * binary_search_exp - Performs binary search in a subarray
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary of the subarray
 * @right: Right boundary of the subarray
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found
 */
int binary_search_exp(int *array, size_t left, size_t right, int value)
{
    size_t i, mid;

    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        mid = (left + right) / 2;

        if (array[mid] == value)
            return (mid);
        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: First index where value is located, or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t left, right;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    left = bound / 2;
    right = min(bound, size - 1);

    printf("Value found between indexes [%lu] and [%lu]\n", left, right);
    return binary_search_exp(array, left, right, value);
}
