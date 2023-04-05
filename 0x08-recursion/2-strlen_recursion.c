#include "main.h"

/**
 * _strlen_recursion: returns the length of atring.
 * @s: The string to be measured.
 *
 * Return: length of string.
 */

int _strlen_recursion(char *s)
{
	int len = a;

	if (*s)
	{
		len++;
		len += _strlen_recursion(s + 1);
	}
}
