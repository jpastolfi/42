/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-a <jcosta-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:42:55 by jastolfi          #+#    #+#             */
/*   Updated: 2026/06/13 17:42:33 by jcosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	is_valid_argc(int argc)
{
	if (argc == 1)
		exit(0);
}
// 17. Validation of the minimum number of argv;

static int	fill_data(t_array *data, int argc, char **argv, int start);

t_array	*validate_number(int argc, char **argv, int start, t_ops *count_op)
{
	t_array	*data;

	data = malloc(sizeof(t_array));
	if (!data)
		return (free(count_op), end(ERR_MALLOC), NULL);
	data->values = malloc(sizeof(int) * (argc - start));
	if (!data->values)
	{
		free(count_op);
		free(data);
		end(ERR_MALLOC);
	}
	if (fill_data(data, argc, argv, start) == -1)
	{
		free(count_op);
		free(data->values);
		free(data);
		end(ERR_NOT_VALID);
	}
	data->head = 0;
	return (data);
}
// 31. argc - i: we remove from the count - program and the flag

static int	fill_data(t_array *data, int argc, char **argv, int start)
{
	int	j;

	j = 0;
	while (start < argc)
	{
		if ((!(ft_isdigit(argv[start][0])
				|| (argv[start][0] == '-' && ft_isdigit(argv[start][1]))
				|| (argv[start][0] == '+' && ft_isdigit(argv[start][1])))))
		{
			return (-1);
		}
		if (ft_atol(argv[start]) < INT_MIN || ft_atol(argv[start]) > INT_MAX)
			return (-1);
		data->values[j] = ft_atol(argv[start]);
		start++;
		j++;
		data->size = j;
		data->capacity = data->size;
	}
	return (0);
}
// 56. First character of each argv cannot be different from sign or digit;
// 57. If there is a sign, also 2nd character from argv needs to be digit;
// 59. Validation if inside INT limits;
// 69. In an array of int on a struct we save the treated argv to values;

void	has_duplicates(t_array *data, t_ops *count_op)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->values[i] == data->values[j])
			{
				free(count_op);
				free(data->values);
				free(data);
				end(ERR_HAS_DUPLICATE);
			}
			j++;
		}
		i++;
	}
}
// 46. Loop to stop at the end of int array;
// 49. Loop to check with the neighbor;
// 52. If has duplicate, stops immediately
