#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
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
			i++;
			if (format[i] == '\0')
				break;

			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int j = 0;

				if (str == NULL)
					str = "(null)";

				while (str[j] != '\0')
				{
					_putchar(str[j]);
					count++;
					j++;
				}
			}
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
