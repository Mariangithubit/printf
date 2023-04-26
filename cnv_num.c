#include "main.h"
/**
 * p_hex - hex
 * @args: argument
 * @specif: parameter
 * Return: hex num
 */
int p_hex(va_list args, p_type *specif)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (specif->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (specif->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, specif);
	if (specif->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	specif->unsign = 1;
	return (c += print_number(str, specif));
}
/**
 * p_HEX - HEX
 * @args: arguments
 * @specif: parameter
 * Return: printed HEX
 */
int p_HEX(va_list args, p_type *specif)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (specif->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (specif->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, specif);
	if (specif->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	specif->unsign = 1;
	return (c += print_number(str, specif));
}
/**
 * p_binary - binary
 * @args: argument
 * @specif: parameters
 * Return: printed binary
 */
int p_binary(va_list args, p_type *specif)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, specif);
	int c = 0;

	if (specif->hashtag_flag && n)
		*--str = '0';
	specif->unsign = 1;
	return (c += print_number(str, specif));
}
/**
 * p_octal - octal
 * @args: argument
 * @specif: parameter
 * Return: octal nums
 */
int p_octal(va_list args, p_type *specif)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (specif->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (specif->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
	{
		l = (unsigned int)va_arg(args, unsigned int);
		str = convert(l, 8, CONVERT_UNSIGNED, specif);
	}
	if (specif->hashtag_flag && l)
		*--str = '0';
	specif->unsign = 1;
	return (c += print_number(str, specif));
}
