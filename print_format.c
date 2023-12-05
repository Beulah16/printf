#include <stdarg.h>
#include "main.h"

/**
 * print_format - a function that analyses argument types
 * for the _printf function
 * @specifier: input character specifier
 * @ap: input arguement pointer
 *
 * Return: the number of characters printed
 */

int print_format(char specifier, va_list ap)
{
	int counter = 0;

	if (specifier == 'c')
		counter += print_char(va_arg(ap, int));
	else if (specifier == 's')
		counter += print_string(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		counter += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		counter += print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		counter += print_percent();
	else if (specifier == 'b')
		counter += print_binary(ap);
	else
		counter += write(1, &specifier, 1);
	return (counter);
}
