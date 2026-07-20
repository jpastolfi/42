/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:15:34 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/09 20:48:06 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_print(char c, va_list *args);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		total_print;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	total_print = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			total_print += if_print(str[i], &args);
		}
		else
			total_print += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (total_print);
}

static int	if_print(char c, va_list *args)
{
	int	total_print;

	total_print = 0;
	if (c == 'd' || c == 'i')
		total_print += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (c == 'c')
		total_print += ft_putchar_fd(va_arg(*args, int), 1);
	else if (c == 's')
		total_print += ft_putstr_fd(va_arg(*args, char *), 1);
	else if (c == 'u')
		total_print += ft_putnbru_fd(va_arg(*args, unsigned int), 1);
	else if (c == 'x')
		total_print += ft_puthex_fd(va_arg(*args, unsigned int), 1);
	else if (c == 'X')
		total_print += ft_puthex_up_fd(va_arg(*args, unsigned int), 1);
	else if (c == 'p')
		total_print += ft_putpointer_fd(va_arg(*args, unsigned long), 1);
	else if (c == '%')
		total_print += ft_putchar_fd('%', 1);
	else if (c == 'f')
		total_print += ft_putfloat_fd(va_arg(*args, double), 1);
	return (total_print);
}
