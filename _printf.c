#include "main.h"

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
            
            switch (format[i])
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case '%':
                    count += print_percent(args);
                    break;
                case 'd':
                case 'i':
                    count += print_int(args);
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                    break;
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
