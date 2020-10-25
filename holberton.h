#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdarg.h>

#include <stdlib.h>
int _printf(const char *format, ...);
/**
 * struct filter - structure with format && return
 * function of pointer
 * @identifier: format
 * @ptr_f: pointer of function
 */
typedef struct filter
{
	char *identifier;
	int (*ptr_f)(va_list);
} filt;

int _putchar(char c);
int _strlen(char *s);
int print_char(va_list);
int print_decimal(va_list);
int print_string(va_list arg);

int print_unsigned(va_list arg);

int print_octal(va_list arg);

int print_binary(va_list arg);

#endif
