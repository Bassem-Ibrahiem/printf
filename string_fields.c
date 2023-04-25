#include "main.h"

/**
 * gt_precision - gts the precision from the format string
 * @p: the format string
 * @para: the parameters struct
 * @x: the argument pointer
 *
 * Return: new pointer
 */
char *gt_precision(char *p, para_t *para, va_list x)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(x, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	para->precision = d;
	return (p);
}
