#include "main.h"

/**
 * Prints an array of integers, separated by a given separator and ended with
 * a line break.
 * 
 * Returns: amount of printed characters.
 */
int print_int_array(int size, int *array, char *separator)
{
    int i;
    int count = 0;

    if (!array)
        return (count);
    for (i = 0; i < size; i++)
    {
        if (i == size - 1)
            count += printf("%d\n", array[i]);
        else
            count += printf("%d%s", array[i], separator);
    }
    return (count);
}