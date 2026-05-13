/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:44:57 by jastolfi          #+#    #+#             */
/*   Updated: 2026/05/11 17:53:16 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*p;

	if (!s)
		return (NULL);
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

char	*ft_strdup(const char *s)
{
	int		index;
	char	*str;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	str = malloc(index + 1);
	if (str == 0)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = s[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	int		total_len;
	char	*result;
	char	*to_free;

	to_free = (char *)s1;
	if (!s1)
		s1 = "";
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
	free(to_free);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != 0)
	{
		counter++;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
