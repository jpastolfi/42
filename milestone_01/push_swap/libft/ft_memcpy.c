/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:37:20 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:21 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/* 
int main(void)
{
	int	src[] = {10, 20, 30};
	int	dest[3] = {0};
	int	i = 0;

	ft_memcpy(dest, src, sizeof(int) * 3);
	// Now dest has {10, 20, 30}
	while (i < 3)
	{
		printf("%i\n", src[i]);
		i++;
	}
	return (0);
} */