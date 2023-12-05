#include "main.h"

/**
 * print_char - prints a character
 * @c: character to be printed
 * Return: number of characters
 */

int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints  string
 * @str: string to be printed
 * Return: number of characters
 */

int print_string(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

/**
 * print_digit - print integers
 * @n: intger to be printed
 * @base: base of the integer
 * Return: number of characters
 */

int print_digit(long n, int base)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdef";

	if (n < 0)
	{
		print_char('-');
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		return (print_char(symbols[n]));
	}
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}
