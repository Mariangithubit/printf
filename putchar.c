#include "main.h"
/**
 * _putchar - print the chars
 * @c: char
 * Return: 1, error -1
 */
int _putchar(int c)
{
	static int j;
	static char buffer[buf_size];

	if (c != buf_flush)
	{
		buffer[j++] = c;
	}
	if (j >= buf_size || c == buf_flush)
	{
		write(1, buffer, j);
		j = 0;
	}
	return (1);
}
/**
 * _input - input the string
 * @st: the string
 * Return: void
 */
int _input(char *st)
{
	char *i = st;

	while (*st)
		_putchar(*st++);
	return (st - i);
}
