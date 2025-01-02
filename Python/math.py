#!/usr/bin/env python3
import math
from typing import List

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

def sieve_of_eratosthenes(limit: int) -> List[int]:
    """
    Generate all prime numbers up to the specified limit using the Sieve of
    Eratosthenes algorithm.
    """
    if limit < 2:
        return []
    primes = [True] * (limit + 1)
    primes[0] = primes[1] = False

    for num in range(2, int(limit ** 0.5) + 1):
        if primes[num]:
            for multiple in range(num * num, limit + 1, num):
                primes[multiple] = False

    return [num for num, is_prime in enumerate(primes) if is_prime]

def first_degree_op(a: float, b: float, y=0.0) -> float:
    """
    Given a first degree operation in the form of ax+b=y, this function solves
    the ecuation returning the value of x for the given y.
    """
    x = (y-b) / a
    return x

def sum_natural_numbers(n: int) -> int:
    """
    Sum of natural numbers up to n in O(1)
    """
    return n * (n+1) // 2

if __name__ == '__main__':
    print(sieve_of_eratosthenes(60))
    print(sieve_of_eratosthenes(-5))
    print(sieve_of_eratosthenes(2))
    print(first_degree_op(2, 2, 3))
    print(sum_natural_numbers(100))
    print(sum_natural_numbers(0))
