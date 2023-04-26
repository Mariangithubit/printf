#include "main.h"
/**
 * init_specif - the first value of specifier
 * @args: the arguments
 * @specif: the specifiers
 * Return: void
 */
void init_specif(va_list args, p_type *specif)
{
	specif->unsign = 0;
	specif->plus_f = 0;
	specif->minus_f = 0;
	specif->space_f = 0;
	specif->hashtag_f = 0;
	specif->zero_f = 0;
	specif->h_modifier = 0;
	specif->l_modifier = 0;
	specif->width = 0;
	specif->precision = UINT_MAX;
	(void)args;
}
