/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:47:37 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:29 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/* 
int main(void)
{
	char	str1[6] = "LIXAAO";
	int		i;
	
	i = 0;
	while (str1[i])
	{
		printf("%c", str1[i]);
		i++;
	}
	printf("\n");
	ft_memset(str1, 'c', 6);
	i = 0;
	while (str1[i])
	{
		printf("%c", str1[i]);
		i++;
	}
	printf("\n");
	return (0);
} */
