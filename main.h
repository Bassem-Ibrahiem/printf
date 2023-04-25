#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define _LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @uns: flag if unsigned value
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
	unsigned int uns		: 1;

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
int _putchar(int n);

/* _functions.c module */
int _char(va_list ax, para_t *para);
int _int(va_list ax, para_t *para);
int _string(va_list ax, para_t *para);
int _percent(va_list ax, para_t *para);
int _S(va_list ax, para_t *para);

/* number.c module */
char *convert(long int n, int bs, int flg, para_t *para);
int _unsigned(va_list ax, para_t *para);
int _address(va_list ax, para_t *para);

/* specifier.c module */
int (*_specifier(char *s))(va_list ax, para_t *para);
int _func(char *s, va_list ax, para_t *para);
int (char *s, para_t *para);
int _modifier(char *s, para_t *para);
char *_width(char *s, para_t *para, va_list ax);

/* convert_number.c module */
int _hex(va_list ax, para_t *para);
int _HEX(va_list ax, para_t *para);
int _binary(va_list ax, para_t *para);
int _octal(va_list ax, para_t *para);

/* simple_printers.c module */
int _from_to(char *start, char *stop, char *except);
int _rev(va_list ax, para_t *para);
int _rot13(va_list ax, para_t *para);

/* _number.c module */
int _isdigit(int c);
int _strlen(char *s);
int _number(char *str, para_t *para);
int r_shift_n(char *str, para_t *para);
int l_shift_n(char *str, para_t *para);

/* para.c module */
void init_para(para_t *para, va_list ax);

/* string_fields.c modoule */
char *_precision(char *x, para_t *para, va_list ax);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
