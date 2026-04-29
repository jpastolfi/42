/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:41:29 by jastolfi          #+#    #+#             */
/*   Updated: 2026/04/22 11:42:16 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
}

/* int main(void)
{
	ft_putstr_fd("Batata", 1);	// prints to stdout
	ft_putstr_fd("\n", 1);	// prints to stdout
	ft_putstr_fd("Tomate", 2);	// prints to stderr
	ft_putstr_fd("\n", 2);	// prints to stdout
} */