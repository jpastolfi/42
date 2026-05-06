#include "ft_printf.h"

int ft_printf(const char *string, ...)
{
    va_list args;
    va_start(args, string);
    int index;
    int counter;

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

#include <stdio.h>
#include <limits.h>

int main()
{
    int r1;
    int r2;

    /* There's a 3 digit difference between the prints because of ft_ before the printf name */

    // %c
    /* r1 = printf("printf %%c: [%c]\n", 'A');
    r2 = ft_printf("ft_printf %%c: [%c]\n", 'A');
    printf("counts: %d vs %d\n", r1, r2); */

    // %s
    /* r1 = printf("printf %%s: [%s]\n", "hello");
    r2 = ft_printf("ft_printf %%s: [%s]\n", "hello");
    printf("counts: %d vs %d\n", r1, r2); */

    // %s NULL
    /* r1 = printf("printf %%s null: [%s]\n", NULL);
    r2 = ft_printf("ft_printf %%s null: [%s]\n", NULL);
    printf("counts: %d vs %d\n\n", r1, r2); */

    // %d and %i
    /* r1 = printf("printf %%d: [%d]\n", 42);
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
    printf("counts: %d vs %d\n\n", r1, r2); */

    // %u
    /* r1 = printf("printf %%u: [%u]\n", 42u);
    r2 = ft_printf("ft_printf %%u: [%u]\n", 42u);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%u UINT_MAX: [%u]\n", UINT_MAX);
    r2 = ft_printf("ft_printf %%u UINT_MAX: [%u]\n", UINT_MAX);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%u zero: [%u]\n", 0u);
    r2 = ft_printf("ft_printf %%u zero: [%u]\n", 0u);
    printf("counts: %d vs %d\n\n", r1, r2); */

    // %x and %X
    /* r1 = printf("printf %%x: [%x]\n", 255);
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
    printf("counts: %d vs %d\n\n", r1, r2); */

    // %p
    /* int x = 42;
    r1 = printf("printf %%p: [%p]\n", &x);
    r2 = ft_printf("ft_printf %%p: [%p]\n", &x);
    printf("counts: %d vs %d\n\n", r1, r2);

    r1 = printf("printf %%p NULL: [%p]\n", NULL);
    r2 = ft_printf("ft_printf %%p NULL: [%p]\n", NULL);
    printf("counts: %d vs %d\n\n", r1, r2); */

    // %%
    /* r1 = printf("printf %%%%: [%%]\n");
    r2 = ft_printf("ft_printf %%%%: [%%]\n");
    printf("counts: %d vs %d\n\n", r1, r2); */

    // multiple args mixed
    /* r1 = printf("printf mixed: [%s %d %x %c]\n", "test", -1, 255, 'Z');
    r2 = ft_printf("ft_printf mixed: [%s %d %x %c]\n", "test", -1, 255, 'Z');
    printf("counts: %d vs %d\n\n", r1, r2); */
    return (0);
}