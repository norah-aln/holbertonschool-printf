#include "main.h"
/**
 * print_char - prints a character
 * @args: va_list containing the character
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return(1);
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
		_putchar(str[count] != '\0');
                count++;
	}

	return (count);
}

/**
 * print_percent - prints a percent sign
 * @args: va_list (unused)
 *
 * Return: number of characters printed (1)
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * handle_format - handles format specifiers
 * @format: format character
 * @args: va_list of arguments
 *
 * Return: number of characters printed, or 0 if unknown
 */
int handle_format(char format, va_list args)
{
	int i;
	struct format_spec {
		char specifier;
		int (*func)(va_list);
	} specs[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	for (i = 0; specs[i].specifier != '\0'; i++)
	{
		if (format == specs[i].specifier)
			return (specs[i].func(args));
	}

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
	int count = 0;
	int i = 0;
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
