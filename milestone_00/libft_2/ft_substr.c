/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:42:52 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/21 13:02:31 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	size_t	index;
	size_t	s_len;
	char	*subs;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		s_len = s_len - start;
	else
		s_len = len;
	subs = (char *)malloc(s_len + 1);
	if (!subs)
		return (NULL);
	index = 0;
	while (s[start + index] && index < len)
	{
		subs[index] = s[start + index];
		index++;
	}
	subs[index] = '\0';
	return (subs);
}

/* int main(void)
{
	char * str = ft_strdup("1");
	printf("%s\n", ft_substr(str, 42, 42000000));
} */