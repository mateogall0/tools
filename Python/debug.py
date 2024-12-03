#!/usr/bin/env python3
import time

DEBUG = True  # in a real scenario this should be a global debug variable
def timer(func):
    """
    Time measurer using this wrapper. Takes the time right before executing
    the method and right after and substracts them to get the time it took to
    execute the method.

    Usage:
        ```
        @timer
         def method(self, user):
             pass
        ```
    """
    def wrapper(*ag, **kw):
        if not DEBUG:
            return func(*ag, **kw)
        start = time.time()
        result = func(*ag, **kw)
        end = time.time()
        print(f"{func.__name__} took {end - start:.6f} seconds")
        return result
    return wrapper

@timer
def __example_func():
    print('Executing function...')
    # operations
    2**2
    4**6
    90**2
    time.sleep(0.1)

if __name__ == '__main__':
    __example_func()