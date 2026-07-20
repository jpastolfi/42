/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:53:00 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:17 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/* 
int main(void)
{
    printf("#1: %d\n", ft_memcmp("BOLA", "BOLO", 3));
	// Expected: 0
    printf("#2: %d\n", ft_memcmp("BOLA", "BOLO", 4));
	// Expected: Neg value (A - O)
    printf("#3: %d\n", ft_memcmp("BO", "BOLA", 4));
	// Expected: Negative value (\0 - L)
    printf("#4: %d\n", ft_memcmp("BOLA", "BOLO", 0));
	// Expected: 0
    printf("#5: %d\n", ft_memcmp("Z", "A", 1));
	// Expected: Positive value (Z - A)
    return (0);
} */
