/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:42:58 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:25:57 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}
/* 
int	main(void)
{
	printf("%c\n",ft_tolower('D')); // Expected: d
	printf("%c\n",ft_tolower(';')); // Expected: ;
	printf("%c\n",ft_tolower(74)); // Expected: j
	return (0);
} */
