#include "holberton.h"
/**
 * *fill_array_positive_octal - fill array of 0 to 7
 * only if the n is positive
 * @array: the array to fill
 * @n: number
 * Return: the array filled
 */
char *fill_array_positive_octal(char *array, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (n > 0)
	{
		array[i] = (n % 8);
		n = (n / 8);
		i++;
	}
	array[i] = '\0';
	return (array);
}
/**
 * fill_octal - create array of size counter and malloc it
 * and call the function to fill the array and reverse
 * @nb: number to convert
 * @counter: size to allocate
 * Return: array mallocate
 */
char *fill_octal(unsigned int nb, unsigned int counter)
{
	char *array;

	array = malloc(sizeof(char) * (counter + 1));
	if (array == NULL)
		return (NULL);
	print_rev_array((counter - 1), fill_array_positive_octal(array, nb));
	return (array);
}


/**
 * print_octal - main function to convert decimal to
 * octal
 * @arg: the number to convert
 * Return: number of int printed
 */
int print_octal(va_list arg)
{
	unsigned int n = va_arg(arg, unsigned int), counter = 0;
	int i = 0;
	char *array;

	if (n < 8)
	{
		_putchar(n + '0');
		return (1);
	}
	while (_pow_recursion(8, i) <= n)
	{
		counter++;
		i++;
	}
	array = fill_octal(n, counter);
	free(array);
	return (counter);
}
