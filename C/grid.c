#include "main.h"

/**
 * Given a grid it prints the values separated by a line break.
 * 
 * Returns: amount of printed characters.
 */
int print_grid(char **grid)
{
	int counter = 0, i;

	if (!grid)
		return (counter);
	for (i = 0; grid[i]; i++)
		counter += printf("%s\n", grid[i]);

	return (counter);
}

void free_grid(char **grid)
{
	int i;
	if (!grid)
		return;
	for (i = 0; grid[i]; i++)
		free(grid[i]);
	free(grid);
}