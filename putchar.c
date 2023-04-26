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

	if (j >= buf_size || c == flush)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (c != flush)
		buffer[j++] = c;
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
