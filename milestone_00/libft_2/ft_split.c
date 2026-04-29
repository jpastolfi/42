/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:32 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/21 16:15:10 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	find_start(char const *s, char c, int start)
{
	while (s[start])
	{
		if (s[start] != c)
			return (start);
		start++;
	}
	return (start);
}

static int	find_end(char const *s, char c, int start)
{
	while (s[start])
	{
		if (s[start] == c)
			return (start);
		start++;
	}
	return (start);
}

static int	count_words(char const *s, char c)
{
	int	start;
	int	end;
	int	counter;

	start = 0;
	counter = 0;
	while (s[start])
	{
		start = find_start(s, c, start);
		end = find_end(s, c, start);
		if (!s[start])
			break ;
		else
			counter++;
		start = end++;
	}
	return (counter);
}

static char	**free_all(char **result, int counter)
{
	int	index;

	index = 0;
	while (index < counter)
	{
		free(result[index]);
		index++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		counter;
	int		start;
	int		end;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	counter = 0;
	start = 0;
	while (s[start])
	{
		start = find_start(s, c, start);
		end = find_end(s, c, start);
		if (!s[start])
			break ;
		result[counter] = ft_substr(s, start, end - start);
		if (!result[counter])
			return (free_all(result, counter));
		start = end;
		counter++;
	}
	result[counter] = NULL;
	return (result);
}
