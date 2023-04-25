#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @n: number
 * @bs: base
 * @flg: argument flags
 * @para: paramater struct
 *
 * Return: string
 */
char *convert(long int n, int bs, int flg, para_t *para)
{
	static char *arr;
	static char buff[50];
	char s = 0;
	char *p;
	unsigned long n = n;
	(void)para;

	if (!(flg & CONVERT_UNSIGNED) && n < 0)
	{
		n = -n;
		s = '-';

	}
	arr = flg & _LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buff[49];
	*p = '\0';

	do	{
		*--p = arr[n % bs];
		n /= bs;
	} while (n != 0);

	if (s)
		*--p = s;
	return (p);
}

/**
 * _unsed - prints unsed integer nbers
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _unsed(va_list ax, para_t *para)
{
	unsigned long l;
uns
	if (para->l_modifier)
		l = (unsigned long)va_arg(ax, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(ax, unsigned int);
	else
		l = (unsigned int)va_arg(ax, unsigned int);
	para->uns = 1;
	return (_number(convert(l, 10, CONVERT_UNSIGNED, para), para));
}



/**
 * _address - prints address
 * @ax: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _address(va_list ax, para_t *para)
{
	unsigned long int n = va_arg(ax, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | _LOWERCASE, para);
	*--str = 'x';
	*--str = '0';
	return (_number(str, para));
}
