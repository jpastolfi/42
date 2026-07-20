/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:13:18 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:14 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* 
char	rot_index(unsigned int index, char c);

int	main(void)
{
	char	s1[] = "AAAAAAAAA";
	char	*str1;

	str1 = ft_strmapi(s1, rot_index);
	printf("%s\n", str1); // Expected: ABCDEFGHI
	free(str1);
}

char	rot_index(unsigned int index, char c)
{
	return	(c + index);
} */
