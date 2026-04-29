/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:40:47 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/27 16:47:47 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != 0)
	{
		counter++;
	}
	return (counter);
}

/* int main(void)
{
	printf("ft_strlen: %zu\n", ft_strlen("Programa"));
	printf("strlen:    %zu\n", strlen("Programa"));
	printf("%s\n", ft_strlen("Programa") == strlen("Programa") ? "OK" : "FAIL");
} */