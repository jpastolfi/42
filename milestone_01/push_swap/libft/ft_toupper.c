/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:42:58 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:26:00 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}
/* 
int	main(void)
{
	printf("%c\n",ft_toupper('d')); // Expected: D
	printf("%c\n",ft_toupper(';')); // Expected: ;
	printf("%c\n",ft_toupper(106)); // Expected: J
	return (0);
} */
