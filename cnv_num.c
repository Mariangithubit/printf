#include "main.h"
<<<<<<< HEAD
/**
 * print_hex - hex
 * @ap: argument
 * @params: parameter
 * Return: hex
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned  int)va_arg(ap, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_HEX - HEX
 * @ap: arguments
 * @params: parameter
 * Return:0
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
=======



int print_hex(va_list ap , params_t *params)
{
	unsigned long l ;
	int c = 0 ;
	char *str ;
        if (params->l_modifier)
                l = ( unsigned long)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                 l = ( unsigned short int)va_arg(ap, unsigned int);
        else
                 l = ( unsigned  int)va_arg(ap, unsigned int);
         str = convert(l , 16,CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
        if (params->hashtag_flag && l)
            {       
		    *--str= 'x';
                   *--str= '0' ;
	    }
        params->unsign = 1;
        return (c += print_number(str,params));
}
int print_HEX(va_list ap , params_t *params)
{
        unsigned long l;
        int c =0;
        char *str;
        if (params->l_modifier)
                l=( unsigned long)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                l=( unsigned short int)va_arg(ap, unsigned int);
        else
                l=( unsigned  int)va_arg(ap, unsigned int);
        str = convert(l , 16,CONVERT_UNSIGNED , params);
        if (params->hashtag_flag && l)
        {    
	      	*--str= 'X';
                *--str= 'O' ;
	}
        params->unsign = 1;
        return (c += print_number(str,params));
}
int print_binary(va_list ap , params_t *params)
{
	unsigned int n =va_arg(ap, unsigned int);
	char *str = convert(n,2,CONVERT_UNSIGNED ,params);
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = 'O';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - binary
 * @ap: argument
 * @params: parameters
 * Return: 0
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
<<<<<<< HEAD
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_octal - octal
 * @ap: argument
 * @params: parameter
 * Return: 0
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
	{
		l = (unsigned int)va_arg(ap, unsigned int);
		str = convert(l, 8, CONVERT_UNSIGNED, params);
	}
	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
=======
                *--str= '0';
	params->unsign = 1;
        return (c += print_number(str,params));
}
int print_octal(va_list ap , params_t *params)
{
        unsigned long l;
        int c =0;
        char *str;
        if (params->l_modifier)
                l=( unsigned long)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                l=( unsigned short int)va_arg(ap, unsigned int);
        else
                l=( unsigned  int)va_arg(ap, unsigned int);
        str = convert(l , 8,CONVERT_UNSIGNED , params);
        if (params->hashtag_flag && l)
		*--str= '0';
        params->unsign = 1;
        return (c += print_number(str,params));
>>>>>>> 66767f5c1cf9b4908604e5716109f69070d47095
}
