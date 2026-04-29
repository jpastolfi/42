/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 12:49:16 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:46:10 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <bsd/string.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dst_len;
	size_t	src_len;

	index = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	while (src[index] && dst_len + index + 1 < size)
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = '\0';
	return (dst_len + src_len);
}

/* int main(void)
{
	// Compile with -lbsd because of bsd/string.h
	char   dst1[20] = "Hello";
	char   dst2[20] = "Hello";
	size_t r1;
	size_t r2;

	r1 = ft_strlcat(dst1, " World", 10);
	r2 = strlcat(dst2, " World", 10);
	printf("dst: ft='%s' orig='%s' %s\n",
		dst1, dst2, strcmp(dst1, dst2) == 0 ? "OK" : "FAIL");
	printf("ret: ft=%zu orig=%zu %s\n", r1, r2, r1 == r2 ? "OK" : "FAIL");
} */