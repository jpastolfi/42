/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:29:58 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 17:39:15 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int ft_isalnum(int c)
{
	return (
			(c >= 48 && c <= 57) || // digit
			(c >= 65 && c <= 90) || // upper
			(c >= 97 && c <= 122)		// lower
	);
}

/* int main (void)
{
	int i = 0;
	while (i <= 127)
	{
		printf("Testing %c: %d\n", (char) i, ft_isalnum(i));
		i++;
	}
} */