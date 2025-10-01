#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list containing the character
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
	return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_int((va_list)&(num /= 10));

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * handle_format - handles format specifiers
 * @format: format character
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int handle_format(char format, va_list args)
{
	if (format == 'c')
		return (print_char(args));
	if (format == 's')
		return (print_string(args));
	if (format == '%')
		return (print_percent(args));
	if (format == 'd' || format == 'i')
		return (print_int(args));

	_putchar('%');
	_putchar(format);
	return (2);
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
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			i++;
			count += handle_format(format[i], args);
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

