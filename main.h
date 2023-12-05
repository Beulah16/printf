#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_format(char specifier, va_list ap);
int print_char(int c);
int print_string(char *str);
int print_digit(long n, int base);
int print_percent(void);
int print_binary(va_list val);

#endif
