/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:25:43 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 17:39:57 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*ptr;
	unsigned char	final;

	ptr = (unsigned char *) s;
	index = 0;
	final = (unsigned char) c;
	while (index < n)
	{
		ptr[index] = final;
		index++;
	}
	return (s);
}

/* int main(void)
{
	char buf1[10];
	char buf2[10];
	size_t i = 0;

	ft_memset(buf1, 65, sizeof(buf1));
	memset(buf2, 65, sizeof(buf2));
	while (i < 10)
	{
		printf("index %zu: ft='%c' orig='%c' %s\n",
					 i, buf1[i], buf2[i], buf1[i] == buf2[i] ? "OK" : "FAIL");
		i++;
	}
} */