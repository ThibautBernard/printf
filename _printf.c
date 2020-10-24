#include "holberton.h"
#include <stdio.h>

void print_char(va_list a)
{
	printf("X");
}

/**
 * _printf - main function printf according the format
 * @format: the string given
 * Return: the length:
 */
int _printf(const char *format, ...)
{
	int i, y, counter = 0;
	filt arr[] = {
			{"c", print_char},
			{"s", print_string},
			{NULL, NULL}
		};
	va_list args;
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		counter++;
		if (format[i] == '%' && format[i + 1] != '\0' && format[i + 1] != '%')
		{
			i++;
			for (y = 0; arr[y].identifier != NULL; y++)
			{
					if (format[i] == *arr[y].identifier)
					{;
						arr[y].ptr_f(args);
					}
			}
		}
		if (format[i + 1] != '\0')
		{
	    i++;
	    _putchar(format[i]);
		}
	}
	return (counter);
}
