#include "main.h"
/**
 * p_char - chars
 * @args: args
 * @specif: parameter
 * Return: printed char
 */
int p_char(va_list args, p_type *specif)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(args, int);

	if (specif->minus_flag)
		sum += _putchar(ch);
	while (pad++ < specif->width)
		sum += _putchar(pad_char);
	if (!specif->minus_flag)
		sum += _putchar(ch);
	return (sum);
}
/**
 * p_int - integer
 * @args: args
 * @specif: parameter
 * Return: int
 */
int p_int(va_list args, p_type *specif)
{
	long l;

	if (specif->l_modifier)
		l = va_arg(args, long);
	else if (specif->h_modifier)
		l = (short int)va_arg(args, int);
	else
	{
		l = (int)va_arg(args, int);
	}
	return (print_number(convert(l, 10, 0, specif), specif));
}
/**
 * p_string - string
 * @args: args
 * @specif: parameter
 * Return: string
 */
int p_string(va_list args, p_type *specif)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;
	(void)specif;

	switch ((int)(!str))
	{
		case 1:
			str = NULL_STRING;
			j = pad = _strlen(str);
	}
	if (specif->precision < pad)
		j = pad = specif->precision;
	if (specif->minus_flag)
	{
		if (specif->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _input(str);
	}
	while (j++ < specif->width)
		sum += _putchar(pad_char);
	if (!specif->minus_flag)
	{
		if (specif->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _input(str);
	}
	return (sum);
}
/**
 * p_percent - %
 * @args: args
 * @specif: parameter
 * Return: percent
 */
int p_percent(va_list args, p_type *specif)
{
	(void)args;
	(void)specif;

	return (_putchar('%'));
}
/**
 * p_S - String
 * @args: args
 * @specif: parameter
 * Return: string
 */
int p_S(va_list args, p_type *specif)
{
	char *str = va_arg(args, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_input(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, specif);
		}
		if (!hex[1])
		{
			sum += _putchar('0');
			sum += _input(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
