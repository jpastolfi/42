/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:42:49 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/28 14:48:03 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	length;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	index = 0;
	length = ft_strlen(s1) - 1;
	while (s1[index])
	{
		if (!ft_strchr(set, s1[index]))
			break ;
		index++;
	}
	while (length > 0)
	{
		if (!ft_strchr(set, s1[length]))
			break ;
		length-- ;
	}
	return (ft_substr(s1, index, length - index + 1));
}

/* int main(void)
{
	printf("%s\n", ft_strtrim("aabaaa", "a"));
	printf("%s\n", ft_strtrim("         aabaaa    a       ", " "));
} */