/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:55:27 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:19:48 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *) dest;
	src_ptr = (unsigned char *) src;
	if (dest_ptr < src_ptr)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			dest_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
	}
	return ((void *)dest_ptr);
}

/* int main(void)
{
	char src1[] = "Batata";
	char src2[] = "Batata";
	int i = 0;

	ft_memmove(src1 + 2, src1, 4);
	memmove(src2 + 2, src2, 4);
	while (i < 6)
	{
		printf("index %d: ft='%c' orig='%c' %s\n",
					 i, src1[i], src2[i], src1[i] == src2[i] ? "OK" : "FAIL");
		i++;
	}
} */
