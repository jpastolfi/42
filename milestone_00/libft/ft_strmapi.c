/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:42:24 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/22 11:05:48 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*result;

	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}

/* char f(unsigned int n, char c)
{
	return c + n;
}

int main(void)
{
	printf("%s\n", ft_strmapi("abc", f)); // ace
	printf("%s\n", ft_strmapi("aaaaa", f)); // abcde
} */