/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:32:24 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:44:18 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int		index;
	long	total;
	int		signal;

	index = 0;
	total = 0;
	signal = 1;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || (nptr[index] == 32))
	{
		index++;
	}
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal = -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		total = (total * 10) + nptr[index] - '0';
		index++;
	}
	return ((int)(total * signal));
}

/* int main(void)
{
	const char *tests[] = {"+42lisboa", "42", "-0", "2147483647",
												 "-2147483648"};
	int i = 0;

	while (i < 5)
	{
		printf("atoi(\"%s\"): ft=%-12d orig=%-12d %s\n",
					 tests[i], ft_atoi(tests[i]), atoi(tests[i]),
					 ft_atoi(tests[i]) == atoi(tests[i]) ? "OK" : "DIFF");
		i++;
	}
} */