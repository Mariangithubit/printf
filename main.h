#ifndef MAIN_H
#define MAIN_H
#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define BUF_FLUSH -1
#define BUF_SIZE 1024
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define P_TYPE
#define PARAMS_T

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
char *convert(long int num, int base, int flag, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* sm_p.c */
int print_rev(va_list ap, params_t *params);
int print_rot(va_list ap, params_t *params);

/* cnv_num.c */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* p_num.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_lift_shift(char *str, params_t *params);

/* print_function.c */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/**
 * struct parameters - structure of paramters
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
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_f : 1;
	unsigned int minus_f : 1;
	unsigned int space_f : 1;
	unsigned int hashtag_f : 1;
	unsigned int zero_f : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int precision;
	unsigned int width;
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
