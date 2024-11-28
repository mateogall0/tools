#include "main.h"

/**
 * Main file that runs all the implemntations.
 * 
 * Used for debugging purposes.
 */
int main()
{
	char *s = "Hello, how are you?", **grid;
	int char_counter;

	grid = str_to_grid(s, " ");
	char_counter = print_grid(grid);
	printf("%i\n", char_counter);
	free_grid(grid);
	print_to_base(64, 2);
	putchar(10);
	print_to_base(55673, 16);
	putchar(10);
	return (0);
}