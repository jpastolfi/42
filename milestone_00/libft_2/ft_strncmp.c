/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:49:15 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/17 16:13:53 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
	{
		return (0);
	}
	index = 0;
	while (s1[index] != '\0')
	{
		if (s1[index] == s2[index] && index < n - 1)
		{
			index++;
		}
		else
		{
			break ;
		}
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

/* int main(void)
{
	int ft;
	int orig;

	ft = ft_strncmp("First", "First", 5);
	orig = strncmp("First", "First", 5);
	printf("\"First\" vs \"First\" n=5: ft=%d orig=%d %s\n",
		ft, orig, ft == 0 && orig == 0 ? "OK" : "FAIL");
	ft = ft_strncmp("Fire", "Fi", 3);
	orig = strncmp("Fire", "Fi", 3);
	printf("\"Fire\" vs \"Fi\" n=3: ft=%d orig=%d %s\n",
		ft, orig, (ft > 0 && orig > 0) ? "OK" : "FAIL");
	ft = ft_strncmp("test", "test\x80", 4);
	orig = strncmp("test", "test\x80", 4);
	printf("\"test\" vs \"test\\x80\" n=4: ft=%d orig=%d %s\n",
		ft, orig, ft == 0 && orig == 0 ? "OK" : "FAIL");
} */