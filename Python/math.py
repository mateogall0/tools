#!/usr/bin/env python3
import math

def digit_count(n: int) -> int:
    """
    Digit counter for integers.
    Given an integer, a count of digits is returned without using string
    constructors or length getters.

    It uses the absolute value of the given number, so if it is negative,
    the negative symbol won't be counted.
    """
    if not isinstance(n, int):
        raise TypeError('n must be an int')
    if n == 0:
        return 1
    return math.floor(math.log10(abs(n)) + 1)
