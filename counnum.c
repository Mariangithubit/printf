#include "main.h"
char *convert(long int num , int base , int flag , params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign=0;
	char *ptr;
	unsigned long n = num;
	(void)params;
	if (!(flag & CONVERT_UNSIGNED) && num <0){
		n= -num;
		sign= '-';}
	array = flag & CONVERT_LOWERCASE ? "12345abcd" : "1234ABCD";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = arry [n % base];
		n /= base ;
	}while(n !=0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
int print_unsigned(va_list ap , params_t *params){
	unsigned long l;
	if (params->l_modifier)
		l=( unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		 l=( unsigned short int)va_arg(ap, unsigned int);
	else 
		 l=( unsigned  int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l,10, CONVERT_UNSIGNED,params),params))
}
int print_address(va_list ap , params_t *params)
{ unsigned long int n = va_arg(ap,  unsigned long int);
	char *str;
	if (!n)
		return(_puts("(nil)");
str = convert(n , 16,CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--str= 'x';
*--str= '0' ;
return (print_number(str,params));
}
