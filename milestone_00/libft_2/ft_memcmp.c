/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:10:23 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/17 15:23:05 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			index;

	if (n == 0)
		return (0);
	s1_ptr = (unsigned char *) s1;
	s2_ptr = (unsigned char *) s2;
	index = 0;
	while (index < n)
	{
		if (s1_ptr[index] != s2_ptr[index])
		{
			return (s1_ptr[index] - s2_ptr[index]);
		}
		index++;
	}
	return (0);
}

/* int main(void)
{
	int ft;
	int orig;

	ft = ft_memcmp("Codigo", "Codiga", 6);
	orig = memcmp("Codigo", "Codiga", 6);
	printf("\"Codigo\" vs \"Codiga\": ft=%d orig=%d %s\n",
				 ft, orig, (ft > 0 && orig > 0) ? "OK" : "FAIL");
	ft = ft_memcmp("Equal", "Equal", 5);
	orig = memcmp("Equal", "Equal", 5);
	printf("\"Equal\" vs \"Equal\": ft=%d orig=%d %s\n",
				 ft, orig, ft == 0 && orig == 0 ? "OK" : "FAIL");
} */