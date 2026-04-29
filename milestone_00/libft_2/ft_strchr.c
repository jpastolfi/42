/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:34 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/24 18:44:51 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*p;

	index = 0;
	while (s[index])
	{
		if (s[index] == (unsigned char)c)
		{
			p = (char *)&s[index];
			return (p);
		}
		index++;
	}
	if (s[index] == (unsigned char)c)
	{
		p = (char *)&s[index];
		return (p);
	}
	return (NULL);
}

/* int main(void)
{
	char s[] = "Batata";
	char *ft = ft_strchr(s, 't');
	char *orig = strchr(s, 't');

	printf("ft_strchr:  offset=%td\n", ft ? ft - s : -1);
	printf("strchr:     offset=%td\n", orig ? orig - s : -1);
	printf("%s\n", ft == orig ? "OK" : "FAIL");
} */