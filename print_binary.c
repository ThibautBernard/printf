#include "holberton.h"
/**
 * _pow_recursion - number pow
 * @x: number given
 * @y: power
 * Return: number
 */
int _pow_recursion(int x, int y)
{
	if (y > 0)
	{
		return (x * _pow_recursion(x,  y - 1));
	}
	else if (y < 0)
	{
		return (-1);
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
void print_rev_array(int max_size_array, int *array)
{
	while (max_size_array >= 0)
	{
		_putchar(array[max_size_array] + '0');
		max_size_array--;
	}
}
/**
 * *fill_array_positive - fill array of 0 or 1
 * only if the n is positive
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
int *fill_array_positive(int *array, int n)
{
	int i;

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
 * *fill_array_negative - convert number in binary &&
 * fill array of 0 or 1, only if the n is negative
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
int *fill_array_negative(int *array, int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		array[i] = (n % 2);
		n = (n / 2);
		i++;
	}
	array[i] = 1;
	array[i + 1] = '\0';
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
	int i, tmp = 0, counter = 0, n = va_arg(arg, int), *array;

	i = 0;
	tmp = n;
	if (n < 0)
		tmp = tmp * -1;
	while (_pow_recursion(2, i) <= tmp)
	{
		counter++;
		i++;
	}
	if (n < 0)
	{
		counter += 1;
		array = malloc(sizeof(int) * (counter + 1));
		print_rev_array((counter - 1), fill_array_negative(array, tmp));
	}
	else
	{
		array = malloc(sizeof(int) * (counter + 1));
		print_rev_array((counter - 1), fill_array_positive(array, n));
	}
	free(array);
	return ((counter - 1));
}
