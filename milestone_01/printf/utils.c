/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:58:21 by jastolfi          #+#    #+#             */
/*   Updated: 2026/05/11 11:44:45 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	write_string(char *string)
{
	int	index;

	if (!string)
		return (write_string("(null)"));
	index = 0;
	while (string[index])
	{
		write_char(string[index]);
		index++;
	}
	return (index);
}

int	write_integer(int number)
{
	char	c;
	int		counter;

	if (number == -2147483648)
		return (write_string("-2147483648"));
	counter = 0;
	if (number < 0)
	{
		write_char('-');
		number = -number;
		counter++;
	}
	if (number > 9)
		counter += write_integer(number / 10);
	counter++;
	c = (number % 10) + '0';
	write_char(c);
	return (counter);
}

int	write_unsigned_integer(unsigned int number)
{
	char	c;
	int		counter;

	counter = 0;
	if (number > 9)
		counter += write_unsigned_integer(number / 10);
	counter++;
	c = (number % 10) + '0';
	write(1, &c, 1);
	return (counter);
}

int	write_hexadecimal(unsigned int number, char letter)
{
	char	c;
	char	*set;
	int		counter;

	counter = 0;
	set = "0123456789abcdef";
	if (letter == 'X')
		set = "0123456789ABCDEF";
	if (number >= 16)
		counter += write_hexadecimal(number / 16, letter);
	counter++;
	c = set[number % 16];
	write_char(c);
	return (counter);
}
