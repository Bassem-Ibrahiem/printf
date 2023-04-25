#include "main.h"

/**
 * _specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*_specifier(char *s))(va_list ax, para_t *para)
{
	specifier_t specifiers[] = {
		{"c", _char},
		{"d", _int},
		{"i", _int},
		{"s", _string},
		{"%", _percent},
		{"b", _binary},
		{"o", _octal},
		{"u", _unsigned},
		{"x", _hex},
		{"X", _HEX},
		{"p", _address},
		{"S", _S},
		{"r", _rev},
		{"R", _rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * _func - finds the format func
 * @s: the format string
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: the number of bytes printed
 */
int _func(char *s, va_list ax, para_t *para)
{
	int (*f)(va_list, para_t *) = _specifier(s);

	if (f)
		return (f(ax, para));
	return (0);
}

/**
 *  - finds the flag func
 * @s: the format string
 * @para: the parameters struct
 *
 * Return: if flag was valid
 */
int (char *s, para_t *para)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = para->plus = 1;
			break;
		case ' ':
			i = para->space = 1;
			break;
		case '#':
			i = para->hashtag = 1;
			break;
		case '-':
			i = para->minus = 1;
			break;
		case '0':
			i = para->zero = 1;
			break;
	}
	return (i);
}

/**
 * _modifier - finds the modifier func
 * @s: the format string
 * @para: the parameters struct
 *
 * Return: if modifier was valid
 */
int _modifier(char *s, para_t *para)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = para->h_modifier = 1;
		break;
	case 'l':
		i = para->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * _width - s the width from the format string
 * @s: the format string
 * @para: the parameters struct
 * @ax: the argument pointer
 *
 * Return: new pointer
 */
char *_width(char *s, para_t *para, va_list ax)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ax, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	para->width = d;
	return (s);
}
