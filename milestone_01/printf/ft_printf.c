/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:55:51 by jastolfi          #+#    #+#             */
/*   Updated: 2026/05/11 12:02:48 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		index;
	int		counter;

	if (!string)
		return (-1);
	va_start(args, string);
	index = 0;
	counter = 0;
	while (string[index])
	{
		if (string[index] == '%')
			counter += dispatcher(string[++index], &args);
		else
			counter += write_char(string[index]);
		index++;
	}
	va_end(args);
	return (counter);
}

int	dispatcher(char formatter, va_list *args)
{
	if (formatter == 'c')
		return (write_char(va_arg(*args, int)));
	if (formatter == 's')
		return (write_string(va_arg(*args, char *)));
	if (formatter == 'p')
		return (write_pointer(va_arg(*args, char *)));
	if (formatter == 'd' || formatter == 'i')
		return (write_integer(va_arg(*args, int)));
	if (formatter == 'u')
		return (write_unsigned_integer(va_arg(*args, unsigned int)));
	if (formatter == 'x' || formatter == 'X')
		return (write_hexadecimal(va_arg(*args, unsigned int), formatter));
	if (formatter == '%')
		return (write_char('%'));
	return (0);
}

int	write_pointer(void *pointer)
{
	int				counter;
	unsigned long	address;

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

/* # include <stdio.h>
# include <limits.h>

int main()
{
    int r1;
    int r2;

    // There's a 3 digit difference between the prints
	// because of ft_ before the printf name

    // %c
    r1 = printf("printf %%c: [%c]\n", 'A');
    r2 = ft_printf("ft_printf %%c: [%c]\n", 'A');
    printf("counts: %d vs %d\n", r1, r2);

    // %s
    r1 = printf("printf %%s: [%s]\n", "hello");
    r2 = ft_printf("ft_printf %%s: [%s]\n", "hello");
    printf("counts: %d vs %d\n", r1, r2);

    // %s NULL
	r1 = printf("printf %%s null: [%s]\n", (char *) NULL);
    r2 = ft_printf("ft_printf %%s null: [%s]\n", NULL);
    printf("counts: %d vs %d\n\n", r1, r2);

	r1 = printf(NULL);
    r2 = ft_printf(NULL);
    printf("counts: %d vs %d\n\n", r1, r2);

    // %d and %i
    r1 = printf("printf %%d: [%d]\n", 42);
    r2 = ft_printf("ft_printf %%d: [%d]\n", 42);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%d negative: [%d]\n", -42);
    r2 = ft_printf("ft_printf %%d negative: [%d]\n", -42);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%d INT_MAX: [%d]\n", INT_MAX);
    r2 = ft_printf("ft_printf %%d INT_MAX: [%d]\n", INT_MAX);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%d INT_MIN: [%d]\n", INT_MIN);
    r2 = ft_printf("ft_printf %%d INT_MIN: [%d]\n", INT_MIN);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%d zero: [%d]\n", 0);
    r2 = ft_printf("ft_printf %%d zero: [%d]\n", 0);
    printf("counts: %d vs %d\n\n", r1, r2);

    // %u
    r1 = printf("printf %%u: [%u]\n", 42u);
    r2 = ft_printf("ft_printf %%u: [%u]\n", 42u);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%u UINT_MAX: [%u]\n", UINT_MAX);
    r2 = ft_printf("ft_printf %%u UINT_MAX: [%u]\n", UINT_MAX);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%u zero: [%u]\n", 0u);
    r2 = ft_printf("ft_printf %%u zero: [%u]\n", 0u);
    printf("counts: %d vs %d\n\n", r1, r2);

    // %x and %X
    r1 = printf("printf %%x: [%x]\n", 255);
    r2 = ft_printf("ft_printf %%x: [%x]\n", 255);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%X: [%X]\n", 255);
    r2 = ft_printf("ft_printf %%X: [%X]\n", 255);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%x zero: [%x]\n", 0);
    r2 = ft_printf("ft_printf %%x zero: [%x]\n", 0);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%x UINT_MAX: [%x]\n", UINT_MAX);
    r2 = ft_printf("ft_printf %%x UINT_MAX: [%x]\n", UINT_MAX);
    printf("counts: %d vs %d\n\n", r1, r2);

    // %p
    int x = 42;
    r1 = printf("printf %%p: [%p]\n", &x);
    r2 = ft_printf("ft_printf %%p: [%p]\n", &x);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%p NULL: [%p]\n", NULL);
    r2 = ft_printf("ft_printf %%p NULL: [%p]\n", NULL);
    printf("counts: %d vs %d\n\n", r1, r2);

    // %%
    r1 = printf("printf %%%%: [%%]\n");
    r2 = ft_printf("ft_printf %%%%: [%%]\n");
    printf("counts: %d vs %d\n\n", r1, r2);

    // multiple args mixed
    r1 = printf("printf mixed: [%s %d %x %c]\n", "test", -1, 255, 'Z');
    r2 = ft_printf("ft_printf mixed: [%s %d %x %c]\n", "test", -1, 255, 'Z');
    printf("counts: %d vs %d\n\n", r1, r2);
    return (0);
} */
