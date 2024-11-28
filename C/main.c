#include "main.h"

int main()
{
	char *s = "Hello, how are you?", **grid;

	grid = str_to_grid(s, " ");
	print_grid(grid);
	return (0);
}