#include "main.h"
/**
 * _isdigit - the number
 * @c: the char
 * Return: 1 if digit
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - string length
 * @s: string
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}
/**
 * print_number - print num
 * @str: string
 * @specif: parameter
 * Return: printed char
 */
int print_number(char *str, p_type *specif)
{
	unsigned int i = _strlen(str);
	int neg = (!specif->unsign && *str == '-');

	if (!specif->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (specif->precision != UINT_MAX)
		while (i++ < specif->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!specif->minus_flag)
		return (print_number_right_shift(str, specif));
	else
		return (print_number_left_shift(str, specif));
}
/**
 * print_number_right_shift - right nums
 * @str: string
 * @specif: parameter
 * Return: 0
 */
int print_number_right_shift(char *str, p_type *specif)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (specif->zero_flag && !specif->minus_flag)
		pad_char = '0';
	neg = neg2 = (!specif->unsign && *str == '-');
	if (neg && i < specif->width && pad_char == '0' && !specif->minus_flag)
		str++;
	else
		neg = 0;
	if ((specif->plus_flag && !neg2) || (!specif->plus_flag &&
				specif->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (specif->plus_flag && !neg2 && pad_char == '0' && !specif->unsign)
		n += _putchar('+');
	else if (!specif->plus_flag && !specif->space_flag && !neg2 &&
			!specif->unsign && specif->zero_flag)
		n += _putchar(' ');
	while (i++ < specif->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (specif->plus_flag && !neg2 && !specif->unsign && pad_char == ' ')
		n += _putchar('+');
	else if (!specif->plus_flag && !neg2 && !specif->unsign
			&& !specif->zero_flag && specif->space_flag)
	{
		n += _putchar(' ');
		n += _input(str);
	}
	return (n);
}
/**
 * print_number_left_shift - left num
 * @str: string
 * @specif: parameter
 * Return: 0
 */
int print_number_left_shift(char *str, p_type *specif)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (specif->zero_flag && !specif->minus_flag)
	{
		pad_char = '0';
		neg = neg2 = (!specif->unsign && *str == '-');
	}
	if (neg && i < specif->width && pad_char == '0' && !specif->minus_flag)
		str++;
	else
	{
		neg = 0;
	}
	if (specif->plus_flag && !neg2 && !specif->unsign)
	{
		n += _putchar('+');
		i++;
	}
	else if (specif->plus_flag && !neg2 && !specif->unsign)
	{
		n += _putchar(' ');
		i++;
		n += _input(str);
	}
	while (i++ < specif->width)
	{
		n += _putchar(pad_char);
	}
	return (n);
}
