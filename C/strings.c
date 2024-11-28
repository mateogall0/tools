#include "main.h"

/**
 * Checks if a given word is a palindrome.
 * 
 * Returns: 1 if it is a palindrome, 0 otherwise.
 */
int is_palindrome(const char *s)
{
    int start = 0, end = strlen(s) - 1;
    if (!s)
        return (0);

    while (start < end)
    {
        if (s[start] != s[end])
            return (0);
        start++;
        end--;
    }
    return (1);
}