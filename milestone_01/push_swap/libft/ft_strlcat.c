/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:45:11 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:00 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 27. If destin. buffer (size) mentioned is equal or less than current
// 	   destin. length then return size + src current length
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	j = d_len + i;
	while (src[i] && j < size - 1)
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (d_len + s_len);
}
/* 
int main(void)
{
	// ✘ Bad case: src = NULL, Expected (0)
	printf("✘ Bad case: return is %zu\n", ft_strlcat("oi", NULL, 4));
	// ✘ Bad case: dest(NULL) && size == 0, Expected s_len(2)
	printf("✘ Bad case: return is %zu\n", ft_strlcat(NULL, "oi", 0));
	// ✘ Bad case: dest(NULL) && size == 0, Expected s_len(3)
	printf("✘ Bad case: return is %zu\n", ft_strlcat(NULL, "OFF", 0));
	// ✘ Bad case: size <= d_len, Expected size + s_len(5)
	printf("✘ Bad case: return is %zu\n", ft_strlcat("oi", "ola", 2));
	// --- GOOD CASE ---
    char dest1[10] = "PU"; 
    char src1[] = "LA";
    size_t	r = ft_strlcat(dest1, src1, 10);
    printf("\n✔ Good case:\n");
    printf("  - Resultado da string: \"%s\"\n", dest1); // Expected: "PULA"
    printf("  - Valor de retorno: %zu\n", r); // Expected: 4

	return (0);
} */
