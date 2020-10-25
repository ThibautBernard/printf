#include "holberton.h"

/**
 * _strlen - count length of string
 * @s: string given
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
