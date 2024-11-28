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
        if (!temp[i])
        {
            for (j = 0; j < i - 1; j++)
                free(temp[j]);
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
            free(temp[j]);
        return (NULL);
    }
    for (j = 0; j < i; j++)
    {
        grid[j] = temp[j];
    }
    return (grid);
}