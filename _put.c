#include "main.h"

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - s);
}

/**
 * _putchar - writes the
 * @n: The character to print
 *
 * Return: 1 On success and -1 in error.
 */
int _putchar(int n)
{
	static int a;
	static char buf[BUF_SIZE];

	if (n == BUF_FLUSH || a >= BUF_SIZE)
	{
		write(1, buf, a);
		a = 0;
	}
	if (n != BUF_FLUSH)
		buf[a++] = n;
	return (1);
}
