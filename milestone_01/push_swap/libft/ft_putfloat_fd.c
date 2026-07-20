/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:36:32 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/09 18:32:10 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putfloat_fd(double num, int fd)
{
	int		count;
	long	int_part;
	long	dec_part;

	count = 0;
	if (num < 0)
	{
		count += ft_putchar_fd('-', fd);
		num = -num;
	}
	num += 0.005;
	int_part = (long)num;
	count += ft_putnbr_fd(int_part, fd);
	count += ft_putchar_fd('.', fd);
	dec_part = (long)((num - (double)int_part) * 100);
	if (dec_part < 10)
		count += ft_putchar_fd('0', fd);
	count += ft_putnbr_fd(dec_part, fd);
	return (count);
}
// 24. Prints minus sign and converts number to positive;
// 27. Adds rounding factor for two decimal places;
// 28. Extracts the whole integer part from the float;
// 29. Prints the integer part using library function;
// 30. Prints the required decimal point;
// 31. Isolates and scales the two decimal digits into an integer;
// 32. Adds leading zero if decimals are below ten;
// 34. Prints the final two decimal digits;
