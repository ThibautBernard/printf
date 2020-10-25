#include "holberton.h"
#include <stdio.h>
/**
 * _pow_recursion - number pow
 * @x: number given
 * @y: power
 * Return: number
 */
unsigned int _pow_recursion(unsigned int x, unsigned int y)
{
	if (y > 0)
	{
		return (x * _pow_recursion(x,  y - 1));
	}
	return (1);
}
/**
 * print_rev_array - print array from the end to
 * the start
 * @max_size_array: length of the array
 * @array: the array
 * Return: nothing
 */
void print_rev_array(unsigned int max_size_array, unsigned int *array)
{
	while (max_size_array)
	{
		_putchar(array[max_size_array] + '0');
		max_size_array--;
	}
	_putchar(array[max_size_array] + '0');
}
/**
 * *fill_array_positive - fill array of 0 or 1
 * only if the n is positive
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
unsigned int *fill_array_positive(unsigned int *array, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n > 0)
	{
		array[i] = (n % 2);
		n = (n / 2);
		i++;
	}
	array[i] = '\0';
	return (array);
}
/**
 * print_binary - main function to convert decimal to
 * binary
 * @arg: the number to convert
 * Return: number of int printed
 */
int print_binary(va_list arg)
{
	unsigned int i, counter = 0, *array, n = va_arg(arg, unsigned int);

	i = 0;
	if (n < 2)
	{
		_putchar(n + '0');
		return (1);
	}
	else if (n > 0)
	{
		while (_pow_recursion(2, i) <= n)
		{
			counter++;
			i++;
		}
		array = malloc(sizeof(unsigned int) * (counter + 1));
		print_rev_array((counter - 1), fill_array_positive(array, n));
		free(array);
		return (counter);
	}
	return (0);
}
