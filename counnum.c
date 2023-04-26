#include "main.h"
<<<<<<< HEAD
/**
 * convert - convert num
 * @num: num
 * @base: base
 * @flag: flag
 * @params: parameters
 * Return: printed num
 */
char *convert(long int num, int base, int flag, params_t *params)
=======

char *convert(long int num , int base , int flag , params_t *params)
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
<<<<<<< HEAD
	(void)params;

=======
        (void)params;
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flag & CONVERT_LOWERCASE ? "12345abcd" : "1234ABCD";
	ptr = &buffer[49];
	*ptr = '\0';
<<<<<<< HEAD
	do {
		*--ptr = arry[n % base];
		n == base;
	}
	while (n != 0)
=======
	do 
	{
	       *--ptr = arry [n % base];
        	n /= base ;
	}
	while(n != 0);
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
	if (sign)
		*--ptr = sign;
	return (ptr);
}
<<<<<<< HEAD
/**
 * print_unsigned - unsigned
 * @ap: argu
 * @params: parameter
 * Return: printed int
 */
int print_unsigned(va_list ap, params_t *params)
=======
int print_unsigned(va_list ap , params_t *params)
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
{
	unsigned long l;

	if (params->l_modifier)
<<<<<<< HEAD
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned  int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}
/**
 * print_address - address
 * @ap: args
 * @params: parameters
 * Return: address
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
=======
		l = ( unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
	        l = ( unsigned short int)va_arg(ap, unsigned int);
	else 
        	 l = ( unsigned  int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert( l , 10 , CONVERT_UNSIGNED,params) , params))
}
int print_address(va_list ap , params_t *params)
{
       	unsigned long int n = va_arg(ap,  unsigned long int);
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
	char *str;

	if (!n)
<<<<<<< HEAD
		return (_puts("(nil)"));
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
=======
		return(_puts("(nil)");
        str = convert(n , 16,CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
        *--str = 'x';
        *--str = '0' ;
        return (print_number(str,params));
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
}
