#include "main.h"
/**
 * print_rev - reverse num
 * @ap: args
 * @params: parameter
 * Return: reversed nums
 */
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
		{
			len++;
			str--;
		}
		for (; len > 0; len--; str--)
			sum += _putchar(*str);
	}
	return (sum);
}
/**
 * print_rot - rot 13
 * @ap: args
 * @params: parameter
 * Return: rot nums
 */
int print_rot(va_list ap, params_t *params)
{
	int i = 0;
	int index = 0;
	int count = 0;
	char arr[] = "ABCD abcd";
	char *a = va_arg(ap, char *);
	(void)params;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count + = _putchar(arr[index]);
		}
		else
		{
			count + = _putchar(a[i]);
			i++;
		}
	}
	return (count);
}
