#include <stdarg.h>
#include "main.h"
/**
 * _printf - a function that ehaves just like printf
 * @format: string format
 *
 * Return: numer of characters
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int count;

	va_start(ap, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
