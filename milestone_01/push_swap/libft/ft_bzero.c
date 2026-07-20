/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:55:07 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:21:53 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/* 
int main(void)
{
	char	str1[6] = "LIXAAO";
	int		i;
	
	i = 0;
	while (i < 6)
	{
		printf("%c", str1[i]);
		i++;
	}
	printf("\n");
	ft_bzero(str1, 6);
	i = 0;
	while (i < 6)
	{
		printf("%c", str1[i]);
		i++;
	}
	printf("\n");
	return (0);
} */
