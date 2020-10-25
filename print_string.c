#include "holberton.h"
/**
 * print_str - prints the string (null)
 *
 * Return: length of (null)
 */
int print_null(void)
{
	int i = 0;
	char *string = "(null)";

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
	return (6);
}

/**
 * print_string - print a string given
 * @arg: the string given
 * Return: length of character printed
 */
int print_string(va_list arg)
{
	char *ptr = va_arg(arg, char *);
	int i, length_arg = 0;
	int j = 0;

	if (ptr == NULL)
	{
		j = print_null();
		return (j);
	}
	else
	{
		length_arg = _strlen(ptr);
		for (i = 0; ptr[i] != '\0'; i++)
		{
			_putchar(ptr[i]);
		}
	}
	return (length_arg);
}
