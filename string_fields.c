#include "main.h"

/**
 * _precision - s the precision from the format string
 * @x: the format string
 * @para: the parameters struct
 * @ax: the argument pointer
 *
 * Return: new pointer
 */
char *_precision(char *x, para_t *para, va_list ax)
{
	int d = 0;

	if (*x != '.')
		return (x);
	x++;
	if (*x == '*')
	{
		d = va_arg(ax, int);
		x++;
	}
	else
	{
		while (_isdigit(*x))
			d = d * 10 + (*x++ - '0');
	}
	para->precision = d;
	return (x);
}
