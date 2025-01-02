#ifndef TOOLS_H
#define TOOLS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>

/* Macros */
#define MAX_AUX_TOKENS 1024
#define BUFF_SIZE 1024

/**
 * Debug macros
 * 
 * When compiling using the flag -DDEBUG will print the given values.
 */
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) fprintf(stderr, "Debug: " fmt, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) // DEBUG is not defined
#endif

int print_grid(char **grid);
char **str_to_grid(const char *s, const char *delim);
void free_grid(char **grid);
int print_to_base(unsigned int n, unsigned int base);
int is_power_two(int n);
int is_palindrome(const char *s);
int print_int_array(int size, int *array, char *separator);
int *args_to_int_array(int size, ...);
int print_file_as_binary(char *s);
#endif