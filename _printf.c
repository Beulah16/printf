#include <stdarg.h>
#include "main.h"
/**
 * _printf - a function that behaves just like printf
 * @format: input string format
 *
 * Return: numer of characters
 */

int _printf(const char *format, ...)
{
	va_list list;
	int counter;

	va_start(list, format);
	counter = 0;

	while (*format != '\0')
	{
		if (*format == '%')
			counter += print_format(*(++format), list);
		else
			counter += write(1, format, 1);
		++format;
	}
	va_end(list);
	return (counter);
}
