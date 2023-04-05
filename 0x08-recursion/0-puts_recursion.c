#include "main.h"

/** 
 * _puts_recursion: prints a string, followed by a new line.
 * @s: The string to be printed.
 *Return: No.
 */

void _puts_recursion(char *s)
{
	if (*s == 0)
	{
		_putchar(10);
	}
	else
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
}
