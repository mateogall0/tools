#include "main.h"

/**
 * Main file that runs all the implemntations.
 * 
 * Used for debugging purposes.
 */
int main()
{
	char *s = "Hello, how are you?", **grid;
	int char_counter, is_power_of_two, palindrome, *int_arr;

    DEBUG_PRINT("Example\n");

	grid = str_to_grid(s, " ");
	char_counter = print_grid(grid);
	printf("%i\n", char_counter);
	free_grid(grid);
	print_to_base(64, 2);
	putchar(10);
	print_to_base(55673, 16);
	putchar(10);
	is_power_of_two = is_power_two(64);
	printf("Is 64 power of 2: %d\n", is_power_of_two);
	is_power_of_two = is_power_two(512);
	printf("Is 512 power of 2: %d\n", is_power_of_two);
	is_power_of_two = is_power_two(2);
	printf("Is 2 power of 2: %d\n", is_power_of_two);
	is_power_of_two = is_power_two(1);
	printf("Is 1 power of 2: %d\n", is_power_of_two);
	is_power_of_two = is_power_two(3);
	printf("Is 3 power of 2: %d\n", is_power_of_two);
	is_power_of_two = is_power_two(5687);
	printf("Is 5687 power of 2: %d\n", is_power_of_two);
	is_power_of_two = is_power_two(5684);
	printf("Is 5684 power of 2: %d\n", is_power_of_two);
	palindrome = is_palindrome("hello");
	printf("Is 'hello' a palindrome: %d\n", palindrome);
	palindrome = is_palindrome("racecar");
	printf("Is 'racecar' a palindrome: %d\n", palindrome);
	int_arr = args_to_int_array(5, 1, 2, 3, 4, 5);
	print_int_array(5, int_arr, ", ");
	print_int_array(5, int_arr, " separator ");
	free(int_arr);
	print_file_as_binary("assets/text.txt");
	return (0);
}