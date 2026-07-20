/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:49:22 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:26 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 29. If dest is after src copies in backwarded order
// 34. If not copies normally
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}
/* 
int	main(void)
{
	char	str1[] = "ABCDE";
	ft_memmove(str1 + 1, str1, 3); // Expected: "AABCE"
	printf("dest is after src from str1[1] = %s\n", str1);
	char	str2[] = "ABCDE";
	ft_memmove(str2, str2 + 2, 3); // Expected: "CDEDE"
	printf("dest is before src from str1[0] = %s\n", str2);
	return (0);
} */