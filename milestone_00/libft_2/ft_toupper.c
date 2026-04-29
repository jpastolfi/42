/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:04:28 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 17:43:16 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	return (c);
}

/* int main(void)
{
	int i = 0;
	while (i <= 127)
	{
		printf("[%3d]: ft=%-3d orig=%-3d %s\n",
					 i, ft_toupper(i), toupper(i),
					 ft_toupper(i) == toupper(i) ? "OK" : "FAIL");
		i++;
	}
} */