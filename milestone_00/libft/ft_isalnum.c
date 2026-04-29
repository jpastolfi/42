/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:29:58 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:47:14 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	return (
		(c >= 48 && c <= 57) || // digit
		(c >= 65 && c <= 90) || // upper
		(c >= 97 && c <= 122) // lower
	);
}

/* int main(void)
{
	int i = 0;
	while (i <= 127)
	{
		printf("[%3d]: ft=%-3d orig=%-3d %s\n",
					 i, ft_isalnum(i), isalnum(i),
					 !!ft_isalnum(i) == !!isalnum(i) ? "OK" : "FAIL");
		i++;
	}
} */