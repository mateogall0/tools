#include "main.h"

int main()
{
	char *s = "Hello, how are you?", **grid;
	int char_counter;

	grid = str_to_grid(s, " ");
	char_counter = print_grid(grid);
	printf("%i\n", char_counter);
	return (0);
}