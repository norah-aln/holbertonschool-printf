#include "main.h"

/**
 * print_char - prints a character
 * @args: arguments list
 * Return: 1
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return (1);
}

/**
 * print_string - prints a string
 * @args: arguments list
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
 * print_percent - prints a percent sign
 * @args: arguments list
 * Return: 1
 */
int print_percent(va_list args)
{
    (void)args;
    _putchar('%');
    return (1);
}

/**
 * print_number - helper function to print numbers recursively
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_number(n / 10);

    _putchar((n % 10) + '0');
    count++;

    return (count);
}

/**
 * print_int - prints an integer (handles %d and %i)
 * @args: arguments list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        count++;
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    count += print_number(num);
    return (count);
}
