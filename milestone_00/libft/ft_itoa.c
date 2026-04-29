/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:28:10 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/22 10:48:33 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int	count_digits(int number)
{
	int		counter;
	long	n;

	counter = (number < 0);
	n = (long)number;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	return (counter + 1);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digits;
	int		index;
	int		next;
	int		start;

	digits = count_digits(n);
	result = malloc(digits + 1);
	if (!result)
		return (NULL);
	index = (n < 0);
	if (index)
		result[0] = '-';
	start = digits - 1;
	while (index <= start)
	{
		next = n % 10;
		if (next < 0)
			next = -next;
		result[start--] = next + '0';
		n /= 10;
	}
	result[digits] = '\0';
	return (result);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(123));
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
} */
