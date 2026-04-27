/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:42:34 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/21 13:02:00 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	inner_index;

	if (little[0] == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	index = 0;
	inner_index = 0;
	while (big[index] && index < len)
	{
		if (big[index] == little[inner_index])
		{
			while (big[index + inner_index] == little[inner_index]
				&& index + inner_index < len)
			{
				inner_index++;
				if (little[inner_index] == 0)
					return ((char *)&big[index]);
			}
			inner_index = 0;
		}
		index++;
	}
	return (NULL);
}

/* int main(void)
{
	const char *hay = "aaabcabcd";
	char       *ft;
	char       *orig;

	ft = ft_strnstr("abcccccdef", "cd", 8);
	orig = strnstr("abcccccdef", "cd", 8);
	printf("\"cd\" in \"abcccccdef\" n=8: ft=%s orig=%s %s\n",
		ft ? ft : "(null)", orig ? orig : "(null)",
		ft == orig ? "OK" : "FAIL");
	ft = ft_strnstr(hay, "abc", 9);
	orig = strnstr(hay, "abc", 9);
	printf("\"abc\" in \"aaabcabcd\" n=9: ft=%s orig=%s %s\n",
		ft ? ft : "(null)", orig ? orig : "(null)",
		ft == orig ? "OK" : "FAIL");
} */
