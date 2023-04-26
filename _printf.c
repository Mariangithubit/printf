#include "main.h"
void print_buffer(char buffer, int *buff_ind);
/**
 * _printf - print specifier
 * @format: a character string.
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
	int len = 0;
	char *c, *str;
	p_type *specif = INIT;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (c = (char *)format; *c; c++)
	{
		init_specif(&specif, args);
		if (*c != '%')
		{
			len += _putchar(*c);
			continue;
		}
		str = c;
		c++;
		while (get_flag(c, &specif))
		{
			c++;
		}
		c = get_width(c, &specif, args);
		c = get_precision(c, &specif, args);
		if (get_modifier(c, &specif))
		{
			c++;
		}
		if (!get_specifier(c))
		{
			len += p_strlen(str, c, specif.h_modifier || specif.l_modifier ? c - 1 : 0);
		}
		else
		{
			len += get_p_func(c, args, &specif);
		}
	}
	_putchar(flush);
	va_end(args);
	return (len);
}
