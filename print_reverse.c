#include "holberton.h"
/**
 * print_reverse - print string reverse
 * @a: argument
 * Return: number of char printed
 */
int print_reverse(va_list a)
{
	int y, i, length = 0;
	char *s, *str_fill;

	s = va_arg(a, char *);
	if (s == NULL)
		return (print_null());
	length = _strlen(s);
	str_fill = malloc(sizeof(char) * (length + 1));
	if (str_fill == NULL)
		exit(98);
	i = length;
	y = 0;
	for (; i >= 0; i--)
	{
		str_fill[y] = s[i];
		y++;
	}
	str_fill[y] = '\0';
	for (i = 0; i <= length; i++)
		_putchar(str_fill[i]);
	free(str_fill);
	return ((i - 1));
}
