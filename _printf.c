#include "holberton.h"
#include <stdio.h>
/**
 * _print_count - print char and incremente the counter
 *
 * @i: int
 * @counter: int
 *
 * Return: int i
 */
int _print_count(char format, int counter)
{
	counter++;
	_putchar(format);
	return(counter);
}

/**
 * _printf - main function printf according the format
 * @format: the string given
 * Return: the length:
 */
int _printf(const char *format, ...)
{
	int i, y, counter = 0, sum = 0;
	filt arr[] = {{"c", print_char},{"s", print_string},{NULL, NULL}};
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			for (y = 0; arr[y].identifier != NULL; y++)
			{
					if (format[i] == *arr[y].identifier)
					{
						sum = arr[y].ptr_f(args);
						counter += sum;
						if (format[i + 1] != '\0')
						{	
							i++;
							if (format[i] != '%')
								counter = _print_count(format[i], counter);
						}
					}
			}
			if (format[i] == '%')
				counter = _print_count(format[i], counter);
		}
		else if (format[i] != '%' || format[i + 1] != '\0')
			counter = _print_count(format[i], counter);
	}
	return (counter);
}
