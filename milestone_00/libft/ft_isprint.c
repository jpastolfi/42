/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:36:48 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 17:38:17 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}

/* int main(void)
{
	int i = 0;
	while (i <= 127)
	{
		printf("[%3d]: ft=%-3d orig=%-3d %s\n",
					 i, ft_isprint(i), isprint(i),
					 !!ft_isprint(i) == !!isprint(i) ? "OK" : "FAIL");
		i++;
	}
} */