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
int print_to_base(unsigned int n, unsigned int base);

#endif