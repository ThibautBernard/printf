#include "holberton.h"
#include <stdio.h>
/**
 * char_hexa_p - convert decimal to hexadecimal
 *
 * @n: the int to converted
 *
 * Return: character converted
 */
char char_hexa_p(unsigned long int n)
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
 * print_rev_array_hexa_p - print array from the end to
 * the start
 * @max_size_array: length of the array
 * @array: the array
 * Return: nothing
 */
int print_rev_array_hexa_p(unsigned long int max_size_array, char *array)
{
	unsigned long int i;

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
 * *fill_array_positive_hexa_p - fill array of 0 to 9, then A to F
 * only if the n is positive
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
char *fill_array_positive_hexa_p(char *array, unsigned long int n)
{
	unsigned long int i, res = 0;
	char hexa = '0';

	i = 0;
	if (array)
	{
		while (n > 0)
		{
			res = n % 16;
			if (res >= 10)
				hexa = char_hexa_p(res);
			else
				hexa = res + '0';
			array[i] = hexa;
			n = (n / 16);
			i++;
		}
		array[i++] = 'x';
		array[i++] = 0 + '0';
		array[i] = '\0';
	}
	return (array);
}
/**
 * fill_hexa_p - create array of size counter and malloc it
 * and call the function to fill the array and reverse
 * @nb: number to convert
 * @counter: size to allocate
 * Return: array mallocate
 */
char *fill_hexa_p(unsigned long int nb, unsigned long int counter)
{
	char *array;

	array = malloc(sizeof(char) * (counter + 1));
	if (array == NULL)
		return (NULL);
	print_rev_array_hexa_p((counter - 1), fill_array_positive_hexa_p(array, nb));
	return (array);
}
/**
 * print_pointeur - print adress of pointer
 *
 *@args: va_list
 *
 * Return: length of the hexadecimal converted
 */
int print_pointeur(va_list args)
{
	unsigned long int n = va_arg(args, unsigned long int), i = 0;
	unsigned long int counter = 0;
	char *remainder;
	char hexa = '0';

	if (n == 0)
	{
		counter = _print_nil();
		return (counter);
	}
	if (n < 10)
	{
		_putchar(n + '0');
		return (1);
	}
	else if (n >= 10 && n < 16)
	{
		hexa = char_hexa_p(n);
		_putchar(hexa);
		return (2);
	}
	while (_pow_recursion(16, i) <= n)
	{
		counter++;
		i++;
	}
	counter += 2;
	remainder = fill_hexa_p(n, counter);
	free(remainder);
	return (counter);
}
