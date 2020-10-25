#include "holberton.h"
/**
 * print_char - prints char
 *
 * @valist: va_list
 *
 * Return: 1: length of one character
 */
int print_char(va_list valist)
{
	char c;

	c = va_arg(valist, int);
	_putchar(c);
	return (1);
}
