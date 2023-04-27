#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define SPECIF_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define flush -1
#define buf_size 1024
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - params
 * @unsign: unsigned value
 * @plus_flag: positive value
 * @minus_flag: negative value
 * @space_flag: empty value
 * @hashtag_flag: hashtag flag
 * @zero_flag: no vlaue
 * @h_modifier: short
 * @l_modifier: long
 * @precision: percent sign
 * @width: the width
 */
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int precision;
	unsigned int width;
} p_type;

/**
 * struct specifier - specifier structure
 * @f: function
 * @specifier: specifier format
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, p_type *);
} specifier_type;

/* _printf prototype */
int _printf(const char *format, ...);

/* specif.c prototype */
void init_specif(va_list args, p_type *specif);

/* putchar.c prototype */
int _putchar(int c);
int _input(char *st);

/* function.c */
int get_p_func(char *s, va_list args, p_type *specif);
int get_modifier(char *s, p_type *specif);
char *get_width(char *s, va_list args, p_type *specif);
char *get_precision(char *s, va_list args, p_type *specif);
int get_flag(char *s, p_type *specif);

/* 1-function.c */
int (*get_specifier(char *s))(va_list args, p_type *specif);

/* strlen.c */
int p_strlen(char *begin, char *end, char *except);

/* counnum.c prototype */
char *convert(long int num, int base, int flag, p_type *specif);
int p_unsigned(va_list args, p_type *specif);
int p_address(va_list args, p_type *specif);

/* sm_p.c */
int p_rev(va_list args, p_type *specif);
int p_rot(va_list args, p_type *specif);

/* cnv_num.c */
int p_hex(va_list args, p_type *specif);
int p_HEX(va_list args, p_type *specif);
int p_binary(va_list args, p_type *specif);
int p_octal(va_list args, p_type *specif);

/* p_num.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, p_type *specif);
int print_number_right_shift(char *str, p_type *specif);
int print_number_left_shift(char *str, p_type *specif);

/* print_function.c */
int p_char(va_list args, p_type *specif);
int p_int(va_list args, p_type *specif);
int p_string(va_list args, p_type *specif);
int p_percent(va_list args, p_type *specif);
int p_S(va_list args, p_type *specif);

#endif
