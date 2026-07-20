/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:24:10 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:45 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*make_word(char const *s, char c);
static char		**freedom(char **arr, size_t j);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			arr[j] = make_word(&s[i], c);
			if (!arr[j])
				return (freedom(arr, j));
			i += ft_strlen(arr[j++]);
		}
	}
	arr[j] = NULL;
	return (arr);
}

static char	*make_word(char const *s, char c)
{
	size_t	i;
	char	*sub_arr;

	i = 0;
	while (s[i] && c != s[i])
		i++;
	sub_arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!sub_arr)
		return (NULL);
	i = 0;
	while (s[i] && c != s[i])
	{
		sub_arr[i] = s[i];
		i++;
	}
	sub_arr[i] = '\0';
	return (sub_arr);
}

static size_t	count_words(char const *s, char c)
{
	size_t	total;
	size_t	at_word;

	total = 0;
	at_word = 0;
	while (*s)
	{
		if (*s != c && at_word == 0)
		{
			total++;
			at_word = 1;
		}
		else if (*s == c)
			at_word = 0;
		s++;
	}
	return (total);
}

static char	**freedom(char **arr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
	}
	free(arr);
	return (NULL);
}
/* 
int	main(void)
{
	char	s1[] = {"KKKOlaKKKaKKKtodosKosKPresentes"};
	char	c1 = 'K';
	char	**arr1;
	int		i;
	
	arr1 = ft_split(s1, c1);
	if (!arr1)
		return (1);
	i = 0;
	while (arr1[i])
	{
		printf("%s\n", arr1[i]);
		free(arr1[i]);
		i++;
	}	
	free(arr1);
	return (0);
} */
