/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 20:37:04 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:02 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/* 
int main(void)
{
    char    dst1[5];
    char    src1[] = "HELLO";
    size_t  result1;

    result1 = ft_strlcpy(dst1, src1, 5); 
    
    printf("Processed string: [%s]\n", dst1);
    printf("Source size (src): %zu\n", result1);
    printf("Given buffer (size): 5\n");
} */
