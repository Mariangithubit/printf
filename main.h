#ifndef MAIN_H
#define MAIN_H
#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define NULL_string ("null")
#define INIT_sp {0,0,0,0,0,0,0,0,0,0}

/* _printf prototype */
int _printf(const char *format, ...);

/* specif.c prototype */
void init_specif(va_list args, p_type *specif);


int _chars(va_list args, p_type *specif);
int _string(va_list args, p_type *specif);
int _percent(va_list args, p_type *specif);
int _integer(va_list args, p_type *specif);
int (*get_specifier(char *s))(va_list args, p_type *specif);
int get_p_func(char *s, va_list args, p_type *specif);
int get_modifier(char *s, p_type *specif);
int get _width(char *s, va_list args, p_type *specif);
int get_flag(char *s, p_type *specif);
int _putchar(int c);
int _input(char *st);
char get_percision(char *s, va_list args, p_type *specif)
int p_strlen(char *begin, char *end, char *except)

/**
 * struct flag - structure of paramters
 * @unsign: unsigned value
 * @plus_f: positive value
 * @minus_f: negative value
 * @space_f: empty value
 * @hashtag_f: hashtah flag
 * @zero_f:no vlaue
 * @h_modifier: short
 * @l_modifier: long
 * @precision: percent sign
 * @width: the width
 */ 
typedef struct flag
{
	unsigned int unsign : 1;
	unsigned int plus_f : 1;
	unsigned int minus_f : 1;
	unsigned int space_f : 1;
	unsigned int hashtag_f : 1;
	unsigned int zero_f : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int precision
	unsigned int width
} p_type;
/**
 * struct specifier - specifier structure
 * @f: function
 * @specif: specifier format
 */
typedef struct specifier
{
	char *specif;
	int (*f)(va_list, p_type *);
} specifier_type;

#endif
