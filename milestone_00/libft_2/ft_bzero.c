/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:17:19 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:06:09 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <strings.h>
#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t			index;
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	index = 0;
	while (index < len)
	{
		ptr[index] = 0;
		index++;
	}
}

/* int main(void)
{
	char buf1[10] = "Batatatata";
	char buf2[10] = "Batatatata";
	size_t i = 0;

	ft_bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	while (i < 10)
	{
		printf("index %zu: ft=%d orig=%d %s\n",
					 i, buf1[i], buf2[i], buf1[i] == buf2[i] ? "OK" : "FAIL");
		i++;
	}
} */