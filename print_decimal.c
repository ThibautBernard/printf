#include "holberton.h"

/**
 * print_decimal - prints decimal
 *
 * @args: va_list
 *
 * Return: counter, length of the decimal
 */
int print_decimal(va_list args)
{
	unsigned int number, power = 1;
	int n = va_arg(args, int), counter = 0;

	number = n;
	while (n / 10)
	{
		power = power * 10;
		n /= 10;
	}
	if (n < 0)
	{
		_putchar('-');
		counter++;
		number = number * -1;
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
