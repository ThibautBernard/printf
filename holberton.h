#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdarg.h>

int _printf(const char *format, ...);
typedef struct filter
{
	char *identifier;
	int (*ptr_f)(va_list);
} filt;

int _putchar(char c);
int _strlen(char *s);
int print_char(va_list);

int print_string(va_list arg);

#endif
