#include "main.h"
/**
 * convert - convert num
 * @num: num
 * @base: base
 * @flag: flag
 * @specif: parameters
 * Return: printed str
 */
char *convert(long int num, int base, int flag, p_type *specif)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)specif;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	}
	while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * p_unsigned - unsigned
 * @args: arguments
 * @specif: parameter
 * Return: printed int
 */
int p_unsigned(va_list args, p_type *specif)
{
	unsigned long l;

	if (specif->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (specif->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	specif->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, specif), specif));
}
/**
 * p_address - address
 * @args: argument
 * @specif: parameters
 * Return: address
 */
int p_address(va_list args, p_type *specif)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *str;

	if (!n)
		return (_input("(nil)"));
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, specif);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, specif));
}
