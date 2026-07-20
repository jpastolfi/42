/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:15:34 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/09 20:48:52 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	if_print_fd(char c, va_list *args, int fd);

int	ft_printf_fd(const char *str, int fd, ...)
{
	va_list	args;
	int		i;
	int		total_print;

	if (!str)
		return (-1);
	va_start(args, fd);
	i = 0;
	total_print = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			total_print += if_print_fd(str[i], &args, fd);
		}
		else
			total_print += ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(args);
	return (total_print);
}

static int	if_print_fd(char c, va_list *args, int fd)
{
	int	total_print;

	total_print = 0;
	if (c == 'd' || c == 'i')
		total_print += ft_putnbr_fd(va_arg(*args, int), fd);
	else if (c == 'c')
		total_print += ft_putchar_fd(va_arg(*args, int), fd);
	else if (c == 's')
		total_print += ft_putstr_fd(va_arg(*args, char *), fd);
	else if (c == 'u')
		total_print += ft_putnbru_fd(va_arg(*args, unsigned int), fd);
	else if (c == 'x')
		total_print += ft_puthex_fd(va_arg(*args, unsigned int), fd);
	else if (c == 'X')
		total_print += ft_puthex_up_fd(va_arg(*args, unsigned int), fd);
	else if (c == 'p')
		total_print += ft_putpointer_fd(va_arg(*args, unsigned long), fd);
	else if (c == '%')
		total_print += ft_putchar_fd('%', fd);
	else if (c == 'f')
		total_print += ft_putfloat_fd(va_arg(*args, double), fd);
	return (total_print);
}
