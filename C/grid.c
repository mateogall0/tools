#include "main.h"

int print_grid(char **grid)
{
	int counter = 0, i;

	if (!grid)
		return (counter);
	for (i = 0; grid[i]; i++)
	{
		counter += printf("%s\n", grid[i]);
	}

	return (counter);
}