#include "main.h"

/**
 * Tokenizes a given string using a given delimeter to turn it into an array
 * of strings. Ensures proper memory allocation and duplicates the original
 * string to ensure further usage of the original input string.
 * 
 * Uses an auxiliar static array with a predifined size to store the
 * duplicated tokens to further be stored in a dynamic array.
 * This approach eliminates the necessity to tokenize twice to obtain the
 * size of the grid.
 * 
 * Returns: 2D array containing the tokenized string.
 */
char **str_to_grid(const char *s, const char *delim)
{
	char *dup, *aux[MAX_AUX_TOKENS], *token, **grid;
	int i, j;

	if (!s || !delim)
		return (NULL);
	dup = strdup(s);
	if (!dup)
		return (NULL);
    token = strtok(dup, delim);
	for (i = 0; token; i++)
	{
		aux[i] = strdup(token);
        if (!aux[i])
        {
            for (j = 0; j < i - 1; j++)
                free(aux[j]);
            free(dup);
            return (NULL);
        }
		token = strtok(NULL, delim);
	}
    free(dup);
	grid = malloc(sizeof(char *) * i);
    if (!grid)
    {
        for (j = 0; j < i; j++)
            free(aux[j]);
        return (NULL);
    }
    for (j = 0; j < i; j++)
    {
        grid[j] = aux[j];
    }
    return (grid);
}