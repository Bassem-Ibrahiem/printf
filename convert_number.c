#include "main.h"

/**
 * _hex - prints unsigned hex numbers in lowercase
 * @x: the argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _hex(va_list x, para_t *para)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (para->l_modifier)
		l = (unsigned long)va_arg(x, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(x, unsigned int);
	else
		l = (unsigned int)va_arg(x, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | _LOWERCASE, para);
	if (para->hashtag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	para->unsign = 1;
	return (c += _number(str, para));
}

/**
 * _HEX - prints unsigned hex numbers in uppercase
 * @x: the argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _HEX(va_list x, para_t *para)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (para->l_modifier)
		l = (unsigned long)va_arg(x, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(x, unsigned int);
	else
		l = (unsigned int)va_arg(x, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, para);
	if (para->hashtag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	para->unsign = 1;
	return (c += _number(str, para));
}
/**
 * _binary - prints unsigned binary number
 * @x: the argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _binary(va_list x, para_t *para)
{
	unsigned int n = va_arg(x, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, para);
	int c = 0;

	if (para->hashtag && n)
		*--str = '0';
	para->unsign = 1;
	return (c += _number(str, para));
}

/**
 * _octal - prints unsigned octal numbers
 * @x: the argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _octal(va_list x, para_t *para)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (para->l_modifier)
		l = (unsigned long)va_arg(x, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(x, unsigned int);
	else
		l = (unsigned int)va_arg(x, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, para);

	if (para->hashtag && l)
		*--str = '0';
	para->unsign = 1;
	return (c += _number(str, para));
}
