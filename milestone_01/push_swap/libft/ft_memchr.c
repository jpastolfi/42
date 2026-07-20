/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:39:47 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:23:13 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (t[i] == (unsigned char)c)
			return ((void *)(t + i));
		i++;
	}
	return (NULL);
}
/* 
int	main(void)
{
    char str[] = "Find the X character";
    char *ptr;

    // Search for 'X' in the first 20 bytes
    ptr = ft_memchr(str, 'X', 20);
    if (ptr)
        printf("Found: %s\n", ptr); // Expected: "X character"
    
    // Search for 'Z' (does not exist)
    ptr = ft_memchr(str, 'Z', 20);
    if (ptr == NULL)
        printf("Character 'Z' not found as expected.\n"); // Expected: NULL

    return (0);
} */
