/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:41:47 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:48 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 29. Since the loop doesn't verify '\0' we add a new verification to 
//	   match the original funtion behaviour
char	*ft_strrchr(const char *s, int c)
{
	char	*t;

	t = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			t = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (t);
}
/* 
int	main(void)
{
	char	s1[] = "BOLALLLA";
	int		c1 = 'L';
	char	s2[] = "BOLALLLA";
	int		c2 = '\0';
	char	s3[] = "BOLALLLA";
	int		c3 = 'D';
	printf("%s\n",ft_strrchr(s1, c1)); // Expected: "LA"
	printf("%s\n",ft_strrchr(s2, c2)); // Expected: ""
	printf("%s\n",ft_strrchr(s3, c3)); // Expected: (null)
	return (0);
} */
