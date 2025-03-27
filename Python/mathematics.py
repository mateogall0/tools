#!/usr/bin/env python3
import math
from typing import List
import matplotlib.pyplot as plt
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

def radian(degrees: float, radius=1.0) -> float:
    """
    Convert degrees to radians.
    """
    return radius * degrees * math.pi / 180

def ellipse_radian(degrees: float, a=1.0, b=1.0, num_points=1000, plot=False) -> float:
    """
    Convert degrees to radians.
    This function specifcially works with ellipses.
    """
    arc_length = 0.0

    step_size = radian(degrees) / num_points
    theta_values = []

    for i in range(num_points):
        theta1 = i * step_size
        theta2 = theta1 + step_size
        x1 = a * math.cos(theta1)
        y1 = b * math.sin(theta1)
        x2 = a * math.cos(theta2)
        y2 = b * math.sin(theta2)

        dx = x2 - x1
        dy = y2 - y1
        ds = math.sqrt(dx**2 + dy**2)

        arc_length += ds
        if plot:
            theta_values.append((x1, y1))

    if plot:
        x_vals, y_vals = zip(*theta_values)
        plt.figure(figsize=(6, 6))
        plt.plot(x_vals, y_vals, marker='o', linestyle='-', markersize=2)
        plt.xlabel('X-axis')
        plt.ylabel('Y-axis')
        plt.title(f'Elliptical Arc for {degrees} Degrees')
        plt.axis('equal')
        plt.grid(True)
        plt.show()

    return arc_length

def simple_integration(f, a, b, num_points=1000) -> float:
    dx = (b-a) / num_points
    integral = 0.0

    for i in range(num_points):
        x = a + i * dx
        integral += f(x) * dx
    return integral

def derivative(f, x, h=1e-5, method="central"):
    match method:
        case 'forward':
            return (f(x + h) - f(x)) / h
        case 'backward':
            return (f(x) - f(x - h)) / h
        case 'central':
            return (f(x + h) - f(x - h)) / (2 * h)
        case _:
            raise ValueError('invalid method, must be "forward", "central" or "backward"')

if __name__ == '__main__':
    print(sieve_of_eratosthenes(60))
    print(sieve_of_eratosthenes(-5))
    print(sieve_of_eratosthenes(2))
    print(first_degree_op(2, 2, 3))
    print(sum_natural_numbers(100))
    print(sum_natural_numbers(0))
    print(radian(180))
    print(radian(30, 2))
    print(ellipse_radian(30, 2, 1))

    def f(x):
        return x**2
    
    def f2(x):
        return x**3
    
    print(simple_integration(f, 0, 1))

    x0 = 50
    h=1e-5

    forward_result = derivative(f2, x0, h, "forward")
    backward_result = derivative(f2, x0, h, "backward")
    central_result = derivative(f2, x0, h, "central")

    print(f"Forward Difference: {forward_result}")
    print(f"Backward Difference: {backward_result}")
    print(f"Central Difference: {central_result}")
    print(f"Exact Derivative: {3*x0**2}")
