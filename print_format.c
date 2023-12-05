#include <stdarg.h>
#include "main.h"

/**
 * print_format - a function that analyses argument types
 * for the _printf function
 * @specifier: character specifier
 * @ap: arguement pointer
 *
 * Return: number of characters printed
 */

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_string(va_arg(ap, char *));
	else if (specifier == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')		
		count += print_digit((long)va_arg(ap, unsigned int), 16);
	else
		count += write(1, &specifier, 1);
	return (count);
}
