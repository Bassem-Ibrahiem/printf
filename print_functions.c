#include "main.h"

/**
 * _char - prints character
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _char(va_list x, para_t *para)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(x, int);

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
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _int(va_list x, para_t *para)
{
	long l;

	if (para->l_modifier)
		l = va_arg(x, long);
	else if (para->h_modifier)
		l = (short int)va_arg(x, int);
	else
		l = (int)va_arg(x, int);
	return (_number(convert(l, 10, 0, para), para));
}

/**
 * _string - prints string
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _string(va_list x, para_t *para)
{
	char *str = va_arg(x, char *), pad_char = ' ';
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
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _percent(va_list x, para_t *para)
{
	(void)x;
	(void)para;
	return (_putchar('%'));
}

/**
 * _S - custom format specifier
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int _S(va_list x, para_t *para)
{
	char *str = va_arg(x, char *);
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
