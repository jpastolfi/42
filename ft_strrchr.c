/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:42:37 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/17 16:03:11 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
		{
			p = (char *) &s[len];
			return (p);
		}
		len--;
	}
	return (NULL);
}

/* int main(void)
{
	char  s[] = "ABCDEF";
	char  *ft = ft_strrchr(s, 'C');
	char  *orig = strrchr(s, 'C');

	printf("ft_strrchr: offset=%td\n", ft ? ft - s : -1);
	printf("strrchr:    offset=%td\n", orig ? orig - s : -1);
	printf("%s\n", ft == orig ? "OK" : "FAIL");
} */