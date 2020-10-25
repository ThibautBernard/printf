#include "holberton.h"
#include <stdio.h>
/**
 * print_unsigned - prints unsigned int
 *
 * @args: va_list
 *
 * Return: length of the unsigned int
 */

int print_unsigned(va_list args)
{
	unsigned int number = 0;
	unsigned int power = 1;
	unsigned int n = va_arg(args, unsigned int), counter = 0;

	if (n < 0)
	{
		number = 4294967296 + n;
	}
	else
		number = n;
	n = number;
	while (n / 10)
	{
		power = power * 10;
		n /= 10;
	}
	while (power >  0)
	{
		if (!(power == 1))
		{
			_putchar((number / power) + '0');
			counter++;
			number = number - (power * (number / power));
		}
		else
		{
			_putchar(number + '0');
			counter++;
		}
		power /= 10;
	}
	return (counter);
}
