/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:36:32 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:32 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbru_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbru_fd(n / 10, fd);
	}
	count += write(fd, &"0123456789"[n % 10], 1);
	return (count);
}
/* 
int main(void)
{
	ft_putnbru_fd(-1, 1); // Expected: 4294967295
	printf("\n");
	ft_putnbru_fd(2026, 2); // Expected: 2026
	printf("\n");
} */
