#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdarg.h>

int _printf(const char *format, ...);
typedef struct filter
{
	char *identifier;
	void (*ptr_f)(va_list);
} filt;

int _putchar(char c);
#endif
