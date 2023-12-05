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

int print_digit(long n, int base, char specifier)
{
	int counter;
	char *symbols;
	char *capital_symbols;

	symbols = "0123456789abcdef";
	capital_symbols = "0123456789ABCDEF";

	if (n < 0)
	{
		print_char('-');
		return (print_digit(-n, base, specifier)+ 1);
	}
	else if (n < base)
	{
		if (specifier == 'X')
			return (print_char(capital_symbols[n]));
		else
			return (print_char(symbols[n]));
	}
	else
	{
		counter = print_digit(n / base, base, specifier);
		return (counter + print_digit(n % base, base, specifier));
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

/**
 * print_binary - function that prints a binary number
 * @val : input parameter
 * Return: the binary number in the form of integers
 */

int print_binary(va_list val)
{
	int counter = 0, flag = 0, i, j = 1, k;
	unsigned int value = va_arg(val, unsigned int);
	unsigned int m;

	for (i = 0; i < 32; i++)
	{
		m = ((j << (31 - i)) & value);
		if (m >> (31 - i))
			flag = 1;
		if (flag)
		{
			k = m >> (31 - i);
			print_char(k + 48);
			counter++;
		}
	}
	if (counter == 0)
	{
		counter++;
		print_char('0');
	}
	return (counter);
}
