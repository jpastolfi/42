/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:45:26 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/12 12:04:11 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *nptr)
{
	long	nb;
	int		sign;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
	{
		nptr++;
	}
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + (*nptr - '0');
		nptr++;
	}
	return ((nb * sign));
}
/* 
#include <stdio.h>
int	main(void)
{
	printf("Test 1: %d\n", ft_atol("42"));        // Expected: 42
	printf("Test 2: %d\n", ft_atol("-42"));       // Expected: -42
	printf("Test 3: %d\n", ft_atol("   +123"));   // Expected: 123
	printf("Test 4: %d\n", ft_atol("\t\n -56"));  // Expected: -56
	printf("Test 5: %d\n", ft_atol("123abc45"));  // Expected: 123
	printf("Test 6: %d\n", ft_atol("2147483647"));  // Expected: (INT_MAX)
	printf("Test 7: %d\n", ft_atol("-2147483648")); // Expected: (INT_MIN)
	printf("Test 8: %d\n\n", ft_atol("2147483648"));  // Expected: 0
	return (0);
} */
