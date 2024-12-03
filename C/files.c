#include "main.h"

/**
 * Reads a file located at given file_path and iterates over each byte of it
 * to print each bit.
 * 
 * Returns: amount of printed characters.
 */

int print_file_as_binary(char *file_path)
{
    int count = 0, i, j, fd, first_time_iterating = 1;
    char bytes[BUFF_SIZE];
    if (!file_path)
        return (0);

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        return (0);
    while (read(fd,bytes, 1) == 1)
    {
        for (j = 0; bytes[j]; j++)
        {
            if (!first_time_iterating)
                count += putchar(' ');
            else
                first_time_iterating = 0;
            for (i = 7; i >= 0; --i)
                count += putchar(((bytes[j] & (1 << i))) ? '1' : '0');
        }
        
    }
    count += putchar('\n');
    close(fd);
    return (count);
}