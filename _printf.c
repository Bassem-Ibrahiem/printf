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
	va_list x;
	char *p, *start;
	para_t para = PARA_INIT;

	va_start(x, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_para(&para, x);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (gt(p, &para)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = gt_width(p, &para, x);
		p = gt_precision(p, &para, x);
		if (gt_modifier(p, &para))
			p++;
		if (!gt_specifier(p))
			sum += _from_to(start, p,
				para.l_modifier || para.h_modifier ? p - 1 : 0);
		else
			sum += gt_func(p, x, &para);
	}
	_putchar(BUF_FLUSH);
	va_end(x);
	return (sum);
}
