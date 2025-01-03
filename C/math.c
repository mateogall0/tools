#include "main.h"

/**
 * Function that prints a given integer using a given base.
 * the declared here go up to base 16, but can be incremented modifying the
 * alphanumeric string.
 * 
 * Returns: amount of printed characters.
 */
const char *alphanumeric = "0123456789abcdef";
int print_to_base(unsigned int n, unsigned int base)
{
    int counter;

    if (n < base)
        return (putchar(alphanumeric[n]));
    counter = print_to_base(n / base, base);
    return (putchar(alphanumeric[n % base]) + counter);
}

/**
 * Checks if a number is a power of 2 non-recursevily.
 * 
 * Returns: 1 if is power, 0 if not.
 */
int is_power_two(int n)
{
    return ((n > 0) && ((n & (n - 1)) == 0));
}