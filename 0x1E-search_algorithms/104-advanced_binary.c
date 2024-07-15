#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The left index of the array
 * @right: The right index of the array
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_binary - Recursive helper function for advanced_binary
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary of the subarray
 * @right: Right boundary of the subarray
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found
 */
int recursive_binary(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = (left + right) / 2;

    if (array[mid] == value && (mid == left || array[mid - 1] < value))
        return (mid);

    if (array[mid] >= value)
        return recursive_binary(array, left, mid, value);
    
    return recursive_binary(array, mid + 1, right, value);
}

/**
 * advanced_binary - Searches for a value in a sorted array using Advanced Binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: First index where value is located, or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return recursive_binary(array, 0, size - 1, value);
}
