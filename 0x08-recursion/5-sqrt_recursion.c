#include "main.h"

int _sqrt_recursion(int n);

/**
 * find_sqrt: finds the natural square root of a given number.
 * @g: the given number
 * @c: the root to be tested
 *
 * Return: if the number has a natural square root - the square root.
 * 	   if the number does not have a natural square root, 1.
*/

int sqrt_check(int g, int c)
{
	if (g * g == c)
		return (g);
	if (g * g > c)
		return (-1);
	return (sqrt_check(g + 1, c));
}

/**
 * _sqrt_recursion - Returns the natural square of a number
 *
 * @n: integer to find sqrt of
 *
 * Return: Natural square root or -1
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);

	return (sqrt_check(1, n));
}

