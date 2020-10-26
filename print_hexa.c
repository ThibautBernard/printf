#include "holberton.h"
#include <stdio.h>
/**
 * char_hexa - convert decimal to hexadecimal
 *
 * @n: the int to converted
 *
 * Return: character converted
 */
char char_hexa(unsigned int n)
{
	char *hexa = "abcdef";
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
 * print_rev_array_hexa - print array from the end to
 * the start
 * @max_size_array: length of the array
 * @array: the array
 * Return: nothing
 */
int print_rev_array_hexa(unsigned int max_size_array, char *array)
{
	int i;

	while (max_size_array)
	{
		_putchar(array[max_size_array]);
		max_size_array--;
		i++;
	}
	i++;
	_putchar(array[max_size_array]);
	return (i);
}
/**
 * print_hexa - convert a decimal into a hexadecimal
 *
 *@args: va_list
 *
 * Return: length of the hexadecimal converted
 */
int print_hexa(va_list args)
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
		hexa = char_hexa(n);
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
			hexa = char_hexa(res);
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
