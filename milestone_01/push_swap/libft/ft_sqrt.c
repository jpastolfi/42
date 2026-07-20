/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:40:03 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/12 12:04:11 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int number)
{
	int	i;

	if (number < 0)
		return (0);
	if (number <= 1)
		return (number);
	i = 1;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}
