#include "holberton.h"

/**
 * print_string - print a string given
 * @arg: the string given
 * Return: length of character printed
 */
int print_string(va_list arg)
{
	char *ptr = va_arg(arg, char *);
	int i, length_arg = 0;

	if (ptr != 0)
	{
		length_arg = _strlen(ptr);
		for (i = 0; ptr[i] != '\0'; i++)
		{
			_putchar(ptr[i]);
		}
	}
	return (length_arg);
}
