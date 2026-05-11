/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:54:33 by jastolfi          #+#    #+#             */
/*   Updated: 2026/05/11 11:07:10 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	dispatcher(char c, va_list *args);
int	write_char(int c);
int	write_string(char *string);
int	write_integer(int number);
int	write_unsigned_integer(unsigned int number);
int	write_hexadecimal(unsigned int number, char letter);
int	write_pointer(void *pointer);

#endif