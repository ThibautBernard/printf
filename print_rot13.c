#include "holberton.h"
/**
 * *rot13 - convert alphab *13
 * @s: string given to convert
 * Return: converted string
 */
char *rot13(char *s)
{
	int i, y, length = 0;
	char *letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *after = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *string_to_fill;

	length = _strlen(s);

	string_to_fill = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (s[i] != '\0')
	{
		y = 0;
		while (letter[y] != '\0')
		{
			if (letter[y] == s[i])
			{
				string_to_fill[i] = after[y];
				break;
			}
			y++;
		}
		i++;
	}
	string_to_fill[i] = '\0';
	return (string_to_fill);
}
/**
 * print_rot13 - print the formated string
 * @a: string given to format in rot13
 * Return: lenth of character printed
 */
int print_rot13(va_list a)
{
	char *s = va_arg(a, char *);
	char *str_formated;
	int i;

	if (s == NULL)
	{
		return (print_null());
	}
	str_formated = rot13(s);
	for (i = 0; str_formated[i] != '\0'; i++)
	{
		_putchar(str_formated[i]);
	}
	return (i);
}
