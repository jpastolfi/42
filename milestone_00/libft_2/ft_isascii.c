/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:39:26 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:46:27 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

/* int main (void)
{
	int i = 0;
	while (i <= 127)
	{
		printf("[%3d]: ft=%-3d orig=%-3d %s\n",
			i, ft_isascii(i), isascii(i),
			!!ft_isascii(i) == !!isascii(i) ? "OK" : "FAIL");
		i++;
	}
} */