#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: array width
 * @height: array height
 *
 * Return: a pointer to a 2D array or, NULL in failure
 */

int **alloc_grid(int width, int height)
{
	int i, r;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (r = 0; r < i; r++)
				free(grid[r]);
			free(grid);
			return (NULL);
		}
		for (r = 0; r < width; r++)
			grid[i][r] = 0;
	}
	return (grid);
}
