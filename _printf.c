#include "holberton.h"
/**
 * _print_count - print char and incremente the counter
 * @format: the string to print and count
 * @counter: int
 * Return: length of the string printed
 */
int _print_count(char format, int counter)
{
	counter++;
	_putchar(format);
	return (counter);
}

/**
 * _printf - main function printf according the format
 * @format: the string given
 * Return: the length of all the characters printed
 */
int _printf(const char *format, ...)
{
	int i, y, counter = 0, sum = 0;
	filt arr[] = {{"c", print_char}, {"s", print_string}, {"d", print_decimal},
{"i", print_decimal}, {"b", print_binary}, {"u", print_unsigned},
{"o", print_octal}, {"x", print_hexa}, {"X", print_hexaUpper},
{"R", print_rot13}, {"r", print_reverse}, {"S", print_string_non_printable},
{NULL, NULL}};

	va_list args;

	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (y = 0; arr[y].identifier != NULL; y++)
			{
				if (format[i] == *arr[y].identifier)
				{
					sum = arr[y].ptr_f(args);
					counter += sum;
				}
			}
			if (format[i] == '%' && format[i - 1] == '%')
				counter = _print_count(format[i], counter);
		}
		else
			counter = _print_count(format[i], counter);
	}
	va_end(args);
	return (counter);
}
