#include "main.h"
/**
 * get_specifier - format function
 * @s: the string
 * Return: the number of characters printed
 */
int (*get_specifier(char *s))(va_list args, p_type *specif)
{
	specifier_type func[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{"S", p_S},
		{"b", p_binary},
		{"o", p_octal},
		{"u", p_unsigned},
		{"p", p_address},
		{"x", p_hex},
		{"X", p_HEX},
		{"r", p_rev},
		{"R", p_rot13},
		{NULL, NULL}
	};
	int n = 0;

	while (func[n].specifier)
	{
		if (*s == func[n].specifer[0])
		{
			return (func[n].f);
		}
		n++;
	}
	return (NULL);
}
/**
 * get_p_func - print the function
 * @s: the string
 * @args: arguments
 * @specif: specifier
 * Return: the number of characters printed
 */
int get_p_func(char *s, va_list args, p_type *specif)
{
	int (*f)(va_list, p_type *) = get_specifier(s);

	if (f)
		return (f(args, specif));
	return (0);
}
/**
 * get_modifier - print the modifier
 * @s: string
 * @specif: specifier
 * Return: modifier
 */
int get_modifier(char *s, p_type *specif)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = specif->h_modifier = 1;
			break;
		case 'l':
			i = specif->l_modifier = 1;
			break;
	}
	return (i);
}
/**
 * get_width - print the width
 * @s: string
 * @args: argument
 * @specif: specifier
 * Return: pointer
 */
char *get_width(char *s, va_list args, p_type *specif)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(args, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i += i * 10 + (*s++ - '0');
	}
	specif->width = i;
	return (s);
}
/**
 * get_precision - get precision format
 * @s: string
 * @args: argumnet
 * @specif: specifier
 * Return: pointer
 */
char *get_precision(char *s, va_list args, p_type *specif)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(args, int);
		s++;
	}
	if (*s != '.')
	{
		return (s);
		s++;
	}
	else
	{
		while (_isdigit(*s))
		{
			i = i * 10 + (*s++ - '0');
		}
	}
	specif->precision = i;
	return (s);
}
/**
 * get_flag - flag parameter
 * @s: the string
 * @specif: specifier
 * Return: flag
 */
int get_flag(char *s, p_type *specif)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = specif->plus_f = 1;
			break;
		case '-':
			i = specif->minus_f = 1;
			break;
		case ' ':
			i = specif->space_f = 1;
			break;
		case '#':
			i = specif->hashtag_f = 1;
			break;
		case '0':
			i = specif->zero_f = 1;
			break;
	}
	return (i);
}
