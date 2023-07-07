#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * Return: 1 on success.
 * on error, -1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
