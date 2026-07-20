/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:41:47 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:48 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 26. Since the loop doesn't verify '\0' we add a new verification to 
//	   match the original funtion behaviour
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/* 
int	main(void)
{
	char	s1[] = "BOLA";
	int		c1 = 'O';
	char	s2[] = "BOLA";
	int		c2 = '\0';
	char	s3[] = "BOLA";
	int		c3 = 'D';
	printf("%s\n",ft_strchr(s1, c1)); // Expected: "OLA"
	printf("%s\n",ft_strchr(s2, c2)); // Expected: ""
	printf("%s\n",ft_strchr(s3, c3)); // Expected: (null)
	return (0);
} */
