#include "main.h"

int _sqrt_recursion(int n);

/**
 * find_sqrt: finds the natural square root of a given number.
 * @num: the given number
 * @root: the root to be tested
 *
 * Return: if the number has a natural square root - the square root.
 * 	   if the number does not have a natural square root, 1.
 */ 

int find_sqrt(int num, int root)
{
	if ((root * root) == num)
		return (root);
}
