/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:26 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 18:09:09 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include "limits.h"

static void	putnbr(int number, int descriptor);

void	ft_putnbr_fd(int n, int fd)
{
	putnbr(n, fd);
}

static void	putnbr(int number, int descriptor)
{
	char	c;

	if (number == INT_MIN)
	{
		write(descriptor, "-2147483648", 11);
		return ;
	}
	if (number < 0)
	{
		write(descriptor, &"-", 1);
		number = -number;
	}
	if (number > 9)
	{
		putnbr(number / 10, descriptor);
		c = (number % 10) + '0';
		write(descriptor, &c, 1);
	}
	else
	{
		c = (number % 10) + '0';
		write(descriptor, &c, 1);
	}
}

/* int main(void)
{
	ft_putnbr_fd(INT_MAX, 1);
	write(1, &"\n", 1);
	ft_putnbr_fd(INT_MIN, 2);
} */