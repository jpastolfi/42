/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:57:00 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 17:42:15 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <bsd/string.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size == 0)
		return (ft_strlen(src));
	index = 0;
	while (src[index] != '\0' && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}

/* int main(void)
{
	char dst1[10] = "Batata";
	char dst2[10] = "Batata";
	size_t r1;
	size_t r2;

	r1 = ft_strlcpy(dst1, "Tomate", 4);
	r2 = strlcpy(dst2, "Tomate", 4);
	printf("dst: ft='%s' orig='%s' %s\n",
				 dst1, dst2, strcmp(dst1, dst2) == 0 ? "OK" : "FAIL");
	printf("ret: ft=%zu orig=%zu %s\n", r1, r2, r1 == r2 ? "OK" : "FAIL");
} */