/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:04:03 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:51 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!set)
		return (NULL);
	if (!s1 || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	while (s1[start])
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (end > 0)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}
// 19. Create two variables to find start and end of the trimmed string
// 22. Guard for NULL set
// 24. Guard for the NULL string or if the string is empty
// 25. then return also an empty memory allocated string
// 29. If current char on the main string ISN'T a charset then we found start
// 33. The end index of string is going to be length - 1 (indexation)
// 40. Return we use substr to allocate the new trimmed string
/* 
int	main(void)
{
	char	s1[] = "OLOLAelhaOLA";
	char	set[] = "OLA";
	char	*trimmed;
	
	trimmed = ft_strtrim(s1, set);
	printf("%s\n", trimmed); // Expected elha
	free(trimmed);
	return (0);
} */
