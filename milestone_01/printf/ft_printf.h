#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);
int dispatcher(char c, va_list *args);
int write_char(int c);
int write_string(char *string);
int write_integer(int number);
int write_unsigned_integer(unsigned int number);
int write_hexadecimal(unsigned int number, char letter);

#endif