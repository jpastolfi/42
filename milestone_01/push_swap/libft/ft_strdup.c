/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 23:03:58 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:51 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	d = (char *)malloc(sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
/* 
int main(void)
{
    char *str = "Leveling up at C!";
    char *dup;

    dup = ft_strdup(str);
    if (dup)
    {
        printf("Original: %s at %p\n", str, str);
        printf("Copy:     %s at %p\n", dup, dup);
        free(dup);
    }
    return (0);
} */
