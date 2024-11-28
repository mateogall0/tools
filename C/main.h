#ifndef TOOLS_H
#define TOOLS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Macros */
#define MAX_AUX_TOKENS 1024

int print_grid(char **grid);
char **str_to_grid(const char *s, const char *delim);
void free_grid(char **grid);

#endif