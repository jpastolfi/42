/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:48:11 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:35 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex_long_fd(unsigned long n, int fd);

int	ft_putpointer_fd(unsigned long n, int fd)
{
	int	count;

	if (n == 0)
		return (write(fd, "(nil)", 5));
	count = write(fd, "0x", 2);
	count += ft_puthex_long_fd(n, fd);
	return (count);
}

static int	ft_puthex_long_fd(unsigned long n, int fd)
{
	unsigned long	nbr;
	int				count;

	nbr = n;
	count = 0;
	if (nbr > 15)
	{
		count += ft_puthex_long_fd(nbr / 16, fd);
	}
	count += write(fd, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}
/* 
int main(void)
{
	ft_putpointer_fd(12365, 1);
	printf("\n");
	ft_putpointer_fd(16, 1);
	printf("\n");
} */
