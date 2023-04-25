#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define _LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus: on if plus specified
 * @space: on if hashtag specified
 * @hashtag: on if  specified
 * @zero: on if  specified
 * @minus: on if  specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus		: 1;
	unsigned int space		: 1;
	unsigned int hashtag	: 1;
	unsigned int zero		: 1;
	unsigned int minus		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} para_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, para_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* _functions.c module */
int _char(va_list x, para_t *para);
int _int(va_list x, para_t *para);
int _string(va_list x, para_t *para);
int _percent(va_list x, para_t *para);
int _S(va_list x, para_t *para);

/* number.c module */
char *convert(long int num, int base, int flags, para_t *para);
int _unsigned(va_list x, para_t *para);
int _address(va_list x, para_t *para);

/* specifier.c module */
int (*gt_specifier(char *s))(va_list x, para_t *para);
int gt_func(char *s, va_list x, para_t *para);
int gt(char *s, para_t *para);
int gt_modifier(char *s, para_t *para);
char *gt_width(char *s, para_t *para, va_list x);

/* convert_number.c module */
int _hex(va_list x, para_t *para);
int _HEX(va_list x, para_t *para);
int _binary(va_list x, para_t *para);
int _octal(va_list x, para_t *para);

/* simple_printers.c module */
int _from_to(char *start, char *stop, char *except);
int _rev(va_list x, para_t *para);
int _rot13(va_list x, para_t *para);

/* _number.c module */
int _isdigit(int c);
int _strlen(char *s);
int _number(char *str, para_t *para);
int _number_right_shift(char *str, para_t *para);
int _number_left_shift(char *str, para_t *para);

/* para.c module */
void init_para(para_t *para, va_list x);

/* string_fields.c modoule */
char *gt_precision(char *p, para_t *para, va_list x);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
