#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
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
	unsigned int i = _strlen(str);
	int neg = (!para->unsign && *str == '-');

	if (!para->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (para->precision != UINT_MAX)
		while (i++ < para->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!para->minus)
		return (_number_right_shift(str, para));
	else
		return (_number_left_shift(str, para));
}

/**
 * _number_right_shift - prints a number with options
 * @str: the base number as a string
 * @para: the parameter struct
 *
 * Return: chars printed
 */
int _number_right_shift(char *str, para_t *para)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (para->zero && !para->minus)
		pad_char = '0';
	neg = neg2 = (!para->unsign && *str == '-');
	if (neg && i < para->width && pad_char == '0' && !para->minus)
		str++;
	else
		neg = 0;
	if ((para->plus && !neg2) ||
		(!para->plus && para->space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (para->plus && !neg2 && pad_char == '0' && !para->unsign)
		n += _putchar('+');
	else if (!para->plus && para->space && !neg2 &&
		!para->unsign && para->zero)
		n += _putchar(' ');
	while (i++ < para->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (para->plus && !neg2 && pad_char == ' ' && !para->unsign)
		n += _putchar('+');
	else if (!para->plus && para->space && !neg2 &&
		!para->unsign && !para->zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * _number_left_shift - prints a number with options
 * @str: the base number as a string
 * @para: the parameter struct
 *
 * Return: chars printed
 */
int _number_left_shift(char *str, para_t *para)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (para->zero && !para->minus)
		pad_char = '0';
	neg = neg2 = (!para->unsign && *str == '-');
	if (neg && i < para->width && pad_char == '0' && !para->minus)
		str++;
	else
		neg = 0;

	if (para->plus && !neg2 && !para->unsign)
		n += _putchar('+'), i++;
	else if (para->space && !neg2 && !para->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < para->width)
		n += _putchar(pad_char);
	return (n);
}
