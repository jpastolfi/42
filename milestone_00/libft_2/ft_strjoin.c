/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:54 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/21 13:04:22 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		total_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		result[ft_strlen(s1) + index] = s2[index];
		index++;
	}
	result[total_len] = '\0';
	return (result);
}

/* int main(void)
{
	printf("%s\n", ft_strjoin("Berga", "mota"));
} */