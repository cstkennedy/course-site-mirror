#! /usr/bin/env python3

import sys

from typing import (Callable, Tuple)
import typing
from fractions import (Fraction)


EPSILON = 10e-6
MAX_ITERATIONS = 100

def newtons_method(f: Callable[[float], float],
                   df: Callable[[float], float],
                   x_n: float,
                   eps: float = EPSILON) -> Tuple[int, float]:
    """
    Compute an approximate solution to f(x) = 0 using Newton's Method.

    Args:
        f: mathematical function
        df: derivative of f
        x_n: an initial guess (i.e., x_0)
        eps: tolerance within which two guesses will be considered equal.

    Returns:
        A Tuple with the number of iterations and approximate solution.

    """

    n = 0

    next_x_n = x_n + 1000 * eps
    while abs(x_n - next_x_n) > eps and n < MAX_ITERATIONS:
        n += 1

        x_n = next_x_n
        next_x_n = x_n - (f(x_n) / df(x_n))

    return n, x_n


def main():
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

        output_str = "x = {:.4f} | f(x) = {:.4f} | {} iterations"
        print(output_str.format(solution_newton, fx_newton, num_iterations))

    except ZeroDivisionError as error:
        print(str(error))


if __name__ == "__main__":
    main()
