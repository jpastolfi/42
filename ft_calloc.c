/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:26:51 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/17 18:09:44 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			index;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	ptr = (unsigned char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	index = 0;
	while (index < nmemb * size)
	{
		ptr[index] = 0;
		index++;
	}
	return ((void *)ptr);
}

/* int main(void)
{
	char *ft_ptr = (char *)ft_calloc(3, 4);
	char *orig = (char *)calloc(3, 4);
	int i = 0;

	while (i < 12)
	{
		printf("index %d: ft=%d orig=%d %s\n",
					 i, ft_ptr[i], orig[i], ft_ptr[i] == orig[i] ? "OK" : "FAIL");
		i++;
	}
	free(ft_ptr);
	free(orig);
} */