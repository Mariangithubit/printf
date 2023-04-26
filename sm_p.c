#include "main.h"
/**
 * p_rev - reverse num
 * @args: arguments
 * @specif: parameter
 * Return: sum
 */
int p_rev(va_list args, p_type *specif)
{
	int len, sum = 0;
	char *str = va_arg(args, char *);
	(void)specif;

	if (str)
	{
		for (len = 0; *str; str++)
		{
			len++;
			str--;
		}
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}
/**
 * p_rot - rot 13
 * @args: argument
 * @specif: parameter
 * Return: sum
 */
int p_rot(va_list args, p_type *specif)
{
	int i = 0;
	int index = 0;
	int count = 0;
	char arr[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ   abcdefghijklmnopqrstuvwxyz";
	char *a = va_arg(args, char *);
	(void)specif;

	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
		{
			count += _putchar(a[i]);
			i++;
		}
	}
	return (count);
}
