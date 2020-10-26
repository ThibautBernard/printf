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
	int power = 1;
	unsigned int number = va_arg(args, unsigned int);
	int counter = 0;
	unsigned int nb = 0;

	nb = number;
	while (nb / 10)
	{
		power = power * 10;
		nb /= 10;
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
