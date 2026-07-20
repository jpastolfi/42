/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:48:11 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:20 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned int n, int fd)
{
	unsigned int	nbr;
	int				count;

	nbr = n;
	count = 0;
	if (nbr > 15)
	{
		count += ft_puthex_fd(nbr / 16, fd);
	}
	count += write(fd, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}
/* 
int main(void)
{
	ft_puthex_fd(123, 1);
	printf("\n");
	ft_puthex_fd(16, 2);
	printf("\n");
} */
