#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdarg.h>

int write_char(int c)
{
    write(1, &c, 1);
    return (1);
}

int write_string(char *string)
{
    int index;

    if (!string)
        return(write_string("(null)"));

    index = 0;
    while (string[index])
    {
        write_char(string[index]);
        index++;
    }
    return (index);
}

int write_integer(int number)
{
    char c;
    int counter;

    if (number == INT_MIN)
        return (write_string("-2147483648"));
    counter = 0;
    if (number < 0)
    {
        write_char('-');
        number = -number;
        counter++;
    }
    if (number > 9)
        counter+= write_integer(number / 10);
    counter++;
    c = (number % 10) + '0';
    write_char(c);
    return (counter);
}

int write_unsigned_integer(unsigned int number)
{
    char c;
    int counter;

    counter = 0;
    if (number > 9)
        counter+= write_unsigned_integer(number / 10);
    counter++;
    c = (number % 10) + '0';
    write(1, &c, 1);
    return (counter);
}

int write_hexadecimal(unsigned int number, char letter)
{
    char c;
    char *set;
    int counter;

    counter = 0;
    set = "0123456789abcdef";
    if (letter == 'X')
        set = "0123456789ABCDEF";
    if (number >= 16)
        counter += write_hexadecimal(number / 16, letter);
    counter++;
    c = set[number % 16];                                                                                                                                                                                                           
    write_char(c);  
    return (counter);
}

int write_pointer(void *pointer)
{
    int counter;
    unsigned long address;

    if (!pointer)
        return (write_string("(nil)"));
    counter = 0;
    address = (unsigned long) pointer;
    if (address >= 16)
        counter += write_pointer((void *)(address / 16));
    else
        counter = write_string("0x");
    counter += write_char("0123456789abcdef"[address % 16]);
    return (counter);
}

int dispatcher(char formatter, va_list *args)
{
    if (formatter == 'c')
        return(write_char(va_arg(*args, int)));
    if (formatter == 's')
        return(write_string(va_arg(*args, char *)));
    if (formatter == 'p')
        return(write_pointer(va_arg(*args, char *)));
    if (formatter == 'd' || formatter == 'i')
        return(write_integer(va_arg(*args, int)));
    if (formatter == 'u')
        return(write_unsigned_integer(va_arg(*args, unsigned int)));
    if (formatter == 'x' || formatter == 'X')
        return(write_hexadecimal(va_arg(*args, unsigned int), formatter));
    if (formatter == '%')
        return (write_char('%'));
    return (0);
}