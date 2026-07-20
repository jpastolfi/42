/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:10:20 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:30 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* 
int main(void)
{
    printf("#1: %d\n", ft_strncmp("BOLA", "BOLO", 3));
	// Expected: 0
    printf("#2: %d\n", ft_strncmp("BOLA", "BOLO", 4));
	// Expected: Neg value (A - O)
    printf("#3: %d\n", ft_strncmp("BO", "BOLA", 4));
	// Expected: Negative value (\0 - L)
    printf("#4: %d\n", ft_strncmp("BOLA", "BOLO", 0));
	// Expected: 0
    printf("#5: %d\n", ft_strncmp("Z", "A", 1));
	// Expected: Positive value (Z - A)
	signed char	str1[] = "test";
	signed char	str2[] = "test";
	str2[3] = -125;
	printf("#6: %d\n", ft_strncmp((const char *)str1, (const char *)str2, 4));
	printf("#7: %d\n", strncmp((const char *)str1, (const char *)str2, 4));
	// Expected: Negative value (Z - A)
    return (0);
} */
