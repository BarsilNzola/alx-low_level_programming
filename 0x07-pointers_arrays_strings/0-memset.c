#include "main.h"

/**
 *  * _memset - entry
 * @s: pointer to char params
 * @b: data to change
 * @n: index
 * Return: Always 0
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
