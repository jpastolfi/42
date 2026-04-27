/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:51 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/22 11:30:21 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
	int	index;

	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

/* void f(unsigned int n, char *c)
{
	printf("String from index %d: %s\n", n, c);
}

int main(void)
{
	ft_striteri("Batata", f);
} */