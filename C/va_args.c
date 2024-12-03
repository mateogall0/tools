#include "main.h"

/**
 * Turn variadic arguments into a dynamic array of integers.
 * 
 * Returns: allocated integers array.
 */
int *args_to_int_array(int size, ...)
{
    va_list ptr;
    int *array;
    int i;

    array = malloc(sizeof(int)* size);
    if (!array)
        return (NULL);
    va_start(ptr, size);
    for (i = 0; i < size; i++)
        array[i] = va_arg(ptr, int);
    va_end(ptr);
    return (array);
}