#include "main.h"

/**
 * _char - prints character
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _char(va_list ax, para_t *para)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ax, int);

	if (para->minus)
		sum += _putchar(ch);
	while (pad++ < para->width)
		sum += _putchar(pad_char);
	if (!para->minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * _int - prints integer
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _int(va_list ax, para_t *para)
{
	long l;

	if (para->l_modifier)
		l = va_arg(ax, long);
	else if (para->h_modifier)
		l = (short int)va_arg(ax, int);
	else
		l = (int)va_arg(ax, int);
	return (_number(convert(l, 10, 0, para), para));
}

/**
 * _string - prints string
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _string(va_list ax, para_t *para)
{
	char *str = va_arg(ax, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)para;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (para->precision < pad)
		j = pad = para->precision;

	if (para->minus)
	{
		if (para->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < para->width)
		sum += _putchar(pad_char);
	if (!para->minus)
	{
		if (para->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * _percent - prints string
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _percent(va_list ax, para_t *para)
{
	(void)ax;
	(void)para;
	return (_putchar('%'));
}

/**
 * _S - custom format specifier
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _S(va_list ax, para_t *para)
{
	char *str = va_arg(ax, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, para);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
