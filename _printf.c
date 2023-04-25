#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ax;
	char *x, *start;
	para_t para = PARA_INIT;

	va_start(ax, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (x = (char *)format; *x; x++)
	{
		init_para(&para, ax);
		if (*x != '%')
		{
			sum += _putchar(*x);
			continue;
		}
		start = x;
		x++;
		while ((x, &para)) /* while char at x is flag char */
		{
			x++; /* next char */
		}
		x = _width(x, &para, ax);
		x = _precision(x, &para, ax);
		if (_modifier(x, &para))
			p++;
		if (!_specifier(x))
			sum += _from_to(start, x,
				para.l_modifier || para.h_modifier ? x - 1 : 0);
		else
			sum += _func(x, ax, &para);
	}
	_putchar(BUF_FLUSH);
	va_end(ax);
	return (sum);
}
