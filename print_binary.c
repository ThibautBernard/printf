#include "holberton.h"
/**
 * _pow_recursion - number pow
 * @x: number given
 * @y: power
 * Return: number
 */
unsigned long int _pow_recursion(unsigned long int x, unsigned long int y)
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
int print_rev_array(unsigned long int max_size_array, char *array)
{
	unsigned long int i;

	while (max_size_array)
	{
		_putchar(array[max_size_array] + '0');
		max_size_array--;
		i++;
	}
	i++;
	_putchar(array[max_size_array] + '0');
	return (i);
}
/**
 * *fill_array_positive - fill array of 0 or 1
 * only if the n is positive
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
char *fill_array_positive(char *array, unsigned long int n)
{
	unsigned long int i;

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
 * fill_binary - create array of size counter and malloc it
 * and call the function to fill the array and reverse
 * @nb: number to convert
 * @counter: size to allocate
 * Return: array mallocate
 */
char *fill_binary(unsigned long int nb, unsigned long int counter)
{
	char *array;

	array = malloc(sizeof(char) * (counter + 1));
	if (array == NULL)
		return (NULL);
	print_rev_array((counter - 1), fill_array_positive(array, nb));
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
	unsigned long int n = va_arg(arg, unsigned long int), counter = 0;
	int i = 0;
	char *array;

	if (n == 0)
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
		array = fill_binary(n, counter);
		free(array);
		return (counter);
	}
	return (0);
}
