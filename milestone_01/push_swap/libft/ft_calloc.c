/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:44:04 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:22:14 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 26. Checking for overflow of the size_t
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	arr = malloc(total_size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, total_size);
	return (arr);
}
/* 
int	main(void)
{
	int		*ptr;

	// Allocate memory for 3 integers
	ptr = (int *)ft_calloc(3, sizeof(int));
	
	if (!ptr)
		return (1);

	// Check if memory is zeroed
	printf("Values: {%d, %d, %d}\n", ptr[0], ptr[1], ptr[2]);

	free(ptr);
	return (0);
} */
