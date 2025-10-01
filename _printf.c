#include "main.h"

/**
 * print_char - prints a character
 * @args: arguments list
 *
 * Return: 1
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - prints a string
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * handle_specifier - handles format specifiers
 * @format: format character
 * @args: arguments list
 *
 * Return: number of characters printed
 */
int handle_specifier(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	else if (format == 's')
		return (print_string(args));
	else if (format == '%')
	{
		_putchar('%');
		return (1);
	}
	else
	{
		_putchar('%');
		_putchar(format);
		return (2);
	}
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			count += handle_specifier(format[i], args);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
