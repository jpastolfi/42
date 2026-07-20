/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:36:32 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/05/05 18:24:40 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	if (!s)
		return (write(fd, "(null)", 6));
	count = 0;
	i = 0;
	while (s[i])
	{
		count += write(fd, &s[i], 1);
		i++;
	}
	return (count);
}
/* 
int main(void)
{
	ft_putstr_fd("stdout\n", 1);
	ft_putstr_fd("stderr\n", 2);
} */
