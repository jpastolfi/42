/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:10:53 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:54 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void	fprint(unsigned int index, char *s);

int	main(void)
{
	char	s1[] = "ABOBORA";
	ft_striteri(s1, fprint);
}

void	fprint(unsigned int index, char *s)
{
	(void)index;
	printf("%s\n", s);
} */
