#include "holberton.h"

void print_string(va_list arg)
{
	char *ptr = va_arg(arg, char *);
	int i;
	if (ptr != 0)
		for (i = 0; ptr[i] != '\0'; i++)
		{
			_putchar(ptr[i]);
		}
}
