/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:11:18 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:45 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	if (*little == '\0')
		return ((char *)big);
	b = 0;
	while (big[b] && b < len)
	{
		l = 0;
		while (little[l] && (b + l) < len && big[b + l] == little[l])
		{
			l++;
		}
		if (little[l] == '\0')
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}
/* 
int	main(void)
{
	char big1[] = "PALALELEPIPEDO";
	char little1[] = "LELE";
	size_t len1 = 8;
	printf("%s\n", ft_strnstr(big1, little1, len1)); // Expected: LELEPIPEDO
	return (0);
} */
