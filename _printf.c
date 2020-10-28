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
	int i = 0, y, counter = 0, sum = 0, passed = 0;
	filt arr[] = {{"c", print_char}, {"s", print_string}, {"d", print_decimal},
{"i", print_decimal}, {"b", print_binary}, {"u", print_unsigned},
{"o", print_octal}, {"x", print_hexa}, {"X", print_hexaUpper},
{"R", print_rot13}, {"r", print_reverse}, {"S", print_string_non_printable},
{"p", print_pointeur}, {NULL, NULL}};
	va_list args;

	if (!(format) || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	va_start(args, format);
	for (; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			passed = 0;
			for (y = 0; arr[y].identifier != NULL; y++)
			{
				if (format[i] == *arr[y].identifier)
				{
					sum = arr[y].ptr_f(args);
					counter += sum;
					passed = 1;
				}
			}
			if (format[i] == '%' && format[i - 1] == '%')
				counter = _print_count(format[i], counter);
			else if (passed == 0 && format[i] != ' ')
			{
				_putchar('%');
				_putchar(format[i]);
				counter += 2;
			}
		}
		else
			counter = _print_count(format[i], counter);
	}
	va_end(args);
	return (counter);
}
