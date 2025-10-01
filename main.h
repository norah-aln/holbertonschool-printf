#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* main functions */
int _printf(const char *format, ...);
int _putchar(char c);

/* helper functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int handle_format(char format, va_list args);

#endif /* MAIN_H */
