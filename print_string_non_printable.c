#include "holberton.h"
#include <stdio.h>
/**
 * char_hexaa - return hexadecim of a number
 * @i: integer to transform in hexa
 * Return: nothing or value of hexa
 */
char char_hexaa(int i)
{
	char *hexa = "ABCDEF";
	int decimal[6] = {0, 1, 2, 3, 4, 5};
	int unite;
	int y = 0;

	unite = (i % 10);
	while (y < 7)
	{
		if (unite == decimal[y])
		{
			return (hexa[y]);
		}
		y++;
	}
	return ('\0');
}
/**
 * convert_hexa - convert number hexa
 * @i: integer to convert
 * Return: string of hexa number of i
 */
char *convert_hexa(int i)
{
	int y, res = 0;
	char *str;

	str = malloc(sizeof(char) * 3);
	if (str == NULL)
		return (NULL);
	y = 0;
	while (i > 0)
	{
		res = i % 16;
		if (res >= 10)
		{
			str[y] = char_hexaa(res);
		}
		else
		{
			str[y] = res + '0';
		}
		i = (i / 16);
		y++;
	}
	if (i < 16)
	{
		str[y] = '0';
	}
	return (str);
}
/**
 * fill_string - fill a string with hexa && string original that
 * ain't passed conditon to convert in hexa
 * @s: string given
 * @length: length of new string to allocate
 * Return: string filled with hexa
 */
char *fill_string(char *s, int length)
{
	int i, c, y, ct_counter, t = 0;
	char *ct;
	char *str_filled = "d";

	y = 0;
	str_filled = malloc(sizeof(char) * (length + 1));
	if (str_filled == NULL)
		return (NULL);
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 0 && s[i] <= 32) || (s[i] >= 127))
		{
			c = 1;
			ct_counter = 1;
			while (c < 3)
			{
				if (c == 1)
				{
					for (t = 0; t < 1; t++)
						str_filled[y] = '\\';
					y++;
					str_filled[y] = 'x';
					ct = convert_hexa(s[i]);
				}
				y++;
				str_filled[y] = ct[ct_counter];
				c++;
				ct_counter--;
			}
		}
		else
			str_filled[y] = s[i];
		y++;
	}
	str_filled[y] = '\0';
	if (ct != NULL)
		free(ct);
	return (str_filled);
}
/**
 * print_string_non_printable - main function to convert
 * @a: string given by _printf to convert
 * Return: number of char printed
 */
int print_string_non_printable(va_list a)
{
	char *s = va_arg(a, char *), *string_convert;
	int i, counter = 0;

	if (s == NULL)
		return (print_null());

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 0 && s[i] <= 32) || (s[i] >= 127))
		{
			counter += 3;
		}
		counter++;
	}
	string_convert = fill_string(s, counter);
	if (string_convert != NULL)
	{
		for (i = 0; string_convert[i] != '\0'; i++)
			_putchar(string_convert[i]);
		free(string_convert);
		return (counter);
	}
	return (0);
}
