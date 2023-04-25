#include "main.h"
/**
 * p_strlen - string from to
 * @begin: the first address
 * @end: the last address
 * @except: except address
 * Return: len
 */
int p_strlen(char *begin, char *end, char *except)
{
	int len  = 0;

	while (begin <= end)
	{
		if (begin != except)
			len += _putchar(*begin);
		beign++;
	}
	return (len);
}
