/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:24:55 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 17:43:09 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (c + 32);
	}
	return (c);
}

/* int main(void)
{
	int i = 0;
	while (i <= 127)
	{
		printf("[%3d]: ft=%-3d orig=%-3d %s\n",
					 i, ft_tolower(i), tolower(i),
					 ft_tolower(i) == tolower(i) ? "OK" : "FAIL");
		i++;
	}
} */