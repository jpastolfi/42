/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:03:15 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:22:34 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n);

char	*ft_itoa(int n)
{
	char	*str_nb;
	size_t	len;
	long	nb;

	nb = n;
	len = count_digits(nb);
	str_nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_nb)
		return (NULL);
	if (nb == 0)
		str_nb[0] = '0';
	if (nb < 0)
	{
		str_nb[0] = '-';
		nb *= -1;
	}
	str_nb[len] = '\0';
	while (nb > 0)
	{
		str_nb[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str_nb);
}

static size_t	count_digits(int n)
{
	size_t	len;
	long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
/* 
int main(void)
{
	int		n1 = -2147483648;
	char	*str_nb1;

	str_nb1 = ft_itoa(n1);
	printf("%s\n", str_nb1);
	free(str_nb1);
	return (0);
} */
