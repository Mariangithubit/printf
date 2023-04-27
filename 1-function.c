#include "main.h"
/**
 * get_specifier - format function
 * @s: the string
 * Return: the number of characters printed
 */
int (*get_specifier(char *s))(va_list args, p_type * specif)
{
	specifier_type func[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_int},
		{"i", p_int},
		{"S", p_S},
		{"b", p_binary},
		{"o", p_octal},
		{"u", p_unsigned},
		{"p", p_address},
		{"x", p_hex},
		{"X", p_HEX},
		{"r", p_rev},
		{"R", p_rot},
		{NULL, NULL}
	};
	int n = 0;

	while (func[n].specifier)
	{
		if (*s == func[n].specifier[0])
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
