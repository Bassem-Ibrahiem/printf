#include "main.h"

/**
 * _isdigit - checks if
 * @n: the character is digit
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _strlen - returns the length of
 * @s: the string
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int a = 0;

	while (*s++)
		a++;
	return (a);
}

/**
 * _number - prints a number with options
 * @str: the base number as a string
 * @para: the parameter struct
 *
 * Return: chars printed
 */
int _number(char *str, para_t *para)
{
	unsigned int a = _strlen(str);
	int ng = (!para->uns && *str == '-');

	if (!para->precision && *str == '0' && !str[1])
		str = "";
	if (ng)
	{
		str++;
		a--;
	}
	if (para->precision != UINT_MAX)
		while (a++ < para->precision)
			*--str = '0';
	if (ng)
		*--str = '-';

	if (!para->minus)
		return (r_shift_n(str, para));
	else
		return (l_shift_n(str, para));
}

/**
 * r_shift_n - prints a number with options
 * @str: the base number as a string
 * @para: the parameter struct
 *
 * Return: chars printed
 */
int r_shift_n(char *str, para_t *para)
{
	unsigned int n = 0, ng, ng2, a = _strlen(str);
	char pad_char = ' ';

	if (para->zero && !para->minus)
		pad_char = '0';
	ng = ng2 = (!para->uns && *str == '-');
	if (ng && a < para->width && pad_char == '0' && !para->minus)
		str++;
	else
		ng = 0;
	if ((para->plus && !ng2) ||
		(!para->plus && para->space && !ng2))
		a++;
	if (ng && pad_char == '0')
		n += _putchar('-');
	if (para->plus && !ng2 && pad_char == '0' && !para->uns)
		n += _putchar('+');
	else if (!para->plus && para->space && !ng2 &&
		!para->uns && para->zero)
		n += _putchar(' ');
	while (a++ < para->width)
		n += _putchar(pad_char);
	if (ng && pad_char == ' ')
		n += _putchar('-');
	if (para->plus && !ng2 && pad_char == ' ' && !para->uns)
		n += _putchar('+');
	else if (!para->plus && para->space && !ng2 &&
		!para->uns && !para->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * l_shift_n - prints a number with options
 * @str: the base number as a string
 * @para: the parameter struct
 *
 * Return: chars printed
 */
int l_shift_n(char *str, para_t *para)
{
	unsigned int n = 0, ng, ng2, a = _strlen(str);
	char pad_char = ' ';

	if (para->zero && !para->minus)
		pad_char = '0';
	ng = ng2 = (!para->uns && *str == '-');
	if (ng && a < para->width && pad_char == '0' && !para->minus)
		str++;
	else
		ng = 0;

	if (para->plus && !ng2 && !para->uns)
		n += _putchar('+'), a++;
	else if (para->space && !ng2 && !para->uns)
		n += _putchar(' '), a++;
	n += _puts(str);
	while (a++ < para->width)
		n += _putchar(pad_char);
	return (n);
}
