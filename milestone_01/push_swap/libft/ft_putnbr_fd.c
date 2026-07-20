/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:36:32 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:27 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		count += ft_putnbr_fd(nbr / 10, fd);
	}
	count += write(fd, &"0123456789"[nbr % 10], 1);
	return (count);
}
/* 
int main(void)
{
	ft_putnbr_fd(-123, 1);
	printf("\n");
	ft_putnbr_fd(2026, 2);
	printf("\n");
} */
