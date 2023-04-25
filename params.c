#include "main.h"

/**
 * init_para - clears struct fields and reset buf
 * @para: the parameters struct
 * @ax: the argument pointer
 *
 * Return: void
 */
void init_para(para_t *para, va_list ax)
{
	para->uns = 0;

	para->plus = 0;
	para->space = 0;
	para->hashtag = 0;
	para->zero = 0;
	para->minus = 0;

	para->width = 0;
	para->precision = UINT_MAX;

	para->h_modifier = 0;
	para->l_modifier = 0;
	(void)ax;
}
