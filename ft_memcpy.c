/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:25:50 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 14:25:55 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t index;
	unsigned char *dest_ptr;
	unsigned char *src_ptr;

	if (!dest && !src)
		return (NULL);
	index = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (index < n)
	{
		dest_ptr[index] = src_ptr[index];
		index++;
	}
	return (dest);
}

/* int main(void)
{
	unsigned char dest1[10] = "Batata";
	unsigned char dest2[10] = "Batata";
	unsigned char src[10] = "Camelo";
	int           i = 0;

	ft_memcpy(dest1, src, 7);
	memcpy(dest2, src, 7);
	while (i < 7)
	{
		printf("index %d: ft='%c' orig='%c' %s\n",
			i, dest1[i], dest2[i], dest1[i] == dest2[i] ? "OK" : "FAIL");
		i++;
	}
} */