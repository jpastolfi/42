/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:54:11 by jcosta-a          #+#    #+#             */
/*   Updated: 2026/06/13 17:47:00 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	parse_all_flags(int argc, char **argv, t_flags *flag, t_ops *count_op)
{
	int	i;
	int	tmp;

	i = 1;
	flag->strategy = -1;
	count_op->bench = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		tmp = get_strategy_idx(&argv[i][2]);
		if (tmp != -1 && flag->strategy == -1)
			flag->strategy = tmp;
		else if (ft_strncmp(&argv[i][2], "bench", 6) == 0
			&& count_op->bench == 0)
			count_op->bench = 1;
		else
			return (free(count_op), end(ERR_INVALID_FLAG), 0);
		i++;
	}
	if (i == argc)
		return (free(count_op), end(ERR_ARG), 0);
	if (flag->strategy == -1)
		flag->strategy = 3;
	return (i);
}

int	get_strategy_idx(char *argv)
{
	char	*flags[5];
	int		i;

	flags[0] = "simple";
	flags[1] = "medium";
	flags[2] = "complex";
	flags[3] = "adaptive";
	flags[4] = NULL;
	i = -1;
	while (flags[++i])
	{
		if (ft_strncmp(argv, flags[i], ft_strlen(flags[i]) + 1) == 0)
			return (i);
	}
	return (-1);
}
