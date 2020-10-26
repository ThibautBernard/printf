#include "holberton.h"
#include <stdio.h>
/**
 * char_hexaUpper - prints conversion decimal to hexadecimal
 *
 * @n: va_list
 *
 * Return: the caracter converted in hexadecimal
 */
char char_hexaUpper(unsigned int n)
{
	char *hexa = "ABCDEF";
	char *decimal = "012345";
	int unite = 0;
	int i = 0;

	unite = n % 10;
	for (i = 0; i < _strlen(hexa); i++)
	{
		if (unite == decimal[i] - '0')
			return (hexa[i]);
	}
	return ('\0');
}
/**
 * print_hexaUpper - converts decimal into hexadecimal Uppercase
 *
 * @args: va_list
 *
 * Return: the length of the hexadecimal
 */
int print_hexaUpper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int), i = 0, res = 0;
	int counter = 0;
	char *remainder;
	char hexa = '0';

	if (n < 10)
	{
		_putchar(n + '0');
		return (1);
	}
	else if (n >= 10 && n < 16)
	{
		hexa = char_hexaUpper(n);
		_putchar(hexa);
		return (2);
	}
	while (_pow_recursion(16, i) <= n)
	{
		counter++;
		i++;
	}
	remainder = malloc(sizeof(unsigned int) * (counter + 1));
	i = 0;
	while (n > 0)
	{
		res = n % 16;
		if (res >= 10)
			hexa = char_hexaUpper(res);
		else
			hexa = res + '0';
		remainder[i] = hexa;
		n = (n / 16);
		i++;
	}
	remainder[i] = '\0';
	print_rev_array_hexa((counter - 1), remainder);
	free(remainder);
	return (counter);
}
