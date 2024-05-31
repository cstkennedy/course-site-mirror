#! /usr/bin/env python3

import sys

from typing import (Callable, Tuple)
from fractions import (Fraction)


EPSILON = Fraction(1, 10**6)
MAX_ITERATIONS = 100

def newtons_method(f: Callable[[Fraction], Fraction],
                   df: Callable[[Fraction], Fraction],
                   x_0: Fraction,
                   eps: Fraction = EPSILON) -> Tuple[int, Fraction]:
    """
    Compute an approximate solution to f(x) = 0 using Newton's Method.

    Args:
        f: mathematical function
        df: derivative of f
        x_0: an initial guess (i.e., x_0)
        eps: tolerance within which two guesses will be considered equal.

    Returns:
        A Tuple with the number of iterations and approximate solution.

    """

    for n, numerical_solution in enumerate(__inner_newtons_method(f, df, x_0, eps)):
        if n >= MAX_ITERATIONS:
            break

    return n, numerical_solution


def __inner_newtons_method(f: Callable[[Fraction], Fraction],
                   df: Callable[[Fraction], Fraction],
                   x_n: Fraction,
                   eps: Fraction = EPSILON) -> Tuple[int, Fraction]:

    next_x_n = x_n + 1000 * eps
    while abs(x_n - next_x_n) > eps:

        x_n = next_x_n
        next_x_n = x_n - (f(x_n) / df(x_n))

        yield x_n

    return x_n


def main():
    """
    This main function serves as the driver for the demo. Such functions
    are not required in Python. However, we want to prevent unnecessary module
    level (i.e., global) variables.
    """

    try:
        initial_guess = float(sys.argv[1])

    except IndexError as error:
        print("Usage: {0} initial_guess".format(*sys.argv))
        sys.exit(1)

    except ValueError as error:
        print("ERROR: {1} is not a valid number".format(*sys.argv))
        print("  " + str(error))
        sys.exit(2)

    # Function (f) and its derivative (dx)
    def f(x):
        return (x ** 2) - 1

    def df(x):
        return 2 * x

    try:
        num_iterations, solution_newton = newtons_method(f, df, initial_guess)
        fx_newton = f(solution_newton)

        output_str = "x = {} | f(x) = {} | {} iterations"
        print(output_str.format(solution_newton,
                                str(fx_newton),
                                str(num_iterations)))

    except ZeroDivisionError as error:
        print(str(error))


if __name__ == "__main__":
    main()
