#include "holberton.h"


/**
 * rev - malloc an array and fill
 * @s: the string
 * @length: length of the string
 * Return: string filled
 */
char *rev(char *s, int length)
{
	int i, y;
	char *str_fill;

	str_fill = malloc(sizeof(char) * (length + 1));
	if (str_fill == NULL)
		return (NULL);
	i = length - 1;
	y = 0;
	for (; i >= 0; i--)
	{
		str_fill[y] = s[i];
		y++;
	}
	str_fill[y] = '\0';
	return (str_fill);
}

/**
 * print_reverse - print string reverse
 * @a: argument
 * Return: number of char printed
 */
int print_reverse(va_list a)
{
	int  i, length = 0;
	char *s, *str_filled;

	s = va_arg(a, char *);
	if (s == NULL)
		return (print_null());
	length = _strlen(s);
	str_filled = rev(s, length);
	for (i = 0; i < length; i++)
		_putchar(str_filled[i]);
	free(str_filled);
	return ((i));
}
