#include "main.h"


char **str_to_grid(const char *s, const char *delim)
{
	char *dup, *temp[MAX_TEMP_TOKENS], *token, **grid;
	int i, j;

	if (!s || !delim)
		return (NULL);
	dup = strdup(s);
	if (!dup)
		return (NULL);
    token = strtok(dup, delim);
	for (i = 0; token; i++)
	{
		temp[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	grid = malloc(sizeof(char *) * i);
    for (j = 0; j < i; j++)
    {
        grid[j] = temp[j];
    }
    return (grid);
}