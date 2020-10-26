#include "holberton.h"
#include <stdio.h>
/**
 * char_hexaUpper - convert decimal to hexadecimal uppercase
 *
 * @n: the int to converted
 *
 * Return: character converted
 */
char char_hexaUpper(unsigned long int n)
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
 * *fill_array_positive_hexaUpper - fill array of 0 to 9, then A to F
 * only if the n is positive
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
char *fill_array_positive_hexaUpper(char *array, unsigned long int n)
{
	unsigned long int i, res = 0;
	char hexa = '0';

	i = 0;
	while (n > 0)
	{
		res = n % 16;
		if (res >= 10)
			hexa = char_hexaUpper(res);
		else
			hexa = res + '0';
		array[i] = hexa;
		n = (n / 16);
		i++;
	}
	array[i] = '\0';
	return (array);
}
/**
 * fill_hexaUpper - create array of size counter and malloc it
 * and call the function to fill the array and reverse
 * @nb: number to convert
 * @counter: size to allocate
 * Return: array mallocate
 */
char *fill_hexaUpper(unsigned long int nb, unsigned long int counter)
{
	char *array;

	array = malloc(sizeof(char) * (counter + 1));
	if (array == NULL)
		return (NULL);
	print_rev_array_hexa((counter - 1), fill_array_positive_hexaUpper(array, nb));
	return (array);
}
/**
 * print_hexaUpper - convert a decimal into a hexadecimal uppercase
 *
 *@args: va_list
 *
 * Return: length of the hexadecimal converted
 */
int print_hexaUpper(va_list args)
{
	unsigned long int n = va_arg(args, unsigned long int), i = 0;
	int counter = 0;
	char *remainder;
	char hexa = '0';

	if (n > 4294967295)
		n = 4294967295;
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
	remainder = fill_hexaUpper(n, counter);
	free(remainder);
	return (counter);
}
