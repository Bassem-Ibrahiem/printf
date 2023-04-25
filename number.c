#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @para: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, para_t *para)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)para;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & _LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _unsigned - prints unsigned integer numbers
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _unsigned(va_list x, para_t *para)
{
	unsigned long l;

	if (para->l_modifier)
		l = (unsigned long)va_arg(x, unsigned long);
	else if (para->h_modifier)
		l = (unsigned short int)va_arg(x, unsigned int);
	else
		l = (unsigned int)va_arg(x, unsigned int);
	para->unsign = 1;
	return (_number(convert(l, 10, CONVERT_UNSIGNED, para), para));
}



/**
 * _address - prints address
 * @x: argument pointer
 * @para: the parameters struct
 *
 * Return: bytes printed
 */
int _address(va_list x, para_t *para)
{
	unsigned long int n = va_arg(x, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | _LOWERCASE, para);
	*--str = 'x';
	*--str = '0';
	return (_number(str, para));
}
