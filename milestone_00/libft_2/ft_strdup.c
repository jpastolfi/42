/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 11:56:38 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/20 12:56:21 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

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

/* int main(void)
{
	const char *src = "42 Lisboa";
	char       *ft_result = ft_strdup(src);
	char       *orig = strdup(src);

	printf("ft_strdup: %s\n", ft_result);
	printf("strdup:    %s\n", orig);
	printf("%s\n", strcmp(ft_result, orig) == 0 ? "OK" : "FAIL");
	free(ft_result);
	free(orig);
} */
