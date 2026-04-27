/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:40:47 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/15 12:40:38 by jastolfi         ###   ########.fr       */
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
	printf("ft_strlen: %zu\n", ft_strlen("Programação"));
	printf("strlen:    %zu\n", strlen("Programação"));
	printf("%s\n", ft_strlen("Programação") == strlen("Programação") ? "OK" : "FAIL");
} */