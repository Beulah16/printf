#include "main.h"

/**
 * print_char - function that prints a character
 * @c: input character to be printed
 * Return: the number of characters
 */

int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - function that prints  string
 * @str: input string to be printed
 * Return: the number of characters
 */

int print_string(char *str)
{
	int counter = 0;

	while (*str != '\0')
	{
		print_char((int)*str);
		++counter;
		++str;
	}
	return (counter);
}

/**
 * print_digit - function that prints integers
 * @n: input integer to be printed
 * @base: input base of the integer
 * Return: the number of characters
 */

int print_digit(long n, int base)
{
	int counter;
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
		counter = print_digit(n / base, base);
		return (counter + print_digit(n % base, base));
	}
}

/**
 * print_percent - function that prints the percentage symbol
 * Return: 1
 */

int print_percent(void)
{
	print_char(37);
	return (1);
}
